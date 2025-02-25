import sys
from PySide6.QtWidgets import (
    QSizePolicy,
    QApplication,
    QWidget,
    QVBoxLayout,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QPushButton,
    QComboBox,
    QTextBrowser,
    QTextEdit,
    QCheckBox,
    QFrame,
)


class IPControllerApp(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("IP Controller App")
        self.setup_ui()

    def setup_ui(self):
        # 主布局为水平布局
        main_layout = QHBoxLayout(self)

        # 左侧布局
        left_layout = QVBoxLayout()

        # 添加顶部spacing
        # left_layout.addStretch()

        # 第一行：标签
        label = QLabel("Controller IP:")
        left_layout.addWidget(label)

        # 第二行：IP输入框
        ip_layout = QHBoxLayout()
        # 创建4个QLineEdit用于输入IP的各个部分
        self.ip_edits = []
        for i in range(4):
            edit = QLineEdit()
            edit.setContentsMargins(0, 0, 0, 0)
            edit.setFixedWidth(30)  # 固定宽度
            edit.setMaxLength(3)  # 每个部分最多3位数字
            self.ip_edits.append(edit)
            ip_layout.addWidget(edit)
            if i < 3:
                # 中间添加点
                dot_label = QLabel(".")
                dot_label.setContentsMargins(0, 0, 0, 0)
                ip_layout.addWidget(dot_label)

        left_layout.addLayout(ip_layout)

        # 第三行：Server Port标签和输入框
        port_layout = QHBoxLayout()
        port_label = QLabel("Server Port:")
        port_layout.addWidget(port_label)
        self.port_edit = QLineEdit()
        self.port_edit.setFixedWidth(50)  # 固定宽度
        self.port_edit.setMaxLength(5)  # 最多5位数字
        port_layout.addWidget(self.port_edit)
        left_layout.addLayout(port_layout)

        # 第四行：按钮布局
        button_layout = QHBoxLayout()
        self.clear_button = QPushButton("Clear")
        self.connect_button = QPushButton("Connect")
        button_layout.addWidget(self.clear_button)
        button_layout.addWidget(self.connect_button)
        left_layout.addLayout(button_layout)

        # 第五行：Camera标签、列表和Open按钮
        camera_layout = QHBoxLayout()
        camera_label = QLabel("Camera:")
        camera_layout.addWidget(camera_label)
        self.camera_list = QComboBox()
        camera_layout.addWidget(self.camera_list)
        self.open_button = QPushButton("Open")
        camera_layout.addWidget(self.open_button)
        left_layout.addLayout(camera_layout)

        # 添加horizontal line
        horizontal_line = QFrame()
        horizontal_line.setFrameShape(QFrame.HLine)
        horizontal_line.setFrameShadow(QFrame.Sunken)
        left_layout.addWidget(horizontal_line)

        left_layout.addStretch()
        
        # 将左侧布局添加到主布局
        main_layout.addLayout(left_layout)

        # 添加vertical line
        vertical_line = QFrame()
        vertical_line.setFrameShape(QFrame.VLine)
        vertical_line.setFrameShadow(QFrame.Sunken)
        main_layout.addWidget(vertical_line)

        # 右侧布局
        right_layout = QVBoxLayout()

        # TextBrowser
        self.text_browser = QTextBrowser()
        right_layout.addWidget(self.text_browser)

        # QTextEdit和按钮
        text_edit_layout = QHBoxLayout()
        self.text_edit = QTextEdit()
        self.text_edit.setFixedHeight(80)
        text_edit_layout.addWidget(self.text_edit)
        self.clear_button = QPushButton("Clear")
        self.send_button = QPushButton("Send")
        button_layout = QVBoxLayout()
        button_layout.addWidget(self.send_button)
        button_layout.addWidget(self.clear_button)
        text_edit_layout.addLayout(button_layout)
        right_layout.addLayout(text_edit_layout)

        # 选项
        options_layout = QVBoxLayout()
        self.show_time_checkbox = QCheckBox("Show Time")
        self.periodic_send_checkbox = QCheckBox("Periodic Send")
        options_layout.addWidget(self.show_time_checkbox)
        options_layout.addWidget(self.periodic_send_checkbox)

        # 周期发送选项
        periodic_options_layout = QHBoxLayout()
        self.interval_label = QLabel("Interval:")
        self.interval_edit = QLineEdit()
        self.count_label = QLabel("Count:")
        self.count_edit = QLineEdit()
        periodic_options_layout.addWidget(self.interval_label)
        periodic_options_layout.addWidget(self.interval_edit)
        periodic_options_layout.addWidget(self.count_label)
        periodic_options_layout.addWidget(self.count_edit)
        options_layout.addLayout(periodic_options_layout)

        right_layout.addLayout(options_layout)

        # 将右侧布局添加到主布局
        main_layout.addLayout(right_layout)

        # 信号连接：点击Clear按钮时清空所有IP输入框
        self.clear_button.clicked.connect(self.clear_ip)

    def clear_ip(self):
        for edit in self.ip_edits:
            edit.clear()
        self.port_edit.clear()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = IPControllerApp()
    window.show()
    sys.exit(app.exec())
