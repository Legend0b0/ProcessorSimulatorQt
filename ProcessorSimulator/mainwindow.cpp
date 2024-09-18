#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->configureWindow();

    this->createWidgets();

    this->createMainMemory();

    this->createLayouts();

    this->settingLayouts();

    this->iniciateMemory();

    this->resize(1200, 800);
}

MainWindow::~MainWindow()
{
    delete this->split;

    delete this->listMemory;

    for(int i = 0; i < 32; i++)
    {
        delete this->positionLabel->at(i);
        delete this->errorLabel->at(i);
    }
    delete this->positionLabel;
    delete this->errorLabel;

    delete this->controlUnitScroll;
    delete this->dataPathScroll;
    delete this->mainMemoryScroll;

    delete this->controlUnitLayoutWindow;
    delete this->dataPathLayoutWindow;
    delete this->mainMemoryLayoutWindow;
    delete this->mainLayoutWindow;

    delete this->controlUnitLayout;
    delete this->dataPathLayout;
    delete this->mainMemoryLayout;
    delete this->mainLayout;

    delete this->processor->controlUnit;

    delete this->processor->dataPath;

    delete this->processor->mainMemory;

    delete this->processor;
}

void MainWindow::configureWindow()
{
    QWidget::setWindowTitle("Processor Simulator");
    this->resize(1200, 800);

    QScreen *screen = QGuiApplication::primaryScreen();
    int screenWidth = screen->geometry().width();
    int screenHeight = screen->geometry().height();
    this->setGeometry((screenWidth/2)-(this->width()/2), (screenHeight/2)-(this->height()/2), this->width(), this->height());

    this->darkTheme();
}

void MainWindow::createWidgets()
{
    this->split = new QSplitter(Qt::Vertical);

    this->controlUnitScroll = new QScrollArea;
    this->dataPathScroll = new QScrollArea;
    this->mainMemoryScroll = new QScrollArea;
}

void MainWindow::createMainMemory()
{
    this->positionLabel = new QVector<QLabel*>;
    this->errorLabel = new QVector<QLabel*>;
    this->listMemory = new QListWidget;

    this->listMemory->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->listMemory->setMaximumWidth(300);

    for(int i = 0; i < 32; i++)
    {
        this->positionLabel->insert(i, new QLabel(QString::number(i) + ":"));

        this->listMemory->addItem(new QListWidgetItem("0"));

        this->errorLabel->insert(i, new QLabel("Syntax Error"));
        this->errorLabel->at(i)->setStyleSheet("QLabel { color : red; }");
    }
    this->listMemory->setFont(QFont ("Courier", 15));
}

void MainWindow::createLayouts()
{
    this->controlUnitLayoutWindow = new QWidget;
    this->dataPathLayoutWindow = new QWidget;
    this->mainMemoryLayoutWindow = new QWidget;
    this->mainLayoutWindow = new QWidget;

    this->controlUnitLayout = new QVBoxLayout(this->controlUnitLayoutWindow);
    this->dataPathLayout = new QVBoxLayout(this->dataPathLayoutWindow);
    this->mainMemoryLayout = new QGridLayout(this->mainMemoryLayoutWindow);
    this->mainLayout = new QHBoxLayout(this->mainLayoutWindow);
}

void MainWindow::settingLayouts()
{
    this->controlUnitLayout->setAlignment(Qt::AlignCenter);
    this->controlUnitLayout->addWidget(new QPushButton("A"));

    this->dataPathLayout->setAlignment(Qt::AlignCenter);
    this->dataPathLayout->addWidget(new QPushButton("B"));

    this->mainMemoryLayout->setAlignment(Qt::AlignCenter);
    this->mainMemoryLayout->setRowStretch(1, 1);
    this->mainMemoryLayout->setColumnStretch(1, 1);
    for(int i = 0; i < 32; i++)
    {
        this->mainMemoryLayout->addWidget(this->positionLabel->at(i), i, 0);
        this->mainMemoryLayout->addWidget(this->errorLabel->at(i), i, 2);
    }
    this->mainMemoryLayout->addWidget(this->listMemory, 0, 1, 31, 1);

    this->controlUnitScroll->setWidget(this->controlUnitLayoutWindow);
    this->dataPathScroll->setWidget(this->dataPathLayoutWindow);
    this->mainMemoryScroll->setWidget(this->mainMemoryLayoutWindow);

    this->split->setChildrenCollapsible(false);
    this->split->addWidget(this->dataPathScroll);
    this->split->addWidget(this->controlUnitScroll);
    this->split->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->mainLayout->setAlignment(Qt::AlignCenter);
    this->mainLayout->addWidget(this->mainMemoryScroll);
    this->mainLayout->addWidget(this->split);

    this->setCentralWidget(this->mainLayoutWindow);
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
