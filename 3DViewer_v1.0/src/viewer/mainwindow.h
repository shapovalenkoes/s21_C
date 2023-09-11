#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

extern "C" {
#include "load_model.h"
#include "transformations.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void OpenFile();
  void ShowInfo(int status);
  void Reset();
  void SaveSettings();
  void LoadSettings();
  void UpdateButtonsAndSliders();
  void TransformModel();
  void SetBackgroundColor();
  void Zoom();
  void ScaleModel();

  void SetVerticesType();
  void SetVerticesSize();
  void SetVerticesColor();

  void SetEdgesType();
  void SetEdgesThickness();
  void SetEdgesColor();

  void SetProjectionType();

  void TakeScreenshot();
  void TakeGIF();
  void SaveGIF(QVector<QImage> &frames, QString filename);

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
