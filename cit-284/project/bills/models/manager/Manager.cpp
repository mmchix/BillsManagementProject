//
// Created by Mohamed MCHICH on 8/5/2021.
//

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "Manager.h"
static const QString CREDITORS_DATA= "D:\\BillsManagementProject\\data\\creditors.txt";
static const   QString CREDITS_DATA= "D:\\BillsManagementProject\\data\\credits.txt";
static const QString PAYMENTS_DATA= "D:\\BillsManagementProject\\data\\payments.txt";
static const QString USERS_DATA= "D:\\BillsManagementProject\\data\\users.txt";
User Manager::currentUser;


bool Manager::login(QString usernameORemail, QString password) {
    QFile usersFile (USERS_DATA);
    usersFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QStringList users_data=QString(usersFile.readAll()).split('\n'); // take line by line
    users_data.removeAll("");
    QStringList user_data;
            foreach(QString users,users_data){
            user_data = users.split('#');
            if(user_data.size()<3) continue;
            if((user_data.at(0) == usernameORemail || user_data.at(1) == usernameORemail) && user_data.at(2) == password){
                currentUser.username = user_data.at(0);
                currentUser.email = user_data.at(1);
                currentUser.password = user_data.at(2);
                currentUser.userID = user_data.at(3);
                currentUser.firstname = user_data.at(4);
                currentUser.lastname = user_data.at(5);
                currentUser.phone = user_data.at(6);
                currentUser.country = user_data.at(7);
                currentUser.city = user_data.at(8);
                currentUser.creditors = getListOfCreditors(currentUser.userID);
                usersFile.close();
                return true;
            }
        }
    usersFile.close();
    return false;
}

//from file
QList <Creditor> Manager::getListOfCreditors(QString userID) {
    QList<Creditor> creditors;
    QFile creditorFile(CREDITORS_DATA);
    creditorFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QStringList creditors_data=QString(creditorFile.readAll()).split('\n'); // take line by line
    creditors_data.removeAll("");

            foreach(QString creditor,creditors_data){

            Creditor temporary_creditor;
            QStringList creditor_data=creditor.split('#');
            if(creditor_data.at(1) != userID) continue;
            temporary_creditor.num = creditor_data.at(0);
            temporary_creditor.firstname = creditor_data.at(2);
            temporary_creditor.lastname = creditor_data.at(3);
            temporary_creditor.phone = creditor_data.at(4);
            temporary_creditor.email = creditor_data.at(5);
            temporary_creditor.country = creditor_data.at(6);
            temporary_creditor.city = creditor_data.at(7);
            QList<Credit> credits;
            temporary_creditor.credits = getCredits(temporary_creditor.num);
            creditors.append(temporary_creditor);
        }
    creditorFile.close();
    return creditors;
}

//from file
Creditor Manager::getCreditor(QString idCreditor) {
    QFile creditorFile(CREDITORS_DATA);
    creditorFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QStringList creditors_data=QString(creditorFile.readAll()).split('\n'); // take line by line
    creditors_data.removeAll("");
    Creditor temporary_creditor;
            foreach(QString creditor,creditors_data){
            QStringList creditor_data=creditor.split('#');
            if(creditor_data.at(0) == idCreditor) {
                temporary_creditor.num = creditor_data.at(0);
                temporary_creditor.firstname = creditor_data.at(2);
                temporary_creditor.lastname = creditor_data.at(3);
                temporary_creditor.phone = creditor_data.at(4);
                temporary_creditor.email = creditor_data.at(5);
                temporary_creditor.country = creditor_data.at(6);
                temporary_creditor.city = creditor_data.at(7);
                QList<Credit> credits;
                temporary_creditor.credits = getCredits(temporary_creditor.num);
                break;
            }
        }
    creditorFile.close();
    return temporary_creditor;
}

