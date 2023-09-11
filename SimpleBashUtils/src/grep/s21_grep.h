#ifndef S21_GREP_H
#define S21_GREP_H

#define MAX_LINE_LENGTH 1024
#define MAX_SIZE_OF_ARRAY 50
#define MAX_STR_LEN 200
#define MAX_MATCHES 100

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;

  char f_filename[MAX_LINE_LENGTH];
  char str_to_comp[MAX_LINE_LENGTH];

  int n_regex;
  int n_files;
  int cflags;
  int is_stdin;

} Grep_params;

void grep(int argc, char *argv[]);
void grep_file(FILE *file, char *filename, Grep_params params);
Grep_params params_parser(int argc, char *argv[]);
Grep_params find_templates(Grep_params params);
Grep_params add_regex(char *regex, Grep_params params);
Grep_params init_arrs(Grep_params params);
void free_arrs(Grep_params params);
void arg_failure();
#endif
