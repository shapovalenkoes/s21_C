#include "depositcalc.h"

#include "ui_depositcalc.h"

DepositCalc::DepositCalc(QWidget *parent)
    : QWidget(parent), ui(new Ui::DepositCalc) {
  ui->setupUi(this);

  this->setWindowTitle("Deposit Calculator");
  connect(ui->calc, SIGNAL(clicked()), this, SLOT(on_calc_clicked()));
}

DepositCalc::~DepositCalc() { delete ui; }

void DepositCalc::on_calc_clicked() {
  double deposit_sum = ui->deposit_sum->text().toDouble();
  double term = ui->term->text().toDouble();
  double interest_rate = ui->interest_rate->text().toDouble();
  double tax = ui->tax->text().toDouble();
  double payment_periodicity = ui->periodicity->text().toDouble();
  int capitalization = ui->capitalization->isChecked();

  double interest_paid = 0;
  double final_amount_deposit = 0;
  double tax_amount = 0;

  if (!capitalization) {
    final_amount_deposit = deposit_sum;
    interest_paid = (deposit_sum * interest_rate * term / 12) / 100;
  } else {
    final_amount_deposit =
        deposit_sum *
        pow(1 + (payment_periodicity / 12) * (interest_rate / 100), term);
    interest_paid = final_amount_deposit - deposit_sum;
  }
  if (interest_paid > 75000) {
    tax_amount = tax / 100 * (interest_paid - 75000);
  }

  ui->paid->setText("Interest paid: " +
                    QString::number(interest_paid, 'g', 15));
  ui->tax_paid->setText("Tax amount: " + QString::number(tax_amount, 'g', 15));
  ui->final_sum->setText("Final amount deposit: " +
                         QString::number(final_amount_deposit, 'g', 15));
}
