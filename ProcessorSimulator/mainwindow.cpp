#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->configureWindow();

    this->createWidgets();

    this->createMainMemory();

    this->createLayouts();

    this->settingLayouts();

    this->iniciateMemory();
}

MainWindow::~MainWindow()
{
    delete this->split1;
    delete this->split2;

    for(int i = 0; i < 32; i++)
    {
        delete this->positionLabel->at(i);
        delete this->lineMemory->at(i);
    }
    delete this->positionLabel;
    delete this->lineMemory;

    delete this->controlUnitScroll;
    delete this->dataPathScroll;
    delete this->mainMemoryScroll;

    delete this->controlUnitLayoutWindow;
    delete this->dataPathLayoutWindow;
    delete this->mainMemoryAuxLayoutWindow;
    delete this->mainMemoryLayoutWindow;
    delete this->containerLayoutWindow;
    delete this->mainLayoutWindow;

    delete this->controlUnitLayout;
    delete this->dataPathLayout;
    delete this->mainMemoryAuxLayout;
    delete this->mainMemoryLayout;
    delete this->containerLayout;
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
    this->split1 = new QSplitter(Qt::Vertical);
    this->split2 = new QSplitter(Qt::Horizontal);

    this->controlUnitScroll = new QScrollArea;
    this->dataPathScroll = new QScrollArea;
    this->mainMemoryScroll = new QScrollArea;
}

void MainWindow::createMainMemory()
{
    this->lineMemory = new QVector<QLineEdit*>;

    for(int i = 0; i < 32; i++)
    {
        this->lineMemory->insert(i, new QLineEdit("0"));
    }

    this->positionLabel = new QVector<QLabel*>;

    for(int i = 0; i < 32; i++)
    {
        this->positionLabel->insert(i, new QLabel(QString::number(i) + ":"));
    }
}

void MainWindow::createLayouts()
{
    this->controlUnitLayoutWindow = new QWidget;
    this->dataPathLayoutWindow = new QWidget;
    this->mainMemoryAuxLayoutWindow = new QWidget;
    this->mainMemoryLayoutWindow = new QWidget;
    this->containerLayoutWindow = new QWidget;
    this->mainLayoutWindow = new QWidget;

    this->controlUnitLayout = new QVBoxLayout(this->controlUnitLayoutWindow);
    this->dataPathLayout = new QVBoxLayout(this->dataPathLayoutWindow);
    this->mainMemoryAuxLayout = new QHBoxLayout(this->mainMemoryAuxLayoutWindow);
    this->mainMemoryLayout = new QGridLayout(this->mainMemoryLayoutWindow);
    this->containerLayout = new QHBoxLayout(this->containerLayoutWindow);
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
        this->mainMemoryLayout->addWidget(this->lineMemory->at(i), i, 1);
    }
    this->mainMemoryAuxLayout->setAlignment(Qt::AlignCenter);
    this->mainMemoryAuxLayout->addWidget(this->mainMemoryLayoutWindow);

    this->controlUnitScroll->setWidget(this->controlUnitLayoutWindow);
    this->dataPathScroll->setWidget(this->dataPathLayoutWindow);
    this->mainMemoryScroll->setWidget(this->mainMemoryAuxLayoutWindow);

    this->split1->setChildrenCollapsible(false);
    this->split1->addWidget(this->controlUnitScroll);
    this->split1->addWidget(this->mainMemoryScroll);

    this->containerLayout->setContentsMargins(0, 0, 0, 0);
    this->containerLayout->addWidget(this->split1);

    this->split2->setChildrenCollapsible(false);
    this->split2->addWidget(this->containerLayoutWindow);
    this->split2->addWidget(this->dataPathScroll);

    this->mainLayout->setAlignment(Qt::AlignCenter);
    this->mainLayout->addWidget(this->split2);

    this->setCentralWidget(this->mainLayoutWindow);

    this->split1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->split2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

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
