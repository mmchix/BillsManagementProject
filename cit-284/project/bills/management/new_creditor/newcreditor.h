//
// Created by Mohamed MCHICH on 8/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_NEWCREDITOR_H
#define BILLSMANAGEMENTPROJECT_NEWCREDITOR_H

#include <QDialog>
#include "../../models/creditor/Creditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NewCreditor; }
QT_END_NAMESPACE

class NewCreditor : public QDialog {
Q_OBJECT
public:
    NewCreditor(QWidget *parent, Creditor creditor);

public:
    Creditor creditor;
    bool update = false;

public:
    explicit NewCreditor(QWidget *parent = nullptr);

    ~NewCreditor() override;
private slots:
    void on_btnNewCreditor_clicked();
private:
    Ui::NewCreditor *ui;
};

#endif //BILLSMANAGEMENTPROJECT_NEWCREDITOR_H
