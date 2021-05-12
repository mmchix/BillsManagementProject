//
// Created by Mohamed MCHICH on 8/5/2021.
//

#ifndef BILLSMANAGEMENTPROJECT_MANAGER_H
#define BILLSMANAGEMENTPROJECT_MANAGER_H


#include "../user/User.h"
#include <QUuid>
#include <QRegularExpression>

class Manager {
public:
    static User currentUser;


public:
    static bool login(QString usernameORemail, QString password);
    static QList<Payment> getListPayment(QString creditID);
    static QList<Credit> getCredits(QString creditorID);
    static QList<Creditor> getListOfCreditors(QString userID);
    static void addUser(User user);
    static void addCreditor(Creditor creditor);
    static void updateCreditor(Creditor creditor);
    static void addCredit(Credit credit);
    static QList<Creditor> getListOfCreditors();
    static QList<Credit> getCredits();
    static void deleteCreditor(QString id);
    static Creditor getCreditor(QString idCreditor);
    static void deleteCredit(QString idCredit);
    static void addPayment(Payment payment);
    static void deletePayment(QString paymentID);
    static QList<Payment> getListPayment();

    static QString newID();
};


#endif //BILLSMANAGEMENTPROJECT_MANAGER_H
