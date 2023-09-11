#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QColor>
#include <QtOpenGLWidgets>

extern "C" {
#include "load_model.h"
#include "transformations.h"
}

enum VerticesType { kNone, kCircle, kSquare };

enum ProjectionType { kParallel, kCentral };

enum EdgesType { kSolid, kDashes };

class OGLWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions {
  Q_OBJECT
 public:
  OGLWidget(QWidget *parent = nullptr);
  ~OGLWidget();

  QString filename = "Untitled";
  QLabel info;

  double scale_val = 5;

  double rotate_x = 0;
  double rotate_y = 0;
  double rotate_z = 0;

  double translate_x = 0;
  double translate_y = 0;
  double translate_z = 0;

  double vertices_size = 1;
  int vertices_type = kNone;
  QColor vertices_color = QColor("white");

  double edges_thickness = 1;
  int edges_type = kSolid;
  QColor edges_color = QColor("white");

  int projection_type = kParallel;

  QColor bg_color = QColor("black");

  obj_data data = {0, 0, 0, 0, NULL, NULL};

 protected:
  void initializeGL() override;
  void paintGL() override;

 private:
  void paintFacets();
  void paintVertices();
  void wheelEvent(QWheelEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mousePressEvent(QMouseEvent *event);

  QPoint MousePosition;

 signals:
  void mouseMove();
};

#endif  // OGLWIDGET_H
