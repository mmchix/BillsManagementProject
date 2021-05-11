//
// Created by Mohamed MCHICH on 8/5/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_NewCreditor.h" resolved

#include <QMessageBox>
#include <QRandomGenerator>
#include "newcreditor.h"
#include "ui_NewCreditor.h"
#include "../../models/creditor/Creditor.h"
#include "../../models/manager/Manager.h"
#include "../creditors/qcreditors.h"

NewCreditor::NewCreditor(QWidget *parent) :
        QDialog(parent), ui(new Ui::NewCreditor) {
    ui->setupUi(this);
    ui->inID->setText(Manager::newID());
    ui->inID->setEnabled(false);
}

NewCreditor::NewCreditor(QWidget *parent,Creditor creditor) :
        QDialog(parent), ui(new Ui::NewCreditor) {
    ui->setupUi(this);
    update = true;
    this->creditor = creditor;
    ui->inID->setEnabled(false);
    ui->inID->setText(QString("%1").arg(creditor.num));
    ui->inPhone->setText(creditor.phone);
    ui->inEmail->setText(creditor.email);
    ui->inCity->setText(creditor.city);
    ui->inFirstname->setText(creditor.firstname);
    ui->inLastname->setText(creditor.lastname);
    ui->inCountry->setText(creditor.country);
    ui->btnNewCreditor->setText("Update");
}

NewCreditor::~NewCreditor() {
    delete ui;
}

void NewCreditor::on_btnNewCreditor_clicked() {
    Creditor creditor;
    creditor.num = ui->inID->text();
    creditor.phone = ui->inPhone->text();
    creditor.email = ui->inEmail->text();
    creditor.city = ui->inCity->text();
    creditor.userID = Manager::currentUser.userID;
    creditor.firstname = ui->inFirstname->text();
    creditor.lastname = ui->inLastname->text();
    creditor.country = ui->inCountry->text();
    if(update)
        Manager::updateCreditor(creditor);
    else
        Manager::addCreditor(creditor);
    QMessageBox::warning(this,"Info",update ? "Creditor was updated successfully":"Creditor was addedd successfully");
    close();
    QCreditors *qCreditors = new QCreditors(this);
    qCreditors->exec();
}
