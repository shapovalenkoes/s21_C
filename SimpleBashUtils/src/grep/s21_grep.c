#include "s21_grep.h"

int main(int argc, char *argv[]) {
  grep(argc, argv);
  return 0;
}

void grep(int argc, char *argv[]) {
  if (argc < 2) arg_failure();
  Grep_params params = params_parser(argc, argv);
  if (params.is_stdin)
    grep_file(stdin, "(standard input)", params);
  else {
    for (int i = optind; i < argc; i++) {
      char *filename = argv[i];
      FILE *file = fopen(filename, "r");
      if (file == NULL) {
        if (!params.s)
          fprintf(stderr, "grep: %s: No such file or directory\n", filename);
      } else {
        grep_file(file, filename, params);
        fclose(file);
      }
    }
  }
}

void grep_file(FILE *file, char *filename, Grep_params params) {
  char line[MAX_LINE_LENGTH];
  regmatch_t matches[MAX_MATCHES];
  regex_t regex;
  int counter = 0;
  int line_number = 0;
  if (regcomp(&regex, params.str_to_comp, params.cflags) != 0) {
    fprintf(stderr, "grep: Trailing backslash\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(line, MAX_LINE_LENGTH, file)) {
    line_number++;
    int rx = regexec(&regex, line, MAX_MATCHES, matches, 0);
    if (params.v) rx = !rx;  //-v
    if (!rx) {
      counter++;
      if (params.l) {  //-l
        printf("%s\n", filename);
        break;
      }
      if (params.c) continue;
      if (!params.o) {
        if ((params.n_files > 1) && !params.h) printf("%s:", filename);  //-h
        if (params.n) printf("%d:", line_number);                        // -n
        printf("%s", line);  // -e - i
        if (line[strlen(line) - 1] != '\n') printf("\n");
      } else {
        while (!regexec(&regex, line, MAX_MATCHES, matches, 0)) {
          int start, end;
          if ((params.n_files > 1) && !params.h) printf("%s:", filename);
          if (params.n) printf("%d:", line_number);
          char *new_str = strdup(line + matches[0].rm_eo);
          start = matches[0].rm_so;
          end = matches[0].rm_eo;
          printf("%.*s\n", end - start, line + start);
          strcpy(line, new_str);
          free(new_str);
        }
      }
    }
  }
  if (params.c && !params.l) {
    if (params.n_files < 2 || params.h)
      printf("%d\n", counter);  // -c
    else
      printf("%s:%d\n", filename, counter);
  }
  regfree(&regex);
}

Grep_params find_regex(Grep_params params) {
  FILE *file = fopen(params.f_filename, "r");
  if (file == NULL) {
    fprintf(stderr, "grep: %s: No such file or directory\n", params.f_filename);
    exit(2);
  } else {
    char word[MAX_LINE_LENGTH];
    while (fscanf(file, "%1023s", word) == 1) {
      params = add_regex(word, params);
    }
    fclose(file);
  }
  return params;
}

Grep_params add_regex(char *regex, Grep_params params) {
  char *c = "|\0";
  strcat(params.str_to_comp, regex);
  strcat(params.str_to_comp, c);
  return params;
}

Grep_params params_parser(int argc, char *argv[]) {
  int flag = 0;
  Grep_params params = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", "", 0, 0, 0, 0};
  while ((flag = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1) {
    switch (flag) {
      case 'e':
        params.e = 1;
        params = add_regex(optarg, params);
        break;
      case 'i':
        params.i = 1;
        params.cflags |= REG_ICASE;
        break;
      case 'v':
        params.v = 1;
        break;
      case 'c':
        params.c = 1;
        break;
      case 'l':
        params.l = 1;
        break;
      case 'n':
        params.n = 1;
        break;
      case 'h':
        params.h = 1;
        break;
      case 's':
        params.s = 1;
        break;
      case 'f':
        params.f = 1;
        strcpy(params.f_filename, optarg);
        params = find_regex(params);
        break;
      case 'o':
        params.o = 1;
        break;
      case '?':
        arg_failure();
    }
  }
  if (params.o && params.v && !params.c && !params.l) exit(EXIT_SUCCESS);
  if (!params.e && !params.f) {
    params = add_regex(argv[optind], params);
    optind++;
  }
  params.cflags |= REG_EXTENDED;
  params.cflags |= REG_NEWLINE;
  params.n_files = argc - optind;
  if (params.n_files == 0) params.is_stdin = 1;
  params.str_to_comp[strlen(params.str_to_comp) - 1] = 0;
  return params;
}

void arg_failure() {
  fprintf(stderr, "Usage: grep [OPTION]... PATTERNS [FILE]...\n");
  fprintf(stderr, "Try 'grep --help' for more information.\n");
  exit(2);
}