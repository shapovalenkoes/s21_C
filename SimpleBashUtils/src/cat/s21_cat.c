#include "s21_cat.h"

int main(int argc, char *argv[]) {
  cat(argc, argv);
  return 0;
}

void cat(int argc, char *argv[]) {
  Flags flags = flags_parser(argc, argv);
  int line_number = 1;
  int last = '\n';
  int prelast = 0;

  if (flags.is_stdin)
    cat_file(stdin, flags, &line_number, &last, &prelast);
  else {
    for (int i = optind; i < argc; i++) {
      FILE *file = fopen(argv[i], "r");
      if (file == NULL) {
        fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
      } else {
        cat_file(file, flags, &line_number, &last, &prelast);
        fclose(file);
      }
    }
  }
}

void cat_file(FILE *file, Flags flags, int *line_number, int *last,
              int *prelast) {
  int c;
  if (flags.b) flags.n = 0;

  while ((c = fgetc(file)) != EOF) {
    if (*last == '\n' && *prelast == '\n' && c == '\n' && flags.s) continue;
    if (*last == '\n' && flags.b && c != '\n') {
      printf("%6d\t", *line_number);
      *line_number = *line_number + 1;
    } else if (*last == '\n' && flags.n) {
      printf("%6d\t", *line_number);
      *line_number = *line_number + 1;
    }
    if (c == '\n' && flags.e) printf("$");
    if (c == 9 && flags.t) {
      printf("^I");
      swap(c, last, prelast);
      continue;
    }
    if (flags.v && (c < 32) && c != '\t' && c != '\n') {
      printf("^%c", c + 64);
      swap(c, last, prelast);
      continue;
    }
    if (flags.v && c == 127) {
      printf("^%c", c - 64);
      swap(c, last, prelast);
      continue;
    }
    printf("%c", c);
    swap(c, last, prelast);
  }
}

Flags flags_parser(int argc, char *argv[]) {
  int flag = 0;
  Flags flags = {0, 0, 0, 0, 0, 0, 0};

  static struct option long_options[] = {
      {"number-nonblank", no_argument, 0, 'b'},
      {"number", no_argument, 0, 'n'},
      {"squeeze-blank", no_argument, 0, 's'},
      {0, 0, 0, 0}};

  while ((flag = getopt_long(argc, argv, "benstvET", long_options, NULL)) !=
         -1) {
    switch (flag) {
      case 'b':
        flags.b = 1;
        break;
      case 'e':
        flags.v = 1;
        flags.e = 1;
        break;
      case 'E':
        flags.e = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 't':
        flags.v = 1;
        flags.t = 1;
        break;
      case 'T':
        flags.t = 1;
        break;
      case 'v':
        flags.v = 1;
        break;
      case '?':
        exit(EXIT_FAILURE);
    }
  }
  if (!(argc - optind)) flags.is_stdin = 1;
  return flags;
}

void swap(int c, int *last, int *prelast) {
  *prelast = *last;
  *last = c;
}