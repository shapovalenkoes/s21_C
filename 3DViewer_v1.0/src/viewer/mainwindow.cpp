#include "mainwindow.h"

#include <QImageWriter>
#include <QSettings>

#include "gif.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->statusbar->addPermanentWidget(&ui->OGLW->info);
  LoadSettings();

  connect(ui->openButton, SIGNAL(clicked()), this, SLOT(OpenFile()));
  connect(ui->resetSettingsButton, SIGNAL(clicked()), this, SLOT(Reset()));

  connect(ui->rotateX, SIGNAL(valueChanged(int)), this, SLOT(TransformModel()));
  connect(ui->rotateY, SIGNAL(valueChanged(int)), this, SLOT(TransformModel()));
  connect(ui->rotateZ, SIGNAL(valueChanged(int)), this, SLOT(TransformModel()));

  connect(ui->translateX, SIGNAL(valueChanged(int)), this,
          SLOT(TransformModel()));
  connect(ui->translateY, SIGNAL(valueChanged(int)), this,
          SLOT(TransformModel()));
  connect(ui->translateZ, SIGNAL(valueChanged(int)), this,
          SLOT(TransformModel()));

  connect(ui->backgroundColorButton, SIGNAL(clicked()), this,
          SLOT(SetBackgroundColor()));

  connect(ui->zoomIn, SIGNAL(clicked()), this, SLOT(Zoom()));
  connect(ui->zoomOut, SIGNAL(clicked()), this, SLOT(Zoom()));
  connect(ui->scaleSlider, SIGNAL(valueChanged(int)), this, SLOT(ScaleModel()));

  connect(ui->verticesNoneRadio, SIGNAL(clicked()), this,
          SLOT(SetVerticesType()));
  connect(ui->verticesSquareRadio, SIGNAL(clicked()), this,
          SLOT(SetVerticesType()));
  connect(ui->verticesCircleRadio, SIGNAL(clicked()), this,
          SLOT(SetVerticesType()));
  connect(ui->verticesSizeSlider, SIGNAL(valueChanged(int)), this,
          SLOT(SetVerticesSize()));
  connect(ui->verticesColorButton, SIGNAL(clicked()), this,
          SLOT(SetVerticesColor()));

  connect(ui->edgesSolidRadio, SIGNAL(clicked()), this, SLOT(SetEdgesType()));
  connect(ui->edgesDashesRadio, SIGNAL(clicked()), this, SLOT(SetEdgesType()));
  connect(ui->edgesThicknessSlider, SIGNAL(valueChanged(int)), this,
          SLOT(SetEdgesThickness()));
  connect(ui->edgesColorButton, SIGNAL(clicked()), this, SLOT(SetEdgesColor()));

  connect(ui->projectionCentralRadio, SIGNAL(clicked()),
          SLOT(SetProjectionType()));
  connect(ui->projectionParallelRadio, SIGNAL(clicked()),
          SLOT(SetProjectionType()));

  connect(ui->OGLW, SIGNAL(mouseMove()), this, SLOT(UpdateButtonsAndSliders()));
  connect(ui->screenshotButton, SIGNAL(clicked()), this,
          SLOT(TakeScreenshot()));
  connect(ui->gifButton, SIGNAL(clicked()), this, SLOT(TakeGIF()));
}

MainWindow::~MainWindow() {
  SaveSettings();
  ClearData(&ui->OGLW->data);
  delete ui;
}
/**
 * @brief Reset settings
 *
 */
void MainWindow::Reset() {
  ui->rotateX->setValue(0);
  ui->rotateY->setValue(0);
  ui->rotateZ->setValue(0);
  ui->translateX->setValue(0);
  ui->translateY->setValue(0);
  ui->translateZ->setValue(0);
  ui->OGLW->vertices_type = kNone;
  ui->OGLW->edges_type = kSolid;
  ui->OGLW->projection_type = kParallel;
  ui->OGLW->scale_val = 5;
  ui->OGLW->edges_thickness = 1;
  ui->OGLW->bg_color = Qt::black;
  ui->OGLW->edges_color = Qt::white;
  ui->OGLW->vertices_color = Qt::white;

  UpdateButtonsAndSliders();
  ui->OGLW->update();
}

void MainWindow::SaveSettings() {
  QSettings settings("School21", "3DViewer");

  settings.beginGroup("MainWindow");

  settings.setValue("projection_type", ui->OGLW->projection_type);

  settings.setValue("edges_type", ui->OGLW->edges_type);
  settings.setValue("edges_thickness", ui->OGLW->edges_thickness);
  settings.setValue("edges_color", ui->OGLW->edges_color);

  settings.setValue("vertices_type", ui->OGLW->vertices_type);
  settings.setValue("vertices_size", ui->OGLW->vertices_size);
  settings.setValue("vertices_color", ui->OGLW->vertices_color);

  settings.setValue("bg_color", ui->OGLW->bg_color);

  settings.endGroup();
}

void MainWindow::LoadSettings() {
  QSettings settings("School21", "3DViewer");

  settings.beginGroup("MainWindow");

  ui->OGLW->projection_type = settings.value("projection_type").toInt();

  ui->OGLW->edges_type = settings.value("edges_type").toInt();
  ui->OGLW->edges_thickness = settings.value("edges_thickness", 1).toInt();
  ui->OGLW->edges_color =
      settings.value("edges_color", "255 255 255 0").value<QColor>();

  ui->OGLW->vertices_type = settings.value("vertices_type").toInt();
  ui->OGLW->vertices_size = settings.value("vertices_size").toInt();
  ui->OGLW->vertices_color =
      settings.value("vertices_color", "255 255 255 0").value<QColor>();

  ui->OGLW->bg_color = settings.value("bg_color", "0 0 0 0").value<QColor>();

  settings.endGroup();

  UpdateButtonsAndSliders();
}

void MainWindow::UpdateButtonsAndSliders() {
  ui->edgesColorButton->setPalette(ui->OGLW->edges_color);
  ui->backgroundColorButton->setPalette(ui->OGLW->bg_color);
  ui->verticesColorButton->setPalette(ui->OGLW->vertices_color);

  ui->verticesSizeSlider->setValue(ui->OGLW->vertices_size);
  ui->edgesThicknessSlider->setValue(ui->OGLW->edges_thickness);
  ui->scaleSlider->setValue(ui->OGLW->scale_val);

  ui->rotateX->setValue(ui->OGLW->rotate_x);
  ui->rotateY->setValue(ui->OGLW->rotate_y);
  ui->rotateZ->setValue(ui->OGLW->rotate_z);

  ui->translateX->setValue(ui->OGLW->translate_x);
  ui->translateY->setValue(ui->OGLW->translate_y);
  ui->translateZ->setValue(ui->OGLW->translate_z);

  if (ui->OGLW->vertices_type == kNone) {
    ui->verticesNoneRadio->click();
  } else if (ui->OGLW->vertices_type == kCircle) {
    ui->verticesCircleRadio->click();
  } else {
    ui->verticesSquareRadio->click();
  }

  if (ui->OGLW->edges_type == kSolid) {
    ui->edgesSolidRadio->click();
  } else {
    ui->edgesDashesRadio->click();
  }

  if (ui->OGLW->projection_type == kParallel) {
    ui->projectionParallelRadio->click();
  } else {
    ui->projectionCentralRadio->click();
  }
}

void MainWindow::OpenFile() {
  QString absoluteFilePath = QFileDialog::getOpenFileName(
      this, tr("Load OBJ File"), "viewer/samples", "OBJ Files (*.obj *.txt)");
  if (!absoluteFilePath.isEmpty()) {
    QFileInfo fileInfo(absoluteFilePath);
    const char *c_str = absoluteFilePath.toLocal8Bit().data();
    ui->OGLW->filename = fileInfo.baseName();
    int status = LoadModel(c_str, &ui->OGLW->data);
    ShowInfo(status);
    if (status == kSuccess) ui->OGLW->update();
  }
}

