//
// Created by Mohamed MCHICH on 9/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_QNEWPAYMENT_H
#define BILLSMANAGEMENTPROJECT_QNEWPAYMENT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QNewPayment; }
QT_END_NAMESPACE

class QNewPayment : public QDialog {
Q_OBJECT

public:
     QNewPayment(QWidget *parent, QString creditID);

public:
    QString creditID;
    QString paymentID;
public:
    explicit QNewPayment(QWidget *parent = nullptr);

    ~QNewPayment() override;

private:
    Ui::QNewPayment *ui;

private slots:
    void on_btnAddPayment_clicked();
};

#endif //BILLSMANAGEMENTPROJECT_QNEWPAYMENT_H
