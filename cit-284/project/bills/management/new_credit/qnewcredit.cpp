//
// Created by Mohamed MCHICH on 9/5/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QNewCredit.h" resolved

#include <QMessageBox>
#include <QRandomGenerator>
#include "qnewcredit.h"
#include "ui_QNewCredit.h"
#include "../../models/manager/Manager.h"
#include "../creditors/qcreditors.h"

QNewCredit::QNewCredit(QWidget *parent) :
        QDialog(parent), ui(new Ui::QNewCredit) {
    ui->setupUi(this);
}

QNewCredit::~QNewCredit() {
    delete ui;
}

QNewCredit::QNewCredit(QWidget *parent,Creditor creditor) :
        QDialog(parent), ui(new Ui::QNewCredit) {
    ui->setupUi(this);
    this->creditor = creditor;
    ui->labelCreditor->setText(QString("%1").arg(creditor.num));
    ui->labelFirstname->setText(creditor.firstname);
    ui->labelLastname->setText(creditor.lastname);
    ui->labelPhone->setText(creditor.phone);
    ui->inCreditID->setText(Manager::newID());
    ui->inCreditID->setEnabled(false);
}

void QNewCredit::on_btnAddCredit_clicked() {
    Credit credit;
    credit.creditID = ui->inCreditID->text();
    credit.creditValue = ui->inAmount->text().toDouble();
    credit.creditorID = creditor.num;
    credit.dateStarts = ui->inDateStarts->date();
    credit.dateEnd = ui->inDateEnds->date();
        Manager::addCredit(credit);
    QMessageBox::warning(this,"Info","Credit was added successfully");
    close();
}