void MainWindow::ShowInfo(int status) {
  if (status == kSuccess) {
    ui->OGLW->info.setText(
        ui->OGLW->filename +
        " Vertices: " + QString::number(ui->OGLW->data.vertices_n) +
        " Edges: " + QString::number(ui->OGLW->data.edges_n / 2));
    ui->statusbar->showMessage(tr("Success"), 3000);
  } else {
    ui->OGLW->info.clear();
    ui->statusbar->showMessage(tr("Failed"), 3000);
  }
}

void MainWindow::SetBackgroundColor() {
  QColor initialColor = ui->OGLW->bg_color;
  QColor newColor =
      QColorDialog::getColor(initialColor, this, tr("Select Background Color"));
  if (newColor.isValid()) {
    ui->OGLW->bg_color = newColor;
    ui->backgroundColorButton->setPalette(newColor);
    ui->OGLW->update();
  }
}

void MainWindow::TransformModel() {
  QSlider *slider = (QSlider *)sender();
  QString findQLabel = sender()->objectName() + "Value";

  int value = slider->value();
  this->findChild<QLabel *>(findQLabel)->setText(QString::number(value));

  if (findQLabel.contains("X")) {
    if (findQLabel.contains("rotate")) {
      //            RotateX(&ui->OGLW->data, (value - ui->OGLW->rotate_x));
      ui->OGLW->rotate_x = value;
    } else {
      //            TranslateX(&ui->OGLW->data, (value -
      //            ui->OGLW->translate_x));
      ui->OGLW->translate_x = value;
    }
  } else if (findQLabel.contains("Y")) {
    if (findQLabel.contains("rotate")) {
      //            RotateY(&ui->OGLW->data, (value - ui->OGLW->rotate_y));
      ui->OGLW->rotate_y = value;
    } else {
      //            TranslateY(&ui->OGLW->data, (value -
      //            ui->OGLW->translate_y));
      ui->OGLW->translate_y = value;
    }
  } else {
    if (findQLabel.contains("rotate")) {
      //            RotateZ(&ui->OGLW->data, (value - ui->OGLW->rotate_z));
      ui->OGLW->rotate_z = value;
    } else {
      //            TranslateZ(&ui->OGLW->data, (value -
      //            ui->OGLW->translate_z));
      ui->OGLW->translate_z = value;
    }
  }
  ui->OGLW->update();
}

void MainWindow::Zoom() {
  QString button = sender()->objectName();
  int current = ui->scaleSlider->value();
  if (button.contains("In")) {
    ui->scaleSlider->setValue(current + 1);
  } else {
    ui->scaleSlider->setValue(current - 1);
  }
}

void MainWindow::ScaleModel() {
  QSlider *slider = (QSlider *)sender();
  double value = (double)slider->value();

  //  double val = value / ui->OGLW->scale_val;
  //  Scale(&ui->OGLW->data, val);
  ui->OGLW->scale_val = value;
  ui->OGLW->update();
}

void MainWindow::SetVerticesType() {
  QString button = sender()->objectName();
  if (button.contains("None")) {
    ui->OGLW->vertices_type = kNone;
  } else if (button.contains("Circle")) {
    ui->OGLW->vertices_type = kCircle;
  } else {
    ui->OGLW->vertices_type = kSquare;
  }
  ui->OGLW->update();
}

void MainWindow::SetVerticesSize() {
  QSlider *slider = (QSlider *)sender();
  double value = (double)slider->value();

  ui->OGLW->vertices_size = value;
  ui->OGLW->update();
}

void MainWindow::SetVerticesColor() {
  QColor initialColor = ui->OGLW->vertices_color;
  QColor newColor =
      QColorDialog::getColor(initialColor, this, tr("Select Vertices Color"));
  if (newColor.isValid()) {
    ui->OGLW->vertices_color = newColor;
    ui->verticesColorButton->setPalette(newColor);
    ui->OGLW->update();
  }
}

