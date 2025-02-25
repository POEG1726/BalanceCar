from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QApplication, QPushButton, QLineEdit, QPlainTextEdit, QComboBox, QMenuBar, QStatusBar, \
    QFileDialog, QCheckBox
from PySide6.QtCore import Qt, Signal, QThread, QObject
from PySide6.QtUiTools import QUiLoader
import sys
import socket

class Main_Window(QObject):
    mainUICloseSignal = Signal()
    
    def __init__(self):
        super().__init__()

        self.ui = QUiLoader.load('./mainWindow.ui')

def main():
    app = QApplication([])
    main_window = Main_Window()
    main_window.ui.show()
    app.exec()
    main_window.mainUICloseSignal.emit()

if __name__ == '__main__':
    main()