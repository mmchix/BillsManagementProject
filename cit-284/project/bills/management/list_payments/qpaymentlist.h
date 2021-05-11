//
// Created by Mohamed MCHICH on 9/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_QPAYMENTLIST_H
#define BILLSMANAGEMENTPROJECT_QPAYMENTLIST_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QPaymentList; }
QT_END_NAMESPACE

class QPaymentList : public QDialog {
Q_OBJECT

public:
    QString creditID;
public:
    explicit QPaymentList(QWidget *parent, QString creditID);

    ~QPaymentList() override;

private:
    Ui::QPaymentList *ui;
private slots:
    void on_btnDeletePayment_clicked();
};



#endif //BILLSMANAGEMENTPROJECT_QPAYMENTLIST_H