void MainWindow::SetEdgesType() {
  QString button = sender()->objectName();
  if (button.contains("Solid")) {
    ui->OGLW->edges_type = kSolid;
  } else {
    ui->OGLW->edges_type = kDashes;
  }
  ui->OGLW->update();
}

void MainWindow::SetEdgesThickness() {
  QSlider *slider = (QSlider *)sender();
  double value = (double)slider->value();

  ui->OGLW->edges_thickness = value;
  ui->OGLW->update();
}

void MainWindow::SetEdgesColor() {
  QColor initialColor = ui->OGLW->edges_color;
  QColor newColor =
      QColorDialog::getColor(initialColor, this, tr("Select edges Color"));

  if (newColor.isValid()) {
    ui->OGLW->edges_color = newColor;
    ui->edgesColorButton->setPalette(newColor);
    ui->OGLW->update();
  }
}

void MainWindow::SetProjectionType() {
  QString button = sender()->objectName();
  if (button.contains("Parallel")) {
    ui->OGLW->projection_type = kParallel;
  } else {
    ui->OGLW->projection_type = kCentral;
  }
  ui->OGLW->update();
}

void MainWindow::TakeScreenshot() {
  QString filename = QFileDialog::getSaveFileName(
      this, tr("Save the screenshot"),
      "screenshots/" + ui->OGLW->filename + ".jpg", tr("Images (*.jpg *.png)"));
  if (!filename.isEmpty()) {
    ui->OGLW->grabFramebuffer().save(filename);
    ui->statusbar->showMessage(tr("Screenshot was saved"), 3000);
  }
}

void MainWindow::TakeGIF() {
  QString filename = QFileDialog::getSaveFileName(
      this, tr("Save the GIF"), "screenshots/" + ui->OGLW->filename + ".gif",
      tr("Images (*.gif)"));
  if (!filename.isEmpty()) {
    ui->gifButton->setDisabled(true);
    QTimer *timer = new QTimer(this);
    QVector<QImage> frames;
    connect(
        timer, &QTimer::timeout, this,
        [this, frames, filename, timer]() mutable {
          int duration = 5;
          int frames_per_sec = 10;
          int total_frames = duration * frames_per_sec;
          if (frames.size() < total_frames) {
            int height = 640;
            int width = 480;
            if (frames.size() % frames_per_sec == 0) {
              ui->statusbar->showMessage(
                  tr("Making the GIF: %1")
                      .arg(duration - frames.size() / frames_per_sec),
                  1000);
            }
            frames.push_back(ui->OGLW->grabFramebuffer().scaled(height, width));
          } else {
            timer->stop();
            delete timer;
            ui->gifButton->setDisabled(false);
            SaveGIF(frames, filename);
          }
        });
    timer->start(100);
  }
}

void MainWindow::SaveGIF(QVector<QImage> &frames, QString filename) {
  GifWriter gw;
  int height = frames.first().height();
  int width = frames.first().width();
  GifBegin(&gw, filename.toStdString().c_str(), width, height, 10);

  for (QImage &frame : frames) {
    std::vector<uint8_t> rgbaPixels(width * height * 4, 0);
    for (int y = 0; y != height; ++y) {
      for (int x = 0; x != width; ++x) {
        QRgb pixel = frame.pixel(x, y);
        rgbaPixels[(y * width + x) * 4 + 0] = qRed(pixel);
        rgbaPixels[(y * width + x) * 4 + 1] = qGreen(pixel);
        rgbaPixels[(y * width + x) * 4 + 2] = qBlue(pixel);
        rgbaPixels[(y * width + x) * 4 + 3] = 0;
      }
    }
    GifWriteFrame(&gw, rgbaPixels.data(), width, height, 10);
  }
  frames.clear();
  GifEnd(&gw);
  ui->statusbar->showMessage(tr("GIF was saved"), 3000);
}
