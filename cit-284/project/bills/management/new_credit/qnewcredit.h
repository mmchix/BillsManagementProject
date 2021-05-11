//
// Created by Mohamed MCHICH on 9/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_QNEWCREDIT_H
#define BILLSMANAGEMENTPROJECT_QNEWCREDIT_H

#include <QDialog>
#include "../../models/creditor/Creditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QNewCredit; }
QT_END_NAMESPACE

class QNewCredit : public QDialog {
Q_OBJECT

public:
    QNewCredit(QWidget *parent, Creditor creditor);

public:
    explicit QNewCredit(QWidget *parent = nullptr);

    ~QNewCredit() override;

private slots:
    void on_btnAddCredit_clicked();

private:
    Creditor creditor;
private:
    Ui::QNewCredit *ui;
};

#endif //BILLSMANAGEMENTPROJECT_QNEWCREDIT_H
