#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->configureWindow();

    this->createWidgets();

    this->configureWidgets();

    this->createLayouts();

    this->settingLayouts();

    this->iniciateMemory();

    this->connects();
}

MainWindow::~MainWindow()
{
    delete this->microInstruction_label;
    delete this->PC_label;
    delete this->IR_label;
    delete this->AAddr_label;
    delete this->BAddr_label;
    delete this->AluOp_label;
    delete this->SwitchPos_label;
    delete this->CAddr_label;
    delete this->RWAddr_label;

    delete this->arrowIRToPC;
    delete this->arrowIRToMIR;

    delete this->controlUnit_label;
    delete this->dataPath_label;
    delete this->memory_label;

    delete this->arrowBTop;
    delete this->arrowBBot;
    delete this->arrowBRight;
    delete this->arrowBLeft;
    delete this->arrowRTop;
    delete this->arrowRBot;
    delete this->arrowRRight;
    delete this->arrowRLeft;

    delete this->PC_lineEdit;
    delete this->IR_lineEdit;
    delete this->AAddr_lineEdit;
    delete this->BAddr_lineEdit;
    delete this->AluOp_lineEdit;
    delete this->SwitchPos_lineEdit;
    delete this->CAddr_lineEdit;
    delete this->RWAddr_lineEdit;

    delete this->file_button;
    delete this->PC_button;

    delete this->file;
    delete this->file_RamMemory;

    delete this->tableMemory;

    delete this->processor;

    delete this->microInstructionLayout;
    delete this->microInstructionLayoutWindow;
    delete this->irLayout;
    delete this->irLayoutWindow;
    delete this->pcLayout;
    delete this->pcLayoutWindow;
    delete this->controlUnitLayout;
    delete this->controlUnitLayoutWindow;
    delete this->controlUnitScroll;

    delete this->dataPathLayout;
    delete this->dataPathLayoutWindow;
    delete this->dataPathScroll;

    delete this->mainMemoryLayout;
    delete this->mainMemoryLayoutWindow;

    delete this->split;

    delete this->mainLayout;
    delete this->mainLayoutWindow;
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
    this->microInstruction_label = new QLabel("Micro Instruction Register");
    this->PC_label = new QLabel("PC:");
    this->IR_label = new QLabel("IR:");
    this->AAddr_label = new QLabel("A Addr:");
    this->BAddr_label = new QLabel("B Addr:");
    this->AluOp_label = new QLabel("Alu Op:");
    this->SwitchPos_label = new QLabel("Switch Pos:");
    this->CAddr_label = new QLabel("C Addr:");
    this->RWAddr_label = new QLabel("RW Addr:");

    this->arrowIRToPC = new QLabel;
    this->arrowIRToMIR = new QLabel;

    this->controlUnit_label = new QLabel("Control Unit");
    this->dataPath_label = new QLabel("Data Path");
    this->memory_label = new QLabel("Main Memory");

    this->arrowBTop = new QPixmap(":/img/ArrowBTop.png");
    this->arrowBBot = new QPixmap(":/img/ArrowBBot.png");
    this->arrowBRight = new QPixmap(":/img/ArrowBRight.png");
    this->arrowBLeft = new QPixmap(":/img/ArrowBLeft.png");
    this->arrowRTop = new QPixmap(":/img/ArrowRTop.png");
    this->arrowRBot = new QPixmap(":/img/ArrowRBot.png");
    this->arrowRRight = new QPixmap(":/img/ArrowRRight.png");
    this->arrowRLeft = new QPixmap(":/img/ArrowRLeft.png");

    this->PC_lineEdit = new QLineEdit("0");
    this->IR_lineEdit = new QLineEdit("");
    this->AAddr_lineEdit = new QLineEdit("00");
    this->BAddr_lineEdit = new QLineEdit("00");
    this->AluOp_lineEdit = new QLineEdit("00");
    this->SwitchPos_lineEdit = new QLineEdit("0000");
    this->CAddr_lineEdit = new QLineEdit("00");
    this->RWAddr_lineEdit = new QLineEdit("00000");

    this->file_button = new QPushButton("Input File");
    this->PC_button = new QPushButton("Reset");

    this->file = new QFile;
    this->file_RamMemory = new QFile;

    this->createTableMemory();

    this->processor = new Processor;

    this->controlUnitScroll = new QScrollArea;
    this->dataPathScroll = new QScrollArea;

    this->split = new QSplitter(Qt::Vertical);
}

