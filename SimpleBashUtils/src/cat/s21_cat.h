#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int is_stdin;
} Flags;

Flags flags_parser(int argc, char *argv[]);
void swap(int c, int *last, int *prelast);
void cat(int argc, char *argv[]);
void cat_file(FILE *file, Flags flags, int *line_number, int *last,
              int *prelast);

#endif
