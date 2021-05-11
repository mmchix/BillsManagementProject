//
// Created by Mohamed MCHICH on 8/5/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QCreditors.h" resolved


#include <QMessageBox>
#include "qcreditors.h"
#include "ui_QCreditors.h"
#include "../../models/manager/Manager.h"
#include "../new_creditor/newcreditor.h"
#include "../login/qlogin.h"
#include "../new_credit/qnewcredit.h"
#include "../list_credits/qcreditlist.h"

QCreditors::QCreditors(QWidget *parent) :
        QDialog(parent), ui(new Ui::QCreditors) {
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel();
    model->setHorizontalHeaderLabels(QStringList({"ID", "Firstname", "Lastname", "Email", "Phone", "Country", "City"}));
    ui->creditors_table->setModel(model);
    QList<QStandardItem*> rowData;
    foreach(Creditor creditor, Manager::getListOfCreditors(Manager::currentUser.userID)){
            rowData.clear();
            rowData << new QStandardItem(QString("%1").arg(creditor.num));
            rowData << new QStandardItem(creditor.firstname);
            rowData << new QStandardItem(creditor.lastname);
            rowData << new QStandardItem(creditor.email);
            rowData << new QStandardItem(creditor.phone);
            rowData << new QStandardItem(creditor.country);
            rowData << new QStandardItem(creditor.city);
            model->appendRow(rowData);
        }

}

QCreditors::~QCreditors() {
    delete ui;
}

void QCreditors::on_btnNewCreditor_clicked() {
     QModelIndexList row = ui->creditors_table->selectionModel()->selectedRows();
    close();
    NewCreditor *qNewCreditor = new NewCreditor(this);
    qNewCreditor->exec();
}

void QCreditors::on_btnLogout_clicked() {
    close();
    QLogin *qLogin = new QLogin(this);
    qLogin->exec();
}

void QCreditors::on_btnUpdateCreditor_clicked() {
    if(!ui->creditors_table->selectionModel()->hasSelection()){
        QMessageBox::warning(this,"Warning","You need to select a row first!");
        return;
    }
    close();
    NewCreditor *qUpdateCreditor = new NewCreditor(this,getSelectedRowAsCreditor());
    qUpdateCreditor->exec();
}

void QCreditors::on_btnDeleteCreditor_clicked() {
    if(!ui->creditors_table->selectionModel()->hasSelection()){
        QMessageBox::warning(this,"Warning","You need to select a row first!");
        return;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Warning", "Do you really want to delete this creditor ?\n If so, all it's data including credits will be deleted also!",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        int index = ui->creditors_table->selectionModel()->currentIndex().row();
        Manager::deleteCreditor(ui->creditors_table->model()->data(ui->creditors_table->model()->index(index,0)).toString());
        ui->creditors_table->model()->removeRow(index);
        //QApplication::quit();
    }
}

void QCreditors::on_btnCreditList_clicked() {
    if(!ui->creditors_table->selectionModel()->hasSelection()){
        QMessageBox::warning(this,"Warning","You need to select a row first!");
        return;
    }
    QCreditList *qCreditList = new QCreditList(this,getSelectedRowAsCreditor());
    qCreditList->setModal(true);
    qCreditList->exec();
}

void QCreditors::on_btnAddCredit_clicked(){
    if(!ui->creditors_table->selectionModel()->hasSelection()){
        QMessageBox::warning(this,"Warning","You need to select a row first!");
        return;
    }
    QNewCredit *qNewCredit = new QNewCredit(this,getSelectedRowAsCreditor());
    qNewCredit->setModal(true);
    qNewCredit->exec();
}

Creditor QCreditors::getSelectedRowAsCreditor() {
    int index = ui->creditors_table->selectionModel()->currentIndex().row();
    return Manager::getCreditor(ui->creditors_table->model()->data(ui->creditors_table->model()->index(index,0)).toString());
}


