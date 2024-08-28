#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->configureWindow();

    this->createLayouts();

    this->settingLayouts();
}

MainWindow::~MainWindow()
{

}

void MainWindow::configureWindow()
{
    QWidget::setWindowTitle("Processor Simulator");
    this->setMinimumSize(1260, 768);

    QScreen *screen = QGuiApplication::primaryScreen();
    int screenWidth = screen->geometry().width();
    int screenHeight = screen->geometry().height();
    this->setGeometry((screenWidth/2)-(this->width()/2), (screenHeight/2)-(this->height()/2), this->width(), this->height());

    this->darkTheme();
}

void MainWindow::createLayouts()
{
    this->layoutWindow = new QWidget;
    this->mainLayout = new QVBoxLayout(this->layoutWindow);
}

void MainWindow::settingLayouts()
{
    this->mainLayout->setAlignment(Qt::AlignCenter);

    this->setCentralWidget(this->layoutWindow);
}

void MainWindow::darkTheme()
{
    // Dark Theme
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, QColor(51, 51, 51));
    pal.setColor(QPalette::WindowText, Qt::white);
    pal.setColor(QPalette::Button, QColor(35, 45, 63));
    pal.setColor(QPalette::ButtonText, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}
