#include "transformations.h"

#include <math.h>
/**
 * @param obj obj_data struct
 * @param angle angle in degree
 */
void RotateX(obj_data *obj, double angle) {
  angle = angle * M_PI / 180;
  for (size_t i = 0; i < obj->vertices_n * 3; i += 3) {
    double y = obj->vertices[i + 1];
    double z = obj->vertices[i + 2];
    obj->vertices[i + 1] = y * cos(angle) + z * sin(angle);
    obj->vertices[i + 2] = -y * sin(angle) + z * cos(angle);
  }
}
/**
 * @param obj obj_data struct
 * @param angle angle in degree
 */
void RotateY(obj_data *obj, double angle) {
  angle = angle * M_PI / 180;
  for (size_t i = 0; i < obj->vertices_n * 3; i += 3) {
    double x = obj->vertices[i];
    double z = obj->vertices[i + 2];
    obj->vertices[i] = x * cos(angle) + z * sin(angle);
    obj->vertices[i + 2] = -x * sin(angle) + z * cos(angle);
  }
}
/**
 * @param obj obj_data struct
 * @param angle angle in degree
 */
void RotateZ(obj_data *obj, double angle) {
  angle = angle * M_PI / 180;
  for (size_t i = 0; i < obj->vertices_n * 3; i += 3) {
    double x = obj->vertices[i];
    double y = obj->vertices[i + 1];
    obj->vertices[i] = x * cos(angle) + y * sin(angle);
    obj->vertices[i + 1] = -x * sin(angle) + y * cos(angle);
  }
}
/**
 * @param obj obj_data struct
 * @param k scale factor
 */
void Scale(obj_data *obj, const double k) {
  if (k != 0) {
    for (size_t i = 0; i < obj->vertices_n * 3; i++) {
      obj->vertices[i] *= k;
    }
  }
}
/**
 * @param obj obj_data struct
 * @param k translate value
 */
void TranslateX(obj_data *obj, const double k) {
  for (size_t i = 0; i < obj->vertices_n * 3; i += 3) {
    obj->vertices[i] += k;
  }
}
/**
 * @param obj obj_data struct
 * @param k translate value
 */
void TranslateY(obj_data *obj, const double k) {
  for (size_t i = 1; i < obj->vertices_n * 3; i += 3) {
    obj->vertices[i] += k;
  }
}
/**
 * @param obj obj_data struct
 * @param k translate value
 */
void TranslateZ(obj_data *obj, const double k) {
  for (size_t i = 2; i < obj->vertices_n * 3; i += 3) {
    obj->vertices[i] += k;
  }
}
