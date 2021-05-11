cmake_minimum_required(VERSION 3.17)
project(BillsManagementProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(${PROJECT_NAME}
        main.cpp
        cit-284/project/bills/management/signup/qsignup.cpp
        cit-284/project/bills/management/signup/qsignup.h
        cit-284/project/bills/management/signup/qsignup.ui
        cit-284/project/bills/management/signup/qsignup.cpp
        cit-284/project/bills/management/signup/qsignup.h
        cit-284/project/bills/management/signup/qsignup.ui
        cit-284/project/bills/management/login/qlogin.cpp
        cit-284/project/bills/management/login/qlogin.h
        cit-284/project/bills/management/login/qlogin.ui
        cit-284/project/bills/models/credit/Credit.cpp
        cit-284/project/bills/models/credit/Credit.h
        cit-284/project/bills/models/creditor/Creditor.cpp
        cit-284/project/bills/models/creditor/Creditor.h
        cit-284/project/bills/models/payment/Payment.cpp
        cit-284/project/bills/models/payment/Payment.h
        cit-284/project/bills/models/user/User.cpp
        cit-284/project/bills/models/user/User.h
        cit-284/project/bills/models/manager/Manager.cpp
        cit-284/project/bills/models/manager/Manager.h
        cit-284/project/bills/management/creditors/qcreditors.cpp
        cit-284/project/bills/management/creditors/qcreditors.h
        cit-284/project/bills/management/creditors/qcreditors.ui
        cit-284/project/bills/management/new_creditor/newcreditor.cpp
        cit-284/project/bills/management/new_creditor/newcreditor.h
        cit-284/project/bills/management/new_creditor/newcreditor.ui
        cit-284/project/bills/management/new_credit/qnewcredit.cpp
        cit-284/project/bills/management/new_credit/qnewcredit.h
        cit-284/project/bills/management/new_credit/qnewcredit.ui
        cit-284/project/bills/management/list_credits/qcreditlist.cpp
        cit-284/project/bills/management/list_credits/qcreditlist.h
        cit-284/project/bills/management/list_credits/qcreditlist.ui
        cit-284/project/bills/management/new_payment/qnewpayment.cpp
        cit-284/project/bills/management/new_payment/qnewpayment.h
        cit-284/project/bills/management/new_payment/qnewpayment.ui
        cit-284/project/bills/management/list_payments/qpaymentlist.cpp
        cit-284/project/bills/management/list_payments/qpaymentlist.h
        cit-284/project/bills/management/list_payments/qpaymentlist.ui)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
