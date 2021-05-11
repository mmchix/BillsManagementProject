//
// Created by Mohamed MCHICH on 7/5/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QLogin.h" resolved

#include <QCryptographicHash>
#include "qlogin.h"
#include "ui_QLogin.h"
#include "../signup/qsignup.h"
#include "../../models/manager/Manager.h"
#include "../creditors/qcreditors.h"

QLogin::QLogin(QWidget *parent) :
        QDialog(parent), ui(new Ui::QLogin) {
    ui->setupUi(this);
}

QLogin::~QLogin() {
    delete ui;
}

void QLogin::on_btnSignup_clicked() {
    QSignup qSignup;
    qSignup.setModal(true);
    qSignup.exec();
}

void QLogin::on_btnLogin_clicked() {
    QString usernameOREmail = ui->inUsername->text();
    QString password = ui->inPassword->text();
    if(Manager::login(usernameOREmail, QString("%1").arg(QString(QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha1).toHex())))){
        close();
        QCreditors *qCreditors = new QCreditors(this);
        qCreditors->exec();
    }
}