void MainWindow::configureWidgets()
{
    QDir::setCurrent("../..");

    this->microInstruction_label->setAlignment(Qt::AlignCenter);
    this->PC_label->setAlignment(Qt::AlignCenter);
    this->IR_label->setAlignment(Qt::AlignCenter);
    this->AAddr_label->setAlignment(Qt::AlignCenter);
    this->BAddr_label->setAlignment(Qt::AlignCenter);
    this->AluOp_label->setAlignment(Qt::AlignCenter);
    this->SwitchPos_label->setAlignment(Qt::AlignCenter);
    this->CAddr_label->setAlignment(Qt::AlignCenter);
    this->RWAddr_label->setAlignment(Qt::AlignCenter);

    this->arrowIRToPC->setPixmap(arrowBLeft->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowIRToMIR->setPixmap(arrowBTop->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowIRToMIR->setAlignment(Qt::AlignRight);

    this->controlUnit_label->setAlignment(Qt::AlignCenter);
    this->dataPath_label->setAlignment(Qt::AlignCenter);
    this->memory_label->setAlignment(Qt::AlignCenter);

    this->PC_lineEdit->setAlignment(Qt::AlignCenter);
    this->IR_lineEdit->setAlignment(Qt::AlignCenter);
    this->AAddr_lineEdit->setAlignment(Qt::AlignCenter);
    this->BAddr_lineEdit->setAlignment(Qt::AlignCenter);
    this->AluOp_lineEdit->setAlignment(Qt::AlignCenter);
    this->SwitchPos_lineEdit->setAlignment(Qt::AlignCenter);
    this->CAddr_lineEdit->setAlignment(Qt::AlignCenter);
    this->RWAddr_lineEdit->setAlignment(Qt::AlignCenter);

    this->PC_lineEdit->setFixedWidth(50);
    this->IR_lineEdit->setFixedWidth(150);
    this->AAddr_lineEdit->setFixedWidth(50);
    this->BAddr_lineEdit->setFixedWidth(50);
    this->AluOp_lineEdit->setFixedWidth(50);
    this->SwitchPos_lineEdit->setFixedWidth(80);
    this->CAddr_lineEdit->setFixedWidth(50);
    this->RWAddr_lineEdit->setFixedWidth(80);

    this->PC_button->setFixedWidth(60);
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
    // Layouts Widgets
    this->microInstructionLayoutWindow = new QWidget;
    this->pcirLayoutWindow = new QWidget;
    this->pcLayoutWindow = new QWidget;
    this->irLayoutWindow = new QWidget;
    this->controlUnitLayoutWindow = new QWidget;

    this->dataPathLayoutWindow = new QWidget;

    this->mainMemoryLayoutWindow = new QWidget;

    this->mainLayoutWindow = new QWidget;

    // Layouts
    this->microInstructionLayout = new QGridLayout(this->microInstructionLayoutWindow);
    this->pcirLayout = new QHBoxLayout(this->pcirLayoutWindow);
    this->pcLayout = new QHBoxLayout(this->pcLayoutWindow);
    this->irLayout = new QHBoxLayout(this->irLayoutWindow);
    this->controlUnitLayout = new QVBoxLayout(this->controlUnitLayoutWindow);

    this->dataPathLayout = new QVBoxLayout(this->dataPathLayoutWindow);

    this->mainMemoryLayout = new QVBoxLayout(this->mainMemoryLayoutWindow);

    this->mainLayout = new QHBoxLayout(this->mainLayoutWindow);
}

void MainWindow::settingLayouts()
{
    this->pcLayout->addWidget(this->PC_label);
    this->pcLayout->addWidget(this->PC_lineEdit);
    this->pcLayout->addWidget(this->PC_button);

    this->irLayout->addWidget(this->IR_label);
    this->irLayout->addWidget(this->IR_lineEdit);

    this->pcirLayout->addWidget(this->pcLayoutWindow);
    this->pcirLayout->addSpacing(10);
    this->pcirLayout->addWidget(this->arrowIRToPC);
    this->pcirLayout->addSpacing(10);
    this->pcirLayout->addWidget(this->irLayoutWindow);
    this->pcirLayout->setAlignment(Qt::AlignCenter);

    this->microInstructionLayout->addWidget(this->AAddr_label, 0, 0);
    this->microInstructionLayout->addWidget(this->BAddr_label, 0, 1);
    this->microInstructionLayout->addWidget(this->AluOp_label, 0, 2);
    this->microInstructionLayout->addWidget(this->SwitchPos_label, 0, 3);
    this->microInstructionLayout->addWidget(this->CAddr_label, 0, 4);
    this->microInstructionLayout->addWidget(this->RWAddr_label, 0, 5);
    this->microInstructionLayout->addWidget(this->AAddr_lineEdit, 1, 0);
    this->microInstructionLayout->addWidget(this->BAddr_lineEdit, 1, 1);
    this->microInstructionLayout->addWidget(this->AluOp_lineEdit, 1, 2);
    this->microInstructionLayout->addWidget(this->SwitchPos_lineEdit, 1, 3);
    this->microInstructionLayout->addWidget(this->CAddr_lineEdit, 1, 4);
    this->microInstructionLayout->addWidget(this->RWAddr_lineEdit, 1, 5);
    this->microInstructionLayout->setAlignment(Qt::AlignCenter);

    this->controlUnitLayout->addWidget(this->controlUnit_label);
    this->controlUnitLayout->addSpacing(50);
    this->controlUnitLayout->addWidget(this->microInstruction_label);
    this->controlUnitLayout->addWidget(this->microInstructionLayoutWindow);
    this->controlUnitLayout->addWidget(this->arrowIRToMIR);
    this->controlUnitLayout->addWidget(this->pcirLayoutWindow);
    this->controlUnitLayout->setAlignment(Qt::AlignCenter);

    this->dataPathLayout->addWidget(this->dataPath_label);
    this->dataPathLayout->setAlignment(Qt::AlignCenter);

    this->controlUnitScroll->setWidget(this->controlUnitLayoutWindow);
    this->controlUnitScroll->setAlignment(Qt::AlignCenter);
    this->dataPathScroll->setWidget(this->dataPathLayoutWindow);
    this->dataPathScroll->setAlignment(Qt::AlignCenter);

    this->mainMemoryLayout->addWidget(this->memory_label);
    this->mainMemoryLayout->addWidget(this->file_button);
    this->mainMemoryLayout->addWidget(this->tableMemory);
    this->mainMemoryLayoutWindow->setFixedWidth(270);

    this->split->setChildrenCollapsible(false);
    this->split->addWidget(this->dataPathScroll);
    this->split->addWidget(this->controlUnitScroll);

    this->mainLayout->addWidget(this->mainMemoryLayoutWindow);
    this->mainLayout->addWidget(this->split);

    this->setCentralWidget(this->mainLayoutWindow);
}

void MainWindow::iniciateMemory()
{
    this->processor->mainMemory->fill("0", 32);
}

void MainWindow::connects()
{
    QObject::connect(this, &MainWindow::sintaxeMemoryThrow, this, &MainWindow::sintaxeMemoryCatch);
    QObject::connect(this->file_button, &QPushButton::clicked, this, &MainWindow::readFile);
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

    file->setFileName(filename);
    file_RamMemory->setFileName("memoria_ram.txt");

    if(!file_RamMemory->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this,"Error","File not found");
        return;
    }

    QString line;
    QTextStream out(file_RamMemory);
    QTextStream in(file);

    for(int i=0; !in.atEnd(); i++)
    {
        if(i > 31)
        {
            break;
        }

        line = in.readLine();
        if(line.isNull())
        {
            break;
        }
        else
        {
            out << line << "\n";
            tableMemory->item(i, 1)->setText(line);
        }
    }

    file->close();
    file_RamMemory->close();
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
