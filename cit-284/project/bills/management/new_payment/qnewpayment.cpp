//
// Created by Mohamed MCHICH on 9/5/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QNewPayment.h" resolved

#include "qnewpayment.h"
#include "ui_QNewPayment.h"
#include "../../models/payment/Payment.h"
#include "../../models/manager/Manager.h"
#include <QRandomGenerator64>
#include <QMessageBox>

QNewPayment::QNewPayment(QWidget *parent) :
        QDialog(parent), ui(new Ui::QNewPayment) {
    ui->setupUi(this);
}

QNewPayment::~QNewPayment() {
    delete ui;
}

QNewPayment::QNewPayment(QWidget *parent, QString creditID)  :
        QDialog(parent), ui(new Ui::QNewPayment) {
    ui->setupUi(this);
    this->creditID = creditID;
    this->paymentID = Manager::newID();
    ui->inCreditId->setText(creditID);
    ui->inPaymentID->setText(paymentID);
    ui->inPaymentDate->setDate(QDate::currentDate());
}

void QNewPayment::on_btnAddPayment_clicked() {
    Payment payment;
    payment.creditID = creditID;
    payment.paymentId = paymentID;
    payment.paymentDate = ui->inPaymentDate->date();
    payment.paymentValue = ui->inAmount->text().toDouble();
    Manager::addPayment(payment);
    QMessageBox::warning(this,"Info","The payment was added successfully");
    close();
}


