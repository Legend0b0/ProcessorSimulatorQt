#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->configureWindow();

    this->createLayouts();

    this->settingLayouts();

    this->iniciateMemory();
}

MainWindow::~MainWindow()
{
    delete this->mainLayout;
    delete this->layoutWindow;

    delete this->processor->controlUnit;

    delete this->processor->dataPath;

    delete this->processor->mainMemory;

    delete this->processor;
}

void MainWindow::configureWindow()
{
    QWidget::setWindowTitle("Processor Simulator");
    this->setBaseSize(800, 600);

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

void MainWindow::iniciateMemory()
{
    this->processor->mainMemory->fill("0", 32);
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

void Processor::LOAD()
{

}

void Processor::STORE()
{

}

void Processor::MOVE()
{

}

void Processor::ADD()
{

}

void Processor::SUB()
{

}

void Processor::AND()
{

}

void Processor::OR()
{

}

void Processor::BRANCH()
{

}

void Processor::BZERO()
{

}

void Processor::BNEG()
{

}

void Processor::NOP()
{

}

void Processor::HALT()
{

}
