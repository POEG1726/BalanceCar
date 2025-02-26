from PySide6.QtCore import Qt,QSize,QRect
from PySide6.QtGui import QIntValidator
from PySide6.QtWidgets import \
    QApplication, QCheckBox, QComboBox, QFrame,\
    QGridLayout, QHBoxLayout, QLabel, QLineEdit,\
    QMainWindow, QMenuBar, QPlainTextEdit, QPushButton,\
    QSizePolicy, QSpacerItem, QStatusBar, QVBoxLayout,\
    QWidget,QTextBrowser,QTextEdit

class UI_HostApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("IP Controller App")
        self.setup_ui()
        self.setMinimumSize(QSize(1000,800))

    def setup_ui(self):
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        main_layout = QVBoxLayout(central_widget)

        center_layout = QHBoxLayout()
        left_layout = QVBoxLayout()
        right_layout = QVBoxLayout()
        center_layout.addLayout(left_layout)
        center_layout.addLayout(right_layout)

        bottom_layout = QHBoxLayout()
        main_layout.addLayout(center_layout)
        main_layout.addLayout(bottom_layout)

        # layout = QHBoxLayout()
        label = QLabel("Controller IP:")
        # label_1 = QLabel("Status:")
        # layout.addWidget(label)
        # layout.addSpacing(10)
        # layout.addWidget(label_1)
        # left_layout.addLayout(layout)
        left_layout.addWidget(label)

        ip_layout = QHBoxLayout()
        left_layout.addLayout(ip_layout)
        ip_validator = QIntValidator(0,255,self)
        self.ip_edits = []
        for i in range(4):
            edit = QLineEdit()
            edit.setContentsMargins(0,0,0,0)
            edit.setFixedWidth(30)
            edit.setMaxLength(3)
            edit.setValidator(ip_validator)
            edit.textChanged.connect(lambda text, idx=i: self.ip_octet_full(text, idx))
            self.ip_edits.append(edit)
        
        for i, edit in enumerate(self.ip_edits):
            ip_layout.addWidget(edit)
            if i < 3:
                dot = QLabel(".")
                dot.setFixedWidth(5)
                ip_layout.addWidget(dot)
        label_1 = QLabel(":")
        label_1.setFixedWidth(5)
        self.server_port = QLineEdit()
        self.server_port.setMaxLength(5)
        self.server_port.setValidator(QIntValidator(0,65535,self.server_port))
        self.server_port.setFixedWidth(50)
        ip_layout.addWidget(label_1)
        ip_layout.addWidget(self.server_port)
        
        # server_port_layout = QHBoxLayout()
        # left_layout.addLayout(server_port_layout)
        # server_port_label = QLabel("Server Port:")
        # self.server_port_input = QLineEdit()
        # port_validator = QIntValidator(0,65535)
        # self.server_port_input.setValidator(port_validator)
        # server_port_layout.addWidget(server_port_label)
        # server_port_layout.addWidget(self.server_port_input)

        ip_btn_layout = QHBoxLayout()
        left_layout.addLayout(ip_btn_layout)
        self.ip_btn_clear = QPushButton("clear")
        self.ip_btn_conn = QPushButton("connect")
        ip_btn_layout.addWidget(self.ip_btn_clear)
        ip_btn_layout.addWidget(self.ip_btn_conn)

    def ip_octet_full(self,text,idx):
        if len(text) == self.ip_edits[idx].maxLength() and idx < len(self.ip_edits) - 1:
            self.ip_edits[idx + 1].setFocus()