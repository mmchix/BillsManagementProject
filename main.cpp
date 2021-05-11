#include <QApplication>
#include <QPushButton>
#include "cit-284/project/bills/management/login/qlogin.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QLogin qLogin;
    qLogin.exec();
}
