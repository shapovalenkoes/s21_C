#include "creditcalc.h"

#include "ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);

  this->setWindowTitle("Credit Calculator");
  connect(ui->annuity_button, SIGNAL(clicked()), this,
          SLOT(on_annuity_button_clicked()));
  connect(ui->differential_button, SIGNAL(clicked()), this,
          SLOT(on_differential_button_clicked()));
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_annuity_button_clicked() {
  double credit_sum = ui->sum->text().toDouble();
  double interest_rate = ui->rate->text().toDouble() / 100;
  double term = ui->term->text().toDouble();

  double monthly_interest_rate = interest_rate / 12;
  double temp_rate = pow(1 + monthly_interest_rate, term);
  double annuity_rate = (monthly_interest_rate * temp_rate) / (temp_rate - 1);

  double monthly_payment = credit_sum * annuity_rate;
  double total_payment = monthly_payment * term;
  double overpayment = total_payment - credit_sum;

  ui->show_result->clear();
  ui->show_result->appendPlainText("Monthly payment: " +
                                   QString::number(monthly_payment));
  ui->show_result->appendPlainText("Overpayment: " +
                                   QString::number(overpayment));
  ui->show_result->appendPlainText("Total payment: " +
                                   QString::number(total_payment));
}

void CreditCalc::on_differential_button_clicked() {
  double credit_sum = ui->sum->text().toDouble();
  double interest_rate = ui->rate->text().toDouble() / 100;
  double term = ui->term->text().toDouble();

  double monthly_principal_payments = credit_sum / term;
  double loan_balance = credit_sum;

  double total_payment = 0;
  double overpayment = 0;

  ui->show_result->clear();

  for (int i = 1; i <= term; i++) {
    double monthly_payment =
        monthly_principal_payments + (loan_balance * interest_rate * 1.0 / 12);
    loan_balance -= monthly_principal_payments;
    ui->show_result->appendPlainText("Month " + QString::number(i) + ": " +
                                     QString::number(monthly_payment));
    total_payment += monthly_payment;
  }
  overpayment = total_payment - credit_sum;

  ui->show_result->appendPlainText("");
  ui->show_result->appendPlainText("Overpayment: " +
                                   QString::number(overpayment, 'g', 15));
  ui->show_result->appendPlainText("Total payment: " +
                                   QString::number(total_payment, 'g', 15));
}
