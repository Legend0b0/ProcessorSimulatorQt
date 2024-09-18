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

    delete this->tableMemory;

    delete this->controlUnitScroll;
    delete this->dataPathScroll;

    delete this->controlUnitLayoutWindow;
    delete this->dataPathLayoutWindow;
    delete this->mainLayoutWindow;

    delete this->controlUnitLayout;
    delete this->dataPathLayout;
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
}

void MainWindow::createMainMemory()
{
    this->tableMemory = new QTableWidget(32, 3);

    this->tableMemory->horizontalHeader()->hide();
    this->tableMemory->verticalHeader()->hide();
    this->tableMemory->setMaximumWidth(230);
    this->tableMemory->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    for(int i = 0; i < 32; i++)
    {
        this->tableMemory->setItem(i, 0, new QTableWidgetItem(QString::number(i) + ":"));
        this->tableMemory->item(i, 0)->setBackground(QBrush(QColor(51,51,51)));
        this->tableMemory->item(i, 0)->setForeground(QBrush(QColor(255,255,255)));
        this->tableMemory->item(i, 0)->setFlags(Qt::ItemIsEnabled);
        //this->tableMemory->item(i, 0)->setTextAlignment(Qt::AlignCenter);

        this->tableMemory->setItem(i, 1, new QTableWidgetItem("0"));

        this->tableMemory->setItem(i, 2, new QTableWidgetItem("Int"));
        this->tableMemory->item(i, 2)->setBackground(QBrush(QColor(51,51,51)));
        this->tableMemory->item(i, 2)->setForeground(QBrush(QColor(0,255,0)));
        this->tableMemory->item(i, 2)->setFlags(Qt::ItemIsEnabled);
        //this->tableMemory->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    }

    this->tableMemory->resizeColumnToContents(0);
    this->tableMemory->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
}

void MainWindow::createLayouts()
{
    this->controlUnitLayoutWindow = new QWidget;
    this->dataPathLayoutWindow = new QWidget;
    this->mainLayoutWindow = new QWidget;

    this->controlUnitLayout = new QVBoxLayout(this->controlUnitLayoutWindow);
    this->dataPathLayout = new QVBoxLayout(this->dataPathLayoutWindow);
    this->mainLayout = new QHBoxLayout(this->mainLayoutWindow);
}

void MainWindow::settingLayouts()
{
    this->controlUnitLayout->setAlignment(Qt::AlignCenter);
    this->controlUnitLayout->addWidget(new QPushButton("A"));

    this->dataPathLayout->setAlignment(Qt::AlignCenter);
    this->dataPathLayout->addWidget(new QPushButton("B"));

    this->controlUnitScroll->setWidget(this->controlUnitLayoutWindow);
    this->dataPathScroll->setWidget(this->dataPathLayoutWindow);

    this->split->setChildrenCollapsible(false);
    this->split->addWidget(this->dataPathScroll);
    this->split->addWidget(this->controlUnitScroll);

    this->mainLayout->setAlignment(Qt::AlignCenter);
    this->mainLayout->addWidget(this->tableMemory);
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
