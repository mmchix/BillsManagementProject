//
// Created by Mohamed MCHICH on 8/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_CREDIT_H
#define BILLSMANAGEMENTPROJECT_CREDIT_H


#include <QDate>
#include "../payment/Payment.h"

class Credit {
public:
    QString creditID;
    QString creditorID;
    double creditValue;
    QDate dateStarts;
    QDate dateEnd;
    QList<Payment> payments;
};


#endif //BILLSMANAGEMENTPROJECT_CREDIT_H