QList <Creditor> Manager::getListOfCreditors() {
    QList<Creditor> creditors;
    QFile creditorFile(CREDITORS_DATA);
    creditorFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QStringList creditors_data=QString(creditorFile.readAll()).split('\n'); // take line by line
    creditors_data.removeAll("");

            foreach(QString creditor,creditors_data){

            Creditor temporary_creditor;
            QStringList creditor_data=creditor.split('#');
            temporary_creditor.num = creditor_data.at(0);
            temporary_creditor.userID = creditor_data.at(1);
            temporary_creditor.firstname = creditor_data.at(2);
            temporary_creditor.lastname = creditor_data.at(3);
            temporary_creditor.phone = creditor_data.at(4);
            temporary_creditor.email = creditor_data.at(5);
            temporary_creditor.country = creditor_data.at(6);
            temporary_creditor.city = creditor_data.at(7);
            QList<Credit> credits;
            temporary_creditor.credits = getCredits(temporary_creditor.num);
            creditors.append(temporary_creditor);
        }
    creditorFile.close();
    return creditors;
}
//from file
QList<Payment> Manager::getListPayment(QString creditID) {
    QList<Payment> payments;
    QFile paymentFile (PAYMENTS_DATA);
    paymentFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QStringList payments_data=QString(paymentFile.readAll()).split('\n'); // take line by line
    payments_data.removeAll("");

            foreach(QString payment,payments_data){
            Payment temporary_payment;
            QStringList credit_data = payment.split('#');
            if(credit_data.at(1) != creditID) continue;
            temporary_payment.paymentId = credit_data.at(0);
            temporary_payment.creditID = credit_data.at(1);
            temporary_payment.paymentValue = credit_data.at(2).toDouble();
            temporary_payment.paymentDate = QDate().fromString(credit_data.at(3));
            payments.append(temporary_payment);
        }
    paymentFile.close();
    return payments;
}

QList<Payment> Manager::getListPayment() {
    QList<Payment> payments;
    QFile paymentFile (PAYMENTS_DATA);
    paymentFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QStringList payments_data=QString(paymentFile.readAll()).split('\n'); // take line by line
    payments_data.removeAll("");

            foreach(QString payment,payments_data){
            Payment temporary_payment;
            QStringList credit_data = payment.split('#');
            temporary_payment.paymentId = credit_data.at(0);
            temporary_payment.creditID = credit_data.at(1);
            temporary_payment.paymentValue = credit_data.at(2).toDouble();
            temporary_payment.paymentDate = QDate().fromString(credit_data.at(3));
            payments.append(temporary_payment);
        }
    paymentFile.close();
    return payments;
}
//from file
QList<Credit> Manager::getCredits(QString creditorID) {
    QList<Credit> credits;
    QFile creditFile (CREDITS_DATA);
    creditFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QStringList credits_data=QString(creditFile.readAll()).split('\n'); // take line by line
    credits_data.removeAll("");

            foreach(QString credit,credits_data){

            Credit temporary_credit;
            QStringList credit_data=credit.split('#');
            if(credit_data.at(1) != creditorID) continue;
            temporary_credit.creditID = credit_data.at(0);
            temporary_credit.creditorID = credit_data.at(1);
            temporary_credit.creditValue = credit_data.at(2).toDouble();
            temporary_credit.dateStarts = QDate().fromString(credit_data.at(3));
            temporary_credit.dateEnd = QDate().fromString(credit_data.at(4));
            temporary_credit.payments = getListPayment(temporary_credit.creditID);
            credits.append(temporary_credit);
        }
    creditFile.close();
    return credits;
}
//from file
QList<Credit> Manager::getCredits() {
    QList<Credit> credits;
    QFile creditFile (CREDITS_DATA);
    creditFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QStringList credits_data=QString(creditFile.readAll()).split('\n'); // take line by line
    credits_data.removeAll("");

            foreach(QString credit,credits_data){

            Credit temporary_credit;
            QStringList credit_data=credit.split('#');
            temporary_credit.creditID = credit_data.at(0);
            temporary_credit.creditorID = credit_data.at(1);
            temporary_credit.creditValue = credit_data.at(2).toDouble();
            temporary_credit.dateStarts = QDate().fromString(credit_data.at(3));
            temporary_credit.dateEnd = QDate().fromString(credit_data.at(4));
            temporary_credit.payments = getListPayment(temporary_credit.creditID);
            credits.append(temporary_credit);
        }
    creditFile.close();
    return credits;
}
//to file
void Manager::addUser(User user) {
    QFile userFile (USERS_DATA);
    userFile.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream out(&userFile);
    out << user.username << "#";
    out << user.email<< "#";
    out << user.password << "#";
    out << user.userID << "#";
    out << user.firstname << "#";
    out << user.lastname << "#";
    out << user.phone << "#";
    out << user.country << "#";
    out << user.city << "\n";

    userFile.permissions();
    userFile.flush();
    userFile.close();
}
//to file
void Manager::addCreditor(Creditor creditor){
    QFile creditorFile (CREDITORS_DATA);
    creditorFile.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream out(&creditorFile);
    out << creditor.num << "#";
    out << creditor.userID << "#";
    out << creditor.firstname << "#";
    out << creditor.lastname << "#";
    out << creditor.phone << "#";
    out << creditor.email<< "#";
    out << creditor.country << "#";
    out << creditor.city << "\n";
    creditorFile.permissions();
    creditorFile.flush();
    creditorFile.close();
}
//from file
void Manager::updateCreditor(Creditor creditor) {
    QList<Creditor> creditors = getListOfCreditors();
    QFile creditorFile (CREDITORS_DATA);
    creditorFile.open(QIODevice::ReadWrite | QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&creditorFile);
    foreach(Creditor c, creditors){
        if(creditor.num == c.num) {
            out << creditor.num << "#";
            out << creditor.userID << "#";
            out << creditor.firstname << "#";
            out << creditor.lastname << "#";
            out << creditor.phone << "#";
            out << creditor.email << "#";
            out << creditor.country << "#";
            out << creditor.city << "\n";
        }else{
            out << c.num << "#";
            out << c.userID << "#";
            out << c.firstname << "#";
            out << c.lastname << "#";
            out << c.phone << "#";
            out << c.email << "#";
            out << c.country << "#";
            out << c.city << "\n";
        }
    }

    creditorFile.permissions();
    creditorFile.flush();
    creditorFile.close();
}
//to file
void Manager::addCredit(Credit credit) {
    QList<Credit> credits = getCredits();
    QFile creditorFile (CREDITS_DATA);
    creditorFile.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream out(&creditorFile);
    out << credit.creditID << "#";
    out << credit.creditorID << "#";
    out << credit.creditValue << "#";
    out << credit.dateStarts.toString() << "#";
    out << credit.dateEnd.toString() << "\n";
    creditorFile.permissions();
    creditorFile.flush();
    creditorFile.close();
}

