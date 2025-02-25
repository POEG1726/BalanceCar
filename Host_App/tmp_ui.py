# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'tmp.ui'
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
from PySide6.QtWidgets import (QApplication, QCheckBox, QComboBox, QFrame,
    QGridLayout, QHBoxLayout, QLabel, QLineEdit,
    QMainWindow, QMenuBar, QPlainTextEdit, QPushButton,
    QSizePolicy, QSpacerItem, QStatusBar, QVBoxLayout,
    QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(645, 425)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.horizontalLayout_2 = QHBoxLayout(self.centralwidget)
        self.horizontalLayout_2.setSpacing(0)
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setSpacing(0)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.horizontalLayout.setContentsMargins(-1, -1, 5, -1)
        self.verticalLayout = QVBoxLayout()
        self.verticalLayout.setSpacing(5)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(5, 5, 5, 5)
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")

        self.verticalLayout.addWidget(self.label)

        self.rcvTextBox = QPlainTextEdit(self.centralwidget)
        self.rcvTextBox.setObjectName(u"rcvTextBox")
        self.rcvTextBox.setReadOnly(True)

        self.verticalLayout.addWidget(self.rcvTextBox)

        self.label_2 = QLabel(self.centralwidget)
        self.label_2.setObjectName(u"label_2")

        self.verticalLayout.addWidget(self.label_2)

        self.sendTextBox = QPlainTextEdit(self.centralwidget)
        self.sendTextBox.setObjectName(u"sendTextBox")
        self.sendTextBox.setReadOnly(True)

        self.verticalLayout.addWidget(self.sendTextBox)

        self.line_2 = QFrame(self.centralwidget)
        self.line_2.setObjectName(u"line_2")
        self.line_2.setFrameShape(QFrame.Shape.HLine)
        self.line_2.setFrameShadow(QFrame.Shadow.Sunken)

        self.verticalLayout.addWidget(self.line_2)

        self.horizontalLayout_3 = QHBoxLayout()
        self.horizontalLayout_3.setSpacing(5)
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.horizontalLayout_3.setContentsMargins(-1, 0, -1, -1)
        self.ckBxHex = QCheckBox(self.centralwidget)
        self.ckBxHex.setObjectName(u"ckBxHex")

        self.horizontalLayout_3.addWidget(self.ckBxHex)

        self.lineSendText = QLineEdit(self.centralwidget)
        self.lineSendText.setObjectName(u"lineSendText")
        self.lineSendText.setEnabled(False)

        self.horizontalLayout_3.addWidget(self.lineSendText)

        self.btnSendData = QPushButton(self.centralwidget)
        self.btnSendData.setObjectName(u"btnSendData")
        self.btnSendData.setEnabled(False)
        sizePolicy = QSizePolicy(QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.btnSendData.sizePolicy().hasHeightForWidth())
        self.btnSendData.setSizePolicy(sizePolicy)
        self.btnSendData.setMaximumSize(QSize(50, 16777215))

        self.horizontalLayout_3.addWidget(self.btnSendData)

        self.btnClearTextBox = QPushButton(self.centralwidget)
        self.btnClearTextBox.setObjectName(u"btnClearTextBox")
        self.btnClearTextBox.setEnabled(True)
        self.btnClearTextBox.setMaximumSize(QSize(50, 16777215))

        self.horizontalLayout_3.addWidget(self.btnClearTextBox)


        self.verticalLayout.addLayout(self.horizontalLayout_3)


        self.horizontalLayout.addLayout(self.verticalLayout)

        self.line_3 = QFrame(self.centralwidget)
        self.line_3.setObjectName(u"line_3")
        self.line_3.setFrameShape(QFrame.Shape.VLine)
        self.line_3.setFrameShadow(QFrame.Shadow.Sunken)

        self.horizontalLayout.addWidget(self.line_3)

        self.widget = QWidget(self.centralwidget)
        self.widget.setObjectName(u"widget")
        self.widget.setMinimumSize(QSize(270, 0))
        self.widget.setMaximumSize(QSize(270, 16777215))
        self.verticalLayout_2 = QVBoxLayout(self.widget)
        self.verticalLayout_2.setSpacing(5)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.widget_2 = QWidget(self.widget)
        self.widget_2.setObjectName(u"widget_2")
        self.widget_2.setMinimumSize(QSize(0, 270))
        self.widget_2.setMaximumSize(QSize(270, 16777215))
        self.verticalLayout_3 = QVBoxLayout(self.widget_2)
        self.verticalLayout_3.setSpacing(5)
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.verticalLayout_3.setContentsMargins(5, 5, 0, 5)
        self.label_5 = QLabel(self.widget_2)
        self.label_5.setObjectName(u"label_5")

        self.verticalLayout_3.addWidget(self.label_5)

        self.byteDataTextBox = QPlainTextEdit(self.widget_2)
        self.byteDataTextBox.setObjectName(u"byteDataTextBox")
        self.byteDataTextBox.setReadOnly(True)

        self.verticalLayout_3.addWidget(self.byteDataTextBox)

        self.gridLayout_2 = QGridLayout()
        self.gridLayout_2.setSpacing(5)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.gridLayout_2.setContentsMargins(0, 5, -1, 5)
        self.btnClearByteData = QPushButton(self.widget_2)
        self.btnClearByteData.setObjectName(u"btnClearByteData")
        self.btnClearByteData.setMinimumSize(QSize(50, 24))
        self.btnClearByteData.setMaximumSize(QSize(50, 24))

        self.gridLayout_2.addWidget(self.btnClearByteData, 0, 1, 1, 1)

        self.btnShowByteData = QPushButton(self.widget_2)
        self.btnShowByteData.setObjectName(u"btnShowByteData")
        self.btnShowByteData.setMinimumSize(QSize(50, 24))
        self.btnShowByteData.setMaximumSize(QSize(50, 24))

        self.gridLayout_2.addWidget(self.btnShowByteData, 0, 0, 1, 1)

        self.btnSaveData = QPushButton(self.widget_2)
        self.btnSaveData.setObjectName(u"btnSaveData")
        self.btnSaveData.setMinimumSize(QSize(50, 24))
        self.btnSaveData.setMaximumSize(QSize(50, 24))

        self.gridLayout_2.addWidget(self.btnSaveData, 0, 2, 1, 1)

        self.btnOpenData = QPushButton(self.widget_2)
        self.btnOpenData.setObjectName(u"btnOpenData")
        self.btnOpenData.setMinimumSize(QSize(50, 24))
        self.btnOpenData.setMaximumSize(QSize(50, 24))

        self.gridLayout_2.addWidget(self.btnOpenData, 0, 3, 1, 1)


        self.verticalLayout_3.addLayout(self.gridLayout_2)

        self.verticalSpacer_2 = QSpacerItem(20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum)

        self.verticalLayout_3.addItem(self.verticalSpacer_2)

        self.gridLayout = QGridLayout()
        self.gridLayout.setSpacing(5)
        self.gridLayout.setObjectName(u"gridLayout")
        self.gridLayout.setContentsMargins(0, -1, 0, -1)
        self.label_4 = QLabel(self.widget_2)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.label_4, 1, 0, 1, 1)

        self.lblIP = QLabel(self.widget_2)
        self.lblIP.setObjectName(u"lblIP")
        self.lblIP.setScaledContents(False)
        self.lblIP.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.lblIP, 3, 0, 1, 1)

        self.label_3 = QLabel(self.widget_2)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.label_3, 0, 0, 1, 1)

        self.btnConnect = QPushButton(self.widget_2)
        self.btnConnect.setObjectName(u"btnConnect")
        sizePolicy1 = QSizePolicy(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Fixed)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.btnConnect.sizePolicy().hasHeightForWidth())
        self.btnConnect.setSizePolicy(sizePolicy1)
        self.btnConnect.setMinimumSize(QSize(50, 24))
        self.btnConnect.setMaximumSize(QSize(50, 24))

        self.gridLayout.addWidget(self.btnConnect, 6, 0, 1, 1)

        self.lblCOM = QLabel(self.widget_2)
        self.lblCOM.setObjectName(u"lblCOM")
        self.lblCOM.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.lblCOM, 4, 0, 1, 1)

        self.btn2 = QPushButton(self.widget_2)
        self.btn2.setObjectName(u"btn2")
        self.btn2.setMinimumSize(QSize(50, 24))
        self.btn2.setMaximumSize(QSize(50, 24))

        self.gridLayout.addWidget(self.btn2, 6, 3, 1, 1)

        self.comboRoleType = QComboBox(self.widget_2)
        self.comboRoleType.addItem("")
        self.comboRoleType.addItem("")
        self.comboRoleType.setObjectName(u"comboRoleType")
        self.comboRoleType.setLayoutDirection(Qt.LeftToRight)

        self.gridLayout.addWidget(self.comboRoleType, 0, 1, 1, 3)

        self.comboMsgType = QComboBox(self.widget_2)
        self.comboMsgType.addItem("")
        self.comboMsgType.addItem("")
        self.comboMsgType.addItem("")
        self.comboMsgType.setObjectName(u"comboMsgType")

        self.gridLayout.addWidget(self.comboMsgType, 1, 1, 1, 3)

        self.lineIP = QLineEdit(self.widget_2)
        self.lineIP.setObjectName(u"lineIP")
        self.lineIP.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.lineIP, 3, 1, 1, 3)

        self.lineCOM = QLineEdit(self.widget_2)
        self.lineCOM.setObjectName(u"lineCOM")
        self.lineCOM.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.lineCOM, 4, 1, 1, 3)

        self.btnRecord = QPushButton(self.widget_2)
        self.btnRecord.setObjectName(u"btnRecord")
        self.btnRecord.setMinimumSize(QSize(50, 24))
        self.btnRecord.setMaximumSize(QSize(50, 24))

        self.gridLayout.addWidget(self.btnRecord, 6, 1, 1, 1)

        self.btn1 = QPushButton(self.widget_2)
        self.btn1.setObjectName(u"btn1")
        self.btn1.setMinimumSize(QSize(50, 24))
        self.btn1.setMaximumSize(QSize(50, 24))

        self.gridLayout.addWidget(self.btn1, 6, 2, 1, 1)


        self.verticalLayout_3.addLayout(self.gridLayout)


        self.verticalLayout_2.addWidget(self.widget_2)


        self.horizontalLayout.addWidget(self.widget)


        self.horizontalLayout_2.addLayout(self.horizontalLayout)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 645, 22))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        self.btnSendData.setDefault(False)


        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"\u7f51\u7edc\u8c03\u8bd5\u5de5\u5177", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"\u63a5\u6536\u7aef\uff1a", None))
        self.rcvTextBox.setPlaceholderText(QCoreApplication.translate("MainWindow", u"No Message was Received", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"\u53d1\u9001\u7aef\uff1a", None))
        self.sendTextBox.setPlainText("")
        self.sendTextBox.setPlaceholderText(QCoreApplication.translate("MainWindow", u"No Message to send", None))
        self.ckBxHex.setText(QCoreApplication.translate("MainWindow", u"HEX", None))
        self.btnSendData.setText(QCoreApplication.translate("MainWindow", u"\u53d1\u9001", None))
        self.btnClearTextBox.setText(QCoreApplication.translate("MainWindow", u"\u6e05\u7a7a", None))
        self.label_5.setText(QCoreApplication.translate("MainWindow", u"\u5b57\u8282\u6570\u636e\u5217\u8868\uff1a", None))
        self.btnClearByteData.setText(QCoreApplication.translate("MainWindow", u"\u6e05\u7a7a", None))
        self.btnShowByteData.setText(QCoreApplication.translate("MainWindow", u"\u5c55\u793a", None))
        self.btnSaveData.setText(QCoreApplication.translate("MainWindow", u"\u4fdd\u5b58", None))
        self.btnOpenData.setText(QCoreApplication.translate("MainWindow", u"\u6253\u5f00", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"\u6570\u636e", None))
        self.lblIP.setText(QCoreApplication.translate("MainWindow", u"IP", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"\u89d2\u8272", None))
        self.btnConnect.setText(QCoreApplication.translate("MainWindow", u"\u8fde\u63a5", None))
        self.lblCOM.setText(QCoreApplication.translate("MainWindow", u"COM", None))
        self.btn2.setText("")
        self.comboRoleType.setItemText(0, QCoreApplication.translate("MainWindow", u"TCP\u5ba2\u6237\u7aef", None))
        self.comboRoleType.setItemText(1, QCoreApplication.translate("MainWindow", u"TCP\u670d\u52a1\u7aef", None))

        self.comboMsgType.setItemText(0, QCoreApplication.translate("MainWindow", u"byte", None))
        self.comboMsgType.setItemText(1, QCoreApplication.translate("MainWindow", u"hex", None))
        self.comboMsgType.setItemText(2, QCoreApplication.translate("MainWindow", u"utf-8", None))

        self.lineIP.setText(QCoreApplication.translate("MainWindow", u"0.0.0.0", None))
        self.lineCOM.setText(QCoreApplication.translate("MainWindow", u"0", None))
        self.btnRecord.setText(QCoreApplication.translate("MainWindow", u"\u5f55\u5236", None))
        self.btn1.setText("")
    # retranslateUi

