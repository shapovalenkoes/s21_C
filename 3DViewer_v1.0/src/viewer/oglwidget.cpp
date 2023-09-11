#include "oglwidget.h"

#include "load_model.h"
#include "mainwindow.h"

OGLWidget::OGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

OGLWidget::~OGLWidget() {}

void OGLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnableClientState(GL_VERTEX_ARRAY);
  glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_ALPHA_TEST);
  glEnable(GL_BLEND);

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_POINT_SMOOTH);
  //  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void OGLWidget::paintGL() {
  glClearColor(bg_color.redF(), bg_color.greenF(), bg_color.blueF(),
               bg_color.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glVertexPointer(3, GL_DOUBLE, 0, data.vertices);

  // replace the current matrix with the identity matrix
  glLoadIdentity();
  if (projection_type == kCentral) {
    // multiply the current matrix by a perspective matrix
    glFrustum(-data.v_max, data.v_max, -data.v_max, data.v_max, 0,
              data.v_max * 100);

  } else {
    // multiply the current matrix with an orthographic matrix
    glOrtho(-1, 1, -1, 1, 1, 1);
  }
  glTranslatef(translate_x / 850, -translate_y / 850, translate_z / 180);
  glRotatef(rotate_x, 0, 1, 0);
  glRotatef(rotate_y, 1, 0, 0);
  glRotatef(rotate_z, 0, 0, 1);
  glScalef(scale_val / 10, scale_val / 10, scale_val / 10);

  paintFacets();
  paintVertices();
}
/**
 * @brief Paint facets on the screen
 *
 */
void OGLWidget::paintFacets() {
  if (edges_type) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  glLineWidth(edges_thickness);
  glColor3f(edges_color.redF(), edges_color.greenF(), edges_color.blueF());
  glDrawElements(GL_LINES, data.edges_n * 2, GL_UNSIGNED_INT, data.facets);
}
/**
 * @brief Paint vertex on the screen
 *
 */
void OGLWidget::paintVertices() {
  if (vertices_type) {
    if (vertices_type == kCircle)
      glEnable(GL_POINT_SMOOTH);
    else
      glDisable(GL_POINT_SMOOTH);
    glColor3f(vertices_color.redF(), vertices_color.greenF(),
              vertices_color.blueF());
    glPointSize(vertices_size);
    glDrawArrays(GL_POINTS, 0, data.vertices_n);
  }
}
/**
 * @brief Write mouse position when clicked
 */
void OGLWidget::mousePressEvent(QMouseEvent *event) {
  MousePosition = event->pos();
}
/**
 * @brief Track mouse position while clicked,change rotate and translate angle
 * @param event
 */
void OGLWidget::mouseMoveEvent(QMouseEvent *event) {
  int x_shift = event->pos().x() - MousePosition.x();
  int y_shift = event->pos().y() - MousePosition.y();

  if (event->buttons() == Qt::LeftButton) {
    translate_x = x_shift;
    translate_y = y_shift;

  } else if (event->buttons() == Qt::RightButton) {
    rotate_x = x_shift;
    rotate_y = y_shift;
  }

  update();
  emit mouseMove();
}

void OGLWidget::wheelEvent(QWheelEvent *event) {
  if (rotate_z >= -360 && rotate_z <= 360) {
    if (event->angleDelta().y() > 0 && rotate_z < 360) {
      rotate_z += 30;
    } else if (event->angleDelta().y() < 0 && rotate_z > -360) {
      rotate_z -= 30;
    }
  }
  update();
  emit mouseMove();
}
