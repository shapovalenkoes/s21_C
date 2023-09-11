#include "graph.h"

#include <iostream>

#include "ui_graph.h"

Graph::Graph(QWidget* parent) : QWidget(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
  this->setWindowTitle("Plot Graph");

  step = 0.1;
  x_start = -10;
  x_end = 10;
  y_start = -10;
  y_end = 10;
}

Graph::~Graph() { delete ui; }

void Graph::plot(QString str) {
  x_start = ui->min_x->text().toDouble();
  x_end = ui->max_x->text().toDouble();
  y_start = ui->min_y->text().toDouble();
  y_end = ui->max_y->text().toDouble();

  if (x_start < -LIMIT) x_start = -LIMIT;
  if (x_end > LIMIT) x_end = LIMIT;
  if (y_start < -LIMIT) y_start = -LIMIT;
  if (y_end > LIMIT) y_end = LIMIT;

  ui->qcustomplot->xAxis->setRange(x_start, x_end);
  ui->qcustomplot->yAxis->setRange(y_start, y_end);
  ui->qcustomplot->xAxis->setLabel("x");
  ui->qcustomplot->yAxis->setLabel("y");

  x.clear();
  y.clear();

  ui->qcustomplot->clearPlottables();
  ui->qcustomplot->clearGraphs();

  const char* expr = str.toStdString().c_str();

  for (X = x_start; X <= x_end; X += step) {
    char valid_str[MAX_SIZE] = "";
    int status = validator(expr, valid_str);
    if (!status) {
      Queue tokens = get_all_tokens(valid_str);
      Queue rpn = to_RPN(&tokens);
      double result = 0;
      status = calculate(rpn, &result, X);
      if (std::isnan(result) || std::isinf(result) || result > y_end ||
          result < y_start) {
        x.push_back(X);
        y.push_back(NAN);
      } else {
        x.push_back(X);
        y.push_back(result);
      }

      ui->qcustomplot->addGraph();
      ui->qcustomplot->graph(0)->addData(x, y);
      ui->qcustomplot->replot();
    } else {
      ui->input_area->setText("Invalid Expression");
      ui->qcustomplot->clearPlottables();
      ui->qcustomplot->clearGraphs();

      break;
    }
  }
}

void Graph::on_plot_button_clicked() { plot(ui->input_area->text()); }
