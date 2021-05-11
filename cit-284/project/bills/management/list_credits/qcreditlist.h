//
// Created by Mohamed MCHICH on 9/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_QCREDITLIST_H
#define BILLSMANAGEMENTPROJECT_QCREDITLIST_H

#include <QDialog>
#include "../../models/creditor/Creditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QCreditList; }
QT_END_NAMESPACE

class QCreditList : public QDialog {
Q_OBJECT

public:
    explicit QCreditList(QWidget *parent = nullptr);
public:
    QCreditList(QWidget *parent,Creditor creditor);

    ~QCreditList() override;

public slots:
    void on_btnDeleteCredit_clicked();
    void on_btnAddPayment_clicked();
    void on_btnPaymentList_clicked();

private:
    Ui::QCreditList *ui;
};

#endif //BILLSMANAGEMENTPROJECT_QCREDITLIST_H
