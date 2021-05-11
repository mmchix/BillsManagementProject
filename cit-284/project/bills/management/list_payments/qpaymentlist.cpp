//
// Created by Mohamed MCHICH on 9/5/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QPaymentList.h" resolved

#include <QStandardItemModel>
#include <QMessageBox>
#include "qpaymentlist.h"
#include "ui_QPaymentList.h"
#include "../../models/manager/Manager.h"

QPaymentList::QPaymentList(QWidget *parent, QString creditID) :
        QDialog(parent), ui(new Ui::QPaymentList) {
    ui->setupUi(this);
    this->creditID = creditID;
    auto *model = new QStandardItemModel();
    model->setHorizontalHeaderLabels(QStringList({"Payment ID", "Amount", "Payment Date"}));
    ui->tablePayments->setModel(model);
    QList<QStandardItem*> rowData;
            foreach(Payment payment, Manager::getListPayment(creditID)){
            rowData.clear();
            rowData << new QStandardItem(payment.paymentId);
            rowData << new QStandardItem(QString("%1").arg(payment.paymentValue));
            rowData << new QStandardItem(payment.paymentDate.toString());
            model->appendRow(rowData);
        }
}

QPaymentList::~QPaymentList() {
    delete ui;
}

void QPaymentList::on_btnDeletePayment_clicked() {
    if(!ui->tablePayments->selectionModel()->hasSelection()){
        QMessageBox::warning(this,"Warning","You need to select a row first!");
        return;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Warning", "Do you really want to delete this payment ?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        int index = ui->tablePayments->selectionModel()->currentIndex().row();
        Manager::deletePayment(ui->tablePayments->model()->data(ui->tablePayments->model()->index(index,0)).toString());
        ui->tablePayments->model()->removeRow(index);
    }
}
