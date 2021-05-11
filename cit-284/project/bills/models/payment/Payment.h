//
// Created by Mohamed MCHICH on 8/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_PAYMENT_H
#define BILLSMANAGEMENTPROJECT_PAYMENT_H


#include <QDate>

class Payment {
public:
    QString paymentId;
    QString creditID;
    double paymentValue;
    QDate paymentDate;
};


#endif //BILLSMANAGEMENTPROJECT_PAYMENT_H
