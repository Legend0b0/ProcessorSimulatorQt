#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->configureWindow();

    this->createWidgets();

    this->createLayouts();

    this->settingLayouts();

    this->iniciateMemory();

    this->connectButons();
}

MainWindow::~MainWindow()
{
    delete this->control_button;
    delete this->data_button;
    delete this->file_button;

    delete this->memory_label;

    delete this->tableMemory;

    delete this->processor;

    delete this->controlUnitLayout;
    delete this->controlUnitLayoutWindow;
    delete this->controlUnitScroll;

    delete this->dataPathLayout;
    delete this->dataPathLayoutWindow;
    delete this->dataPathScroll;

    delete this->mainMemoryLayoutWindow;
    delete this->mainLayoutWindow;

    //delete this->mainMemoryLayout;
    //delete this->split;
    //delete this->mainLayout;
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
    this->control_button = new QPushButton("Control Unit");
    this->data_button = new QPushButton("Data Path");
    this->file_button = new QPushButton("Input File");

    this->memory_label = new QLabel("Main Memory");

    this->split = new QSplitter(Qt::Vertical);

    this->controlUnitScroll = new QScrollArea;
    this->dataPathScroll = new QScrollArea;

    this->createTableMemory();

    this->processor = new Processor;
}

void MainWindow::createTableMemory()
{
    this->tableMemory = new QTableWidget(32, 3);

    this->tableMemory->horizontalHeader()->hide();
    this->tableMemory->verticalHeader()->hide();
    this->tableMemory->setMaximumWidth(250);
    this->tableMemory->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    for(int i = 0; i < 32; i++)
    {
        this->tableMemory->setItem(i, 0, new QTableWidgetItem(QString::number(i) + ":"));
        this->tableMemory->item(i, 0)->setForeground(QBrush(QColor(255, 255, 255)));
        this->tableMemory->item(i, 0)->setBackground(QBrush(QColor(51, 51, 51)));
        this->tableMemory->item(i, 0)->setFlags(Qt::ItemIsEnabled);

        this->tableMemory->setItem(i, 1, new QTableWidgetItem("0"));

        this->tableMemory->setItem(i, 2, new QTableWidgetItem("Integer"));
        this->tableMemory->item(i, 2)->setForeground(QBrush(QColor(255, 255, 255)));
        this->tableMemory->item(i, 2)->setBackground(QBrush(QColor(51, 51, 51)));
        this->tableMemory->item(i, 2)->setFlags(Qt::ItemIsEnabled);
    }

    this->tableMemory->item(31, 1)->setText("ADD R0 R0 R0 ");
    this->tableMemory->resizeColumnToContents(0);
    this->tableMemory->resizeColumnToContents(1);
    this->tableMemory->item(31, 1)->setText("0");

    this->tableMemory->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
}

void MainWindow::createLayouts()
{
    this->controlUnitLayoutWindow = new QWidget;
    this->dataPathLayoutWindow = new QWidget;
    this->mainMemoryAuxLayoutWindow = new QWidget;
    this->mainMemoryLayoutWindow = new QWidget;
    this->mainLayoutWindow = new QWidget;

    this->controlUnitLayout = new QVBoxLayout(this->controlUnitLayoutWindow);
    this->dataPathLayout = new QVBoxLayout(this->dataPathLayoutWindow);
    this->mainMemoryAuxLayout = new QHBoxLayout(this->mainMemoryAuxLayoutWindow);
    this->mainMemoryLayout = new QVBoxLayout(this->mainMemoryLayoutWindow);
    this->mainLayout = new QHBoxLayout(this->mainLayoutWindow);
}

void MainWindow::settingLayouts()
{
    this->controlUnitLayout->setAlignment(Qt::AlignCenter);
    this->controlUnitLayout->addWidget(control_button);

    this->dataPathLayout->setAlignment(Qt::AlignCenter);
    this->dataPathLayout->addWidget(data_button);

    this->controlUnitScroll->setWidget(this->controlUnitLayoutWindow);
    this->dataPathScroll->setWidget(this->dataPathLayoutWindow);

    this->mainMemoryAuxLayout->addStretch(1);
    this->mainMemoryAuxLayout->addWidget(memory_label);
    this->mainMemoryAuxLayout->addStretch(1);

    this->mainMemoryLayout->addWidget(mainMemoryAuxLayoutWindow);
    this->mainMemoryLayout->addWidget(file_button);
    this->mainMemoryLayout->addWidget(this->tableMemory);
    this->mainMemoryLayoutWindow->setFixedWidth(270);

    this->split->setChildrenCollapsible(false);
    this->split->addWidget(this->dataPathScroll);
    this->split->addWidget(this->controlUnitScroll);

    this->mainLayout->setAlignment(Qt::AlignCenter);
    this->mainLayout->addWidget(this->mainMemoryLayoutWindow);
    this->mainLayout->addWidget(this->split);

    this->setCentralWidget(this->mainLayoutWindow);
}

