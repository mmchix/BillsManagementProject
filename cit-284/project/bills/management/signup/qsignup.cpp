//
// Created by Mohamed MCHICH on 7/5/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QSignup.h" resolved

#include <QMessageBox>
#include <QCryptographicHash>
#include "qsignup.h"
#include "ui_QSignup.h"
#include "../../models/user/User.h"
#include "../../models/manager/Manager.h"

QSignup::QSignup(QWidget *parent) :
        QDialog(parent), ui(new Ui::QSignup) {
    ui->setupUi(this);
    ui->inID->setText(Manager::newID());
    ui->inID->setEnabled(false);
}

QSignup::~QSignup() {
    delete ui;
}

void QSignup::on_btnCreate_clicked() {
    User user;
    user.country = ui->inCountry->text();
    user.lastname = ui->inLastname->text();
    user.firstname = ui->inFirstname->text();
    user.userID = ui->inID->text();

    user.password = QString("%1").arg(QString(QCryptographicHash::hash(ui->inPassword->text().toUtf8(),QCryptographicHash::Sha1).toHex()));
    user.username = ui->inUsername->text();
    user.city = ui->inCity->text();
    user.email = ui->inEmail->text();
    user.phone = ui->inPhone->text();
    Manager::addUser(user);
    QMessageBox::warning(this,"Info","User wa added successfully");
    close();
}


