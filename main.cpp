#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Grand Azure Hotel");
    app.setOrganizationName("GrandAzure");
    app.setStyleSheet("QMainWindow{background:#0D1B2A;} QWidget{font-family:'Segoe UI',Arial,sans-serif;font-size:13px;} QMessageBox{background:#1A2E45;color:#FAF7F0;} QMessageBox QLabel{color:#FAF7F0;} QMessageBox QPushButton{background:#C9A84C;color:#0D1B2A;border:none;padding:6px 18px;border-radius:4px;font-weight:bold;} QMessageBox QPushButton:hover{background:#F0D98E;}");
    MainWindow w;
    w.show();
    return app.exec();
}
