#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  this->setWindowTitle("SmartCalc v1.0");

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(push_button_func()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(push_button_func()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(push_button_func()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(push_button_func()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(push_button_func()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(push_button_func()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(push_button_func()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(push_button_func()));

  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(push_button_func()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(push_button()));
  connect(ui->pushButton_rh_bracket, SIGNAL(clicked()), this,
          SLOT(push_button()));
  connect(ui->pushButton_lf_bracket, SIGNAL(clicked()), this,
          SLOT(push_button()));

  connect(ui->pushButton_ac, SIGNAL(clicked()), this, SLOT(clear_input()));

  connect(ui->pushButton_eq, SIGNAL(clicked()), this, SLOT(get_result()));
  connect(ui->input_field, SIGNAL(returnPressed()), SLOT(get_result()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::push_button() {
  QPushButton *button = (QPushButton *)sender();
  QString input = ui->input_field->text();
  QString new_label;
  if (input.contains("ZeroInvalid") || input == "0") {
    ui->input_field->clear();
  }

  new_label = ui->input_field->text() + button->text();

  ui->input_field->setText(new_label);
}

void MainWindow::push_button_func() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label;
  QString input = ui->input_field->text();
  if (input.contains("ZeroInvalid") || input == "0") {
    ui->input_field->clear();
  }

  new_label = ui->input_field->text() + button->text() + "(";

  ui->input_field->setText(new_label);
}

void MainWindow::clear_input() {
  ui->input_field->setText("0");
  ui->input_x->setText("");
}

void MainWindow::get_result() {
  QString input = ui->input_field->text();
  int flag = 0;

  if ((input.contains("x") || input.contains("X")) &&
      ui->input_x->text() == "") {
    on_pushButton_plot_clicked();
    flag = 1;
  }
  if (!flag) {
    char valid_str[MAX_SIZE] = "";
    double x = ui->input_x->text().toDouble();
    ui->input_x->clear();
    const char *str = input.toStdString().c_str();
    int status = validator(str, valid_str);

    if (status) {
      ui->input_field->setText("Invalid Input");
    } else {
      double result = 0;

      Queue tokens = get_all_tokens(valid_str);

      Queue rpn = to_RPN(&tokens);

      status = calculate(rpn, &result, x);

      if (status)
        ui->input_field->setText("Zero Division");
      else {
        ui->input_field->setText(QString::number(result));
      }
    }
  }
}

void MainWindow::on_pushButton_deposit_clicked() {
  DepositCalc *deposit = new DepositCalc();
  deposit->show();
}

void MainWindow::on_pushButton_credit_clicked() {
  CreditCalc *credit = new CreditCalc();
  credit->show();
}

void MainWindow::on_pushButton_plot_clicked() {
  Graph *graph = new Graph();
  graph->show();
  graph->plot(ui->input_field->text());
}
