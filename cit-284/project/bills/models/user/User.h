//
// Created by Mohamed MCHICH on 8/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_USER_H
#define BILLSMANAGEMENTPROJECT_USER_H


#include <QString>
#include "../creditor/Creditor.h"

class User {

public:
    User();

public:
    QString username;//0
    QString email;//1
    QString password;//2
    QString userID;//3
    QString firstname;//4
    QString lastname;//5
    QString phone;//6
    QString country;//7
    QString city;//8
    QList<Creditor> creditors;


};


#endif //BILLSMANAGEMENTPROJECT_USER_H
