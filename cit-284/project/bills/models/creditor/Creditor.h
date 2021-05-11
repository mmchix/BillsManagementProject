//
// Created by Mohamed MCHICH on 8/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_CREDITOR_H
#define BILLSMANAGEMENTPROJECT_CREDITOR_H


#include <QString>
#include "../credit/Credit.h"

class Creditor {
public:
    QString num;
    QString userID;
    QString firstname;
    QString lastname;
    QString phone;
    QString email;
    QString country;
    QString city;
    QList<Credit> credits;

};


#endif //BILLSMANAGEMENTPROJECT_CREDITOR_H
