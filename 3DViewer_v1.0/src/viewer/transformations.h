#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "load_model.h"

void RotateX(obj_data *obj, const double angle);
void RotateY(obj_data *obj, const double angle);
void RotateZ(obj_data *obj, const double angle);
void TranslateX(obj_data *obj, const double shift);
void TranslateY(obj_data *obj, const double shift);
void TranslateZ(obj_data *obj, const double shift);
void Scale(obj_data *obj, const double cofactor);

#endif  // TRANSFORMATIONS_H
