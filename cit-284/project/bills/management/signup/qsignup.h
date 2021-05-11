//
// Created by Mohamed MCHICH on 7/5/2021.
//

#ifndef BILLMANAGER_QSIGNUP_H
#define BILLMANAGER_QSIGNUP_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QSignup; }
QT_END_NAMESPACE

class QSignup : public QDialog {
Q_OBJECT

public:
    explicit QSignup(QWidget *parent = nullptr);

    ~QSignup() override;

private slots:
    void on_btnCreate_clicked();


private:
    Ui::QSignup *ui;
};

#endif //BILLMANAGER_QSIGNUP_H
