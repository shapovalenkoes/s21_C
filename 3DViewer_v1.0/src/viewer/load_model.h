#ifndef LOAD_MODEL_H
#define LOAD_MODEL_H

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

enum Status { kSuccess, kFailure };

typedef struct data_t {
  size_t vertices_n;
  size_t facets_n;
  size_t edges_n;
  double v_max;
  double *vertices;
  int *facets;
} obj_data;

int LoadModel(const char *filename, obj_data *data);
void ClearData(obj_data *data);
void CountVerticesAndFacets(FILE *f, obj_data *data);
int MemoryAlloc(obj_data *data);
void ParseFile(FILE *f, obj_data *data);

#endif  // LOAD_MODEL_H
