# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainWindow.ui'
##
## Created by: Qt User Interface Compiler version 6.8.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QComboBox, QHBoxLayout, QLabel,
    QLineEdit, QMainWindow, QPushButton, QSizePolicy,
    QStatusBar, QTextBrowser, QVBoxLayout, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(909, 461)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.horizontalLayout_2 = QHBoxLayout(self.centralwidget)
        self.horizontalLayout_2.setSpacing(0)
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.widget = QWidget(self.centralwidget)
        self.widget.setObjectName(u"widget")
        self.horizontalLayoutWidget_5 = QWidget(self.widget)
        self.horizontalLayoutWidget_5.setObjectName(u"horizontalLayoutWidget_5")
        self.horizontalLayoutWidget_5.setGeometry(QRect(10, 10, 521, 351))
        self.horizontalLayout_4 = QHBoxLayout(self.horizontalLayoutWidget_5)
        self.horizontalLayout_4.setObjectName(u"horizontalLayout_4")
        self.horizontalLayout_4.setContentsMargins(0, 0, 0, 0)
        self.VL_Settings = QVBoxLayout()
        self.VL_Settings.setObjectName(u"VL_Settings")
        self.label = QLabel(self.horizontalLayoutWidget_5)
        self.label.setObjectName(u"label")
        sizePolicy = QSizePolicy(QSizePolicy.Policy.Preferred, QSizePolicy.Policy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label.sizePolicy().hasHeightForWidth())
        self.label.setSizePolicy(sizePolicy)

        self.VL_Settings.addWidget(self.label)

        self.HL_IP = QHBoxLayout()
        self.HL_IP.setObjectName(u"HL_IP")
        self.IP_Octet_Input_1 = QLineEdit(self.horizontalLayoutWidget_5)
        self.IP_Octet_Input_1.setObjectName(u"IP_Octet_Input_1")

        self.HL_IP.addWidget(self.IP_Octet_Input_1)

        self.IP_Dot_1 = QLabel(self.horizontalLayoutWidget_5)
        self.IP_Dot_1.setObjectName(u"IP_Dot_1")
        sizePolicy.setHeightForWidth(self.IP_Dot_1.sizePolicy().hasHeightForWidth())
        self.IP_Dot_1.setSizePolicy(sizePolicy)

        self.HL_IP.addWidget(self.IP_Dot_1)

        self.IP_Octet_Input_2 = QLineEdit(self.horizontalLayoutWidget_5)
        self.IP_Octet_Input_2.setObjectName(u"IP_Octet_Input_2")

        self.HL_IP.addWidget(self.IP_Octet_Input_2)

        self.IP_Dot_2 = QLabel(self.horizontalLayoutWidget_5)
        self.IP_Dot_2.setObjectName(u"IP_Dot_2")
        sizePolicy.setHeightForWidth(self.IP_Dot_2.sizePolicy().hasHeightForWidth())
        self.IP_Dot_2.setSizePolicy(sizePolicy)

        self.HL_IP.addWidget(self.IP_Dot_2)

        self.IP_Octet_Input_3 = QLineEdit(self.horizontalLayoutWidget_5)
        self.IP_Octet_Input_3.setObjectName(u"IP_Octet_Input_3")

        self.HL_IP.addWidget(self.IP_Octet_Input_3)

        self.IP_Dot_3 = QLabel(self.horizontalLayoutWidget_5)
        self.IP_Dot_3.setObjectName(u"IP_Dot_3")
        sizePolicy.setHeightForWidth(self.IP_Dot_3.sizePolicy().hasHeightForWidth())
        self.IP_Dot_3.setSizePolicy(sizePolicy)

        self.HL_IP.addWidget(self.IP_Dot_3)

        self.IP_Octet_Input_4 = QLineEdit(self.horizontalLayoutWidget_5)
        self.IP_Octet_Input_4.setObjectName(u"IP_Octet_Input_4")

        self.HL_IP.addWidget(self.IP_Octet_Input_4)


        self.VL_Settings.addLayout(self.HL_IP)

        self.HL_Server_Port = QHBoxLayout()
        self.HL_Server_Port.setObjectName(u"HL_Server_Port")
        self.label_2 = QLabel(self.horizontalLayoutWidget_5)
        self.label_2.setObjectName(u"label_2")
        sizePolicy1 = QSizePolicy(QSizePolicy.Policy.Preferred, QSizePolicy.Policy.Preferred)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.label_2.sizePolicy().hasHeightForWidth())
        self.label_2.setSizePolicy(sizePolicy1)

        self.HL_Server_Port.addWidget(self.label_2)

        self.lineEdit = QLineEdit(self.horizontalLayoutWidget_5)
        self.lineEdit.setObjectName(u"lineEdit")

        self.HL_Server_Port.addWidget(self.lineEdit)


        self.VL_Settings.addLayout(self.HL_Server_Port)

        self.horizontalLayout_3 = QHBoxLayout()
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.btn_Clear_IP = QPushButton(self.horizontalLayoutWidget_5)
        self.btn_Clear_IP.setObjectName(u"btn_Clear_IP")

        self.horizontalLayout_3.addWidget(self.btn_Clear_IP)

        self.btn_Connect = QPushButton(self.horizontalLayoutWidget_5)
        self.btn_Connect.setObjectName(u"btn_Connect")

        self.horizontalLayout_3.addWidget(self.btn_Connect)


        self.VL_Settings.addLayout(self.horizontalLayout_3)

        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.label_3 = QLabel(self.horizontalLayoutWidget_5)
        self.label_3.setObjectName(u"label_3")

        self.horizontalLayout.addWidget(self.label_3)

        self.comboBox = QComboBox(self.horizontalLayoutWidget_5)
        self.comboBox.setObjectName(u"comboBox")

        self.horizontalLayout.addWidget(self.comboBox)

        self.pushButton = QPushButton(self.horizontalLayoutWidget_5)
        self.pushButton.setObjectName(u"pushButton")

        self.horizontalLayout.addWidget(self.pushButton)


        self.VL_Settings.addLayout(self.horizontalLayout)


        self.horizontalLayout_4.addLayout(self.VL_Settings)

        self.textBrowser = QTextBrowser(self.horizontalLayoutWidget_5)
        self.textBrowser.setObjectName(u"textBrowser")

        self.horizontalLayout_4.addWidget(self.textBrowser)


        self.horizontalLayout_2.addWidget(self.widget)

        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Host App for Controller || \u4e0a\u4f4d\u673a", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"Controller IP:", None))
        self.IP_Dot_1.setText(QCoreApplication.translate("MainWindow", u".", None))
        self.IP_Dot_2.setText(QCoreApplication.translate("MainWindow", u".", None))
        self.IP_Dot_3.setText(QCoreApplication.translate("MainWindow", u".", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"Server Port:", None))
        self.btn_Clear_IP.setText(QCoreApplication.translate("MainWindow", u"Clear", None))
        self.btn_Connect.setText(QCoreApplication.translate("MainWindow", u"Connect", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"Camera:", None))
        self.pushButton.setText(QCoreApplication.translate("MainWindow", u"Open", None))
    # retranslateUi

