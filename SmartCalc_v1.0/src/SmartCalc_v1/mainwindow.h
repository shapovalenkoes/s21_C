#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <creditcalc.h>
#include <depositcalc.h>
#include <graph.h>
#include <qcustomplot.h>

#include <QMainWindow>
#include <QVector>

extern "C" {
#include "calc.h"
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

 private:
  Ui::MainWindow *ui;

 private slots:
  void push_button();
  void push_button_func();
  void clear_input();
  void get_result();

  void on_pushButton_deposit_clicked();
  void on_pushButton_credit_clicked();
  void on_pushButton_plot_clicked();
};
#endif  // MAINWINDOW_H
