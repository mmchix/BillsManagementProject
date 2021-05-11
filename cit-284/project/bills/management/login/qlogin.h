//
// Created by Mohamed MCHICH on 7/5/2021.
//

#ifndef BILLMANAGER_QLOGIN_H
#define BILLMANAGER_QLOGIN_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QLogin; }
QT_END_NAMESPACE

class QLogin : public QDialog {
Q_OBJECT

public:
    explicit QLogin(QWidget *parent = nullptr);
    ~QLogin() override;

private slots:
    void on_btnSignup_clicked();
    void on_btnLogin_clicked();


private:
    Ui::QLogin *ui;
};

#endif //BILLMANAGER_QLOGIN_H