void Manager::deleteCredit(QString idCredit) {
    QList<Credit> credits = getCredits();
    QFile creditsFile (CREDITS_DATA);
    creditsFile.open(QIODevice::ReadWrite | QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&creditsFile);
            foreach(Credit c, credits){
            if(c.creditID == idCredit) {
                continue;
            }else{
                out << c.creditID << "#";
                out << c.creditorID << "#";
                out << QString("%1").arg(c.creditValue) << "#";
                out << c.dateStarts.toString() << "#";
                out << c.dateEnd.toString() << "\n";
            }
        }

    creditsFile.permissions();
    creditsFile.flush();
    creditsFile.close();
}

//from file
void Manager::deleteCreditor(QString id) {
    QList<Creditor> creditors = getListOfCreditors();
    QFile creditorFile (CREDITORS_DATA);
    creditorFile.open(QIODevice::ReadWrite | QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&creditorFile);
            foreach(Creditor c, creditors){
                if(c.num == id) {
                    continue;
                }else{
                    out << c.num << "#";
                    out << c.userID << "#";
                    out << c.firstname << "#";
                    out << c.lastname << "#";
                    out << c.phone << "#";
                    out << c.email << "#";
                    out << c.country << "#";
                    out << c.city << "\n";
                }
        }

    creditorFile.permissions();
    creditorFile.flush();
    creditorFile.close();
}

void Manager::addPayment(Payment payment) {
    QFile paymentFile (PAYMENTS_DATA);
    paymentFile.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream out(&paymentFile);
    out << payment.paymentId << "#";
    out << payment.creditID << "#";
    out << payment.paymentValue << "#";
    out << payment.paymentDate.toString() << "\n";
    paymentFile.permissions();
    paymentFile.flush();
    paymentFile.close();
}

void Manager::deletePayment(QString paymentID) {
    QList<Payment> payments = getListPayment();
    QFile paymentsFile (PAYMENTS_DATA);
    paymentsFile.open(QIODevice::ReadWrite | QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&paymentsFile);
            foreach(Payment p, payments){
            if(p.paymentId == paymentID) {
                continue;
            }else{
                out << p.paymentId << "#";
                out << p.creditID << "#";
                out << QString("%1").arg(p.paymentValue) << "#";
                out << p.paymentDate.toString() << "\n";
            }
        }

    paymentsFile.permissions();
    paymentsFile.flush();
    paymentsFile.close();

}

QString Manager::newID() {
    QString id = QUuid::createUuid().toString();
    id.remove(QRegularExpression("{|}|-"));
    return id;
}





