#include "load_model.h"

#include <math.h>
#include <string.h>

/**
 * @brief Parse data about vertex and facets from .obj file
 *
 * @param filename name of .obj file
 * @param data pointer to obj_data struct
 * @return int status. 0 - kSuccsess, 1 - kFailure
 */
int LoadModel(const char *filename, obj_data *data) {
  ClearData(data);
  int status = kFailure;

  FILE *f = fopen(filename, "r");
  if (f != NULL) {
    CountVerticesAndFacets(f, data);
    status = MemoryAlloc(data);
    if (status != kFailure) {
      fseek(f, 0, SEEK_SET);
      ParseFile(f, data);
    }
    fclose(f);
  }
  return status;
}

/**
 * @brief Free vertex and facets array
 *
 * @param data obj_data struct
 */
void ClearData(obj_data *data) {
  data->facets_n = 0;
  data->vertices_n = 0;
  data->edges_n = 0;
  data->v_max = 0;

  if (data->facets != NULL) {
    free(data->facets);
    data->facets = NULL;
  }
  if (data->vertices != NULL) {
    free(data->vertices);
    data->vertices = NULL;
  }
}

/**
 * @param f file stream
 *
 * @param data obj_data struct
 */
void CountVerticesAndFacets(FILE *f, obj_data *data) {
  char line[256];
  // size_t len = 0;

  while (fgets(line, 256, f)) {
    if (!strncmp(line, "v ", 2)) {
      data->vertices_n++;
    } else if (!strncmp(line, "f ", 2)) {
      data->facets_n++;
      char *istr = strtok(line + 2, " ");
      while (istr != NULL) {
        data->edges_n++;
        istr = strtok(NULL, " ");
      }
    }
  }
}

/**
 * @brief Allocate memory for vertex and facets
 *
 * @param data obj_data struct
 * @return int status. 0 - kSuccsess, 1 - kFailure
 */
int MemoryAlloc(obj_data *data) {
  int status = kFailure;
  if (data->edges_n && data->vertices_n) {
    data->vertices = calloc(data->vertices_n * 3, sizeof(double));
    data->facets = calloc(data->edges_n * 2, sizeof(int));
    status = !(data->vertices && data->facets);
  }
  return status;
}

/**
 * @brief Write vertex and facets
 *
 * @param f file stream
 * @param data destination struct
 */
void ParseFile(FILE *f, obj_data *data) {
  char line[256];
  // size_t len = 0;
  size_t i = 0;
  size_t j = 0;

  setlocale(LC_NUMERIC, "C");

  while (fgets(line, 256, f)) {
    if (!strncmp(line, "v ", 2)) {
      char *istr = strtok(line + 2, " ");
      while (istr != NULL) {
        double d = atof(istr);
        if (fabs(d) > data->v_max) data->v_max = fabs(d);
        data->vertices[i++] = d;
        istr = strtok(NULL, " ");
      }
    } else if (!strncmp(line, "f ", 2)) {
      int is_first = 1;
      char *istr = strtok(line + 2, " ");
      int first = atoi(istr) - 1;
      while (istr != NULL) {
        int val = atoi(istr) - 1;
        data->facets[j++] = val;
        if (is_first)
          is_first = 0;
        else
          data->facets[j++] = val;
        istr = strtok(NULL, " ");
      }
      data->facets[j++] = first;
    }
  }
}
