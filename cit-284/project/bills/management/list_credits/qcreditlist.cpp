//
// Created by Mohamed MCHICH on 9/5/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QCreditList.h" resolved

#include <QStandardItemModel>
#include <QMessageBox>
#include "qcreditlist.h"
#include "ui_QCreditList.h"
#include "../../models/manager/Manager.h"
#include "../new_payment/qnewpayment.h"
#include "../list_payments/qpaymentlist.h"

QCreditList::QCreditList(QWidget *parent,Creditor creditor) :
        QDialog(parent), ui(new Ui::QCreditList) {
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel();
    model->setHorizontalHeaderLabels(QStringList({"CreditID", "Amount", "Date Starts", "Date Ends"}));
    ui->tableCredits->setModel(model);
    QList<QStandardItem*> rowData;
            foreach(Credit credit, Manager::getCredits(creditor.num)){
            rowData.clear();
            rowData << new QStandardItem(QString("%1").arg(credit.creditID));
            rowData << new QStandardItem(QString("%1").arg(credit.creditValue));
            rowData << new QStandardItem(credit.dateStarts.toString());
            rowData << new QStandardItem(credit.dateEnd.toString());
            model->appendRow(rowData);
        }
}

QCreditList::~QCreditList() {
    delete ui;
}

void QCreditList::on_btnDeleteCredit_clicked() {
    if(!ui->tableCredits->selectionModel()->hasSelection()){
        QMessageBox::warning(this,"Warning","You need to select a row first!");
        return;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Warning", "Do you really want to delete this credit ?\n If so, all it's data including payments will be deleted also!",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        int index = ui->tableCredits->selectionModel()->currentIndex().row();
        Manager::deleteCredit(ui->tableCredits->model()->data(ui->tableCredits->model()->index(index,0)).toString());
        ui->tableCredits->model()->removeRow(index);
    }
}

void QCreditList::on_btnAddPayment_clicked() {
    int index = ui->tableCredits->selectionModel()->currentIndex().row();
    QNewPayment *qNewPayment = new QNewPayment(this,ui->tableCredits->model()->data(ui->tableCredits->model()->index(index,0)).toString());
    qNewPayment->setModal(true);
    qNewPayment->exec();
}

void QCreditList::on_btnPaymentList_clicked() {
    int index = ui->tableCredits->selectionModel()->currentIndex().row();
    QPaymentList *qPaymentList = new QPaymentList(this,ui->tableCredits->model()->data(ui->tableCredits->model()->index(index,0)).toString());
    qPaymentList->setModal(true);
    qPaymentList->exec();
}