void MainWindow::iniciateMemory()
{
    this->processor->mainMemory->fill("0", 32);
}

void MainWindow::connectButons()
{
    QObject::connect(this->file_button, &QPushButton::clicked, this, &MainWindow::readFile);
    QObject::connect(this, &MainWindow::sintaxeMemoryThrow, this, &MainWindow::sintaxeMemoryCatch);
    QObject::connect(this->tableMemory, &QTableWidget::itemChanged, this, &MainWindow::textChanged);
}

void MainWindow::verifyInstruction(QTableWidgetItem *item)
{
    QRegularExpression re;
    re.setPattern(R"((^(ADD|SUB|OR|AND)\sR[0-3]\sR[0-3]\sR[0-3]$)|(^(HALT|NOP)$)|(^(BRANCH|BNEG|BZERO)\s([0-9]|[1-2][0-9]|[3][0-1])$)|(^(MOVE\sR[0-3]\sR[0-3])$)|(^(STORE\s([0-9]|[1-2][0-9]|[3][0-1])\sR[0-3])$)|(^(LOAD\sR[0-3]\s([0-9]|[1-2][0-9]|[3][0-1]))$))");

    QRegularExpressionMatch match = re.match(item->text());
    if(match.hasMatch())
    {
        emit sintaxeMemoryThrow(item->row(), 1);
        return;
    }

    emit sintaxeMemoryThrow(item->row(), 2);
    return;
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

void MainWindow::readFile()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Abrir ficheiro"),QDir::currentPath(), tr("Text files (*.txt)"));
    file.setFileName(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this,"Error","File not found");
        return;
    }

    QTextStream in(&file);
    for(int i=0; !in.atEnd(); i++)
    {
        QString line = in.readLine();
        if(line.isNull())
        {
            break;
        }
        else
        {
            tableMemory->item(i, 1)->setText(line);
        }
    }
    file.close();
}

void MainWindow::textChanged(QTableWidgetItem *item)
{
    this->tableMemory->blockSignals(true);

    item->setText(item->text().toUpper());

    QString string = item->text();

    while(!(string.isEmpty()) && ((string[0] == '0') || (string[0] == ' ')))
    {
        string.removeFirst();
    }

    if(string.isEmpty())
    {
        item->setText("0");
        emit sintaxeMemoryThrow(item->row(), 0);
        this->tableMemory->blockSignals(false);
        return;
    }

    while(!(string.isEmpty()) && ((string[string.size()-1] == ' ') || (string[string.size()-1] == '\n')))
    {
        string.removeLast();
    }

    if(string.isEmpty())
    {
        item->setText("0");
        emit sintaxeMemoryThrow(item->row(), 0);
        this->tableMemory->blockSignals(false);
        return;
    }

    item->setText(string);

    if((string[0] >= '0') && (string[0] <= '9'))
    {
        if(string.toInt() == 0)
        {
            emit sintaxeMemoryThrow(item->row(), 2);
            this->tableMemory->blockSignals(false);
            return;
        }

        emit sintaxeMemoryThrow(item->row(), 0);
        this->tableMemory->blockSignals(false);
        return;
    }

    verifyInstruction(item);

    this->tableMemory->blockSignals(false);
    return;
}

void MainWindow::sintaxeMemoryCatch(int i, int signal)
{
    switch(signal)
    {
        case 0:
        {
            this->tableMemory->item(i, 2)->setText("Integer");
            this->tableMemory->item(i, 2)->setForeground(QBrush(QColor(255, 255, 255)));
            break;
        }
        case 1:
        {
            this->tableMemory->item(i, 2)->setText("Instruction");
            this->tableMemory->item(i, 2)->setForeground(QBrush(QColor(0, 255, 0)));
            break;
        }
        case 2:
        {
            this->tableMemory->item(i, 2)->setText("Sintaxe Error");
            this->tableMemory->item(i, 2)->setForeground(QBrush(QColor(255, 0, 0)));
            break;
        }
        default:
        {
            break;
        }
    }
}
