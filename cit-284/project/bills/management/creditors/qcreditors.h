//
// Created by Mohamed MCHICH on 8/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_QCREDITORS_H
#define BILLSMANAGEMENTPROJECT_QCREDITORS_H

#include <QDialog>
#include <QStandardItemModel>
#include "../../models/creditor/Creditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QCreditors; }
QT_END_NAMESPACE

class QCreditors : public QDialog {
Q_OBJECT

public:
    explicit QCreditors(QWidget *parent = nullptr);

    ~QCreditors() override;

private:
    Ui::QCreditors *ui;
    QStandardItemModel *model;

private slots:
    void on_btnNewCreditor_clicked();
    void on_btnLogout_clicked();
    void on_btnUpdateCreditor_clicked();
    void on_btnDeleteCreditor_clicked();
    void on_btnCreditList_clicked();
    void on_btnAddCredit_clicked();
    Creditor getSelectedRowAsCreditor();


};

#endif //BILLSMANAGEMENTPROJECT_QCREDITORS_H
