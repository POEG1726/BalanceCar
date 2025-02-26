import sys
from PySide6.QtWidgets import QApplication
from main_ui import UI_HostApp


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = UI_HostApp()
    window.show()
    sys.exit(app.exec())
