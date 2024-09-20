#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->configureWindow();

    this->createWidgets();

    this->configureWidgets();

    this->createLayouts();

    this->settingLayouts();

    this->connects();
}

MainWindow::~MainWindow()
{
    delete this->controlUnit_label;
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

    delete this->dataPath_label;
    delete this->registerBank_label;
    delete this->ABusAdr_label;
    delete this->BBusAdr_label;
    delete this->CBusAdr_label;
    delete this->ABus_label;
    delete this->BBus_label;
    delete this->CBus_label;
    delete this->MMBus_label;
    delete this->R0_label;
    delete this->R1_label;
    delete this->R2_label;
    delete this->R3_label;
    delete this->ABusALU_label;
    delete this->BBusALU_label;
    delete this->CBusALU_label;
    this->rAAdr->clear();
    delete this->rAAdr;
    this->rBAdr->clear();
    delete this->rBAdr;
    this->rCAdr->clear();
    delete this->rCAdr;
    this->rALU->clear();
    delete this->rALU;
    delete this->arrowAAdrToABus;
    delete this->arrowBAdrToBBus;
    delete this->arrowABusToALU;
    delete this->arrowBBusToALU;
    delete this->arrowALUToCBus;
    delete this->arrowCBusToMMBus;
    delete this->arrowMMBusToCBus;
    delete this->arrowCBusToCAdr;
    delete this->ballArrowAAdr;
    delete this->ballArrowBAdr;
    delete this->ballArrowCAdr;
    delete this->ballArrowALU;

    delete this->memory_label;

    delete this->arrowBTop;
    delete this->arrowBBot;
    delete this->arrowBRight;
    delete this->arrowBLeft;
    delete this->arrowBTopLeft;
    delete this->arrowRTop;
    delete this->arrowRBot;
    delete this->arrowRRight;
    delete this->arrowRLeft;
    delete this->arrowRTopLeft;
    delete this->ballArrowTop;
    delete this->ballArrowBot;
    delete this->ballArrowRight;
    delete this->ballArrowLeft;

    delete this->PC_lineEdit;
    delete this->IR_lineEdit;
    delete this->AAddr_lineEdit;
    delete this->BAddr_lineEdit;
    delete this->AluOp_lineEdit;
    delete this->SwitchPos_lineEdit;
    delete this->CAddr_lineEdit;
    delete this->RWAddr_lineEdit;

    delete this->R0_lineEdit;
    delete this->R1_lineEdit;
    delete this->R2_lineEdit;
    delete this->R3_lineEdit;
    delete this->ABus_lineEdit;
    delete this->BBus_lineEdit;
    delete this->CBus_lineEdit;
    delete this->MMBus_lineEdit;
    delete this->ABusALU_lineEdit;
    delete this->BBusALU_lineEdit;
    delete this->CBusALU_lineEdit;

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

    delete this->aAdrLayout;
    delete this->aAdrLayoutWindow;
    delete this->bAdrLayout;
    delete this->bAdrLayoutWindow;
    delete this->cAdrLayout;
    delete this->cAdrLayoutWindow;
    delete this->aluArrowLayout;
    delete this->aluArrowLayoutWindow;
    delete this->aBusLayout;
    delete this->aBusLayoutWindow;
    delete this->bBusLayout;
    delete this->bBusLayoutWindow;
    delete this->cBusLayout;
    delete this->cBusLayoutWindow;
    delete this->mmBusLayout;
    delete this->mmBusLayoutWindow;
    delete this->aBusALULayout;
    delete this->aBusALULayoutWindow;
    delete this->bBusALULayout;
    delete this->bBusALULayoutWindow;
    delete this->cBusALULayout;
    delete this->cBusALULayoutWindow;
    delete this->aluLayout;
    delete this->aluLayoutWindow;
    delete this->registersLayout;
    delete this->registersLayoutWindow;
    delete this->registerBankLayout;
    delete this->registerBankLayoutWindow;
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
    this->createControlUnitWidgets();
    this->createDataPathWidgets();
    this->createMainMemoryWidgets();

    this->arrowBTop = new QPixmap(":/img/ArrowBTop.png");
    this->arrowBBot = new QPixmap(":/img/ArrowBBot.png");
    this->arrowBRight = new QPixmap(":/img/ArrowBRight.png");
    this->arrowBLeft = new QPixmap(":/img/ArrowBLeft.png");
    this->arrowBTopLeft = new QPixmap(":/img/ArrowBTopLeft.png");
    this->arrowRTop = new QPixmap(":/img/ArrowRTop.png");
    this->arrowRBot = new QPixmap(":/img/ArrowRBot.png");
    this->arrowRRight = new QPixmap(":/img/ArrowRRight.png");
    this->arrowRLeft = new QPixmap(":/img/ArrowRLeft.png");
    this->arrowRTopLeft = new QPixmap(":/img/ArrowRTopLeft.png");
    this->ballArrowTop = new QPixmap(":/img/BallArrowTop.png");
    this->ballArrowBot = new QPixmap(":/img/BallArrowBot.png");
    this->ballArrowRight = new QPixmap(":/img/BallArrowRight.png");
    this->ballArrowLeft = new QPixmap(":/img/BallArrowLeft.png");

    this->processor = new Processor;
}

void MainWindow::createControlUnitWidgets()
{
    this->controlUnit_label = new QLabel("Control Unit");

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

    this->PC_lineEdit = new QLineEdit("0");
    this->IR_lineEdit = new QLineEdit("");
    this->AAddr_lineEdit = new QLineEdit("00");
    this->BAddr_lineEdit = new QLineEdit("00");
    this->AluOp_lineEdit = new QLineEdit("00");
    this->SwitchPos_lineEdit = new QLineEdit("0000");
    this->CAddr_lineEdit = new QLineEdit("00");
    this->RWAddr_lineEdit = new QLineEdit("00000");

    this->PC_button = new QPushButton("Reset");

    this->controlUnitScroll = new QScrollArea;
}

void MainWindow::createDataPathWidgets()
{
    this->dataPath_label = new QLabel("Data Path");
    this->registerBank_label = new QLabel("Register Bank");
    this->ABusAdr_label = new QLabel("A Bus\nAddress");
    this->BBusAdr_label = new QLabel("B Bus\nAddress");
    this->CBusAdr_label = new QLabel("C Bus\nAddress");
    this->ABus_label = new QLabel("A Bus");
    this->BBus_label = new QLabel("B Bus");
    this->CBus_label = new QLabel("C Bus");
    this->MMBus_label = new QLabel("Main Memory Bus");
    this->R0_label = new QLabel("R0:");
    this->R1_label = new QLabel("R1:");
    this->R2_label = new QLabel("R2:");
    this->R3_label = new QLabel("R3:");
    this->ABusALU_label = new QLabel("A:");
    this->BBusALU_label = new QLabel("B:");
    this->CBusALU_label = new QLabel("C:");
    this->arrowAAdrToABus = new QLabel;
    this->arrowBAdrToBBus = new QLabel;
    this->arrowABusToALU = new QLabel;
    this->arrowBBusToALU = new QLabel;
    this->arrowALUToCBus = new QLabel;
    this->arrowCBusToMMBus = new QLabel;
    this->arrowMMBusToCBus = new QLabel;
    this->arrowCBusToCAdr = new QLabel;
    this->ballArrowAAdr = new QLabel;
    this->ballArrowBAdr = new QLabel;
    this->ballArrowCAdr = new QLabel;
    this->ballArrowALU = new QLabel;

    this->rAAdr = new QVector<QLabel*>;
    this->rBAdr = new QVector<QLabel*>;
    this->rCAdr = new QVector<QLabel*>;
    this->rALU = new QVector<QLabel*>;

    this->R0_lineEdit = new QLineEdit("0");
    this->R1_lineEdit = new QLineEdit("0");
    this->R2_lineEdit = new QLineEdit("0");
    this->R3_lineEdit = new QLineEdit("0");
    this->ABus_lineEdit = new QLineEdit("0");
    this->BBus_lineEdit = new QLineEdit("0");
    this->CBus_lineEdit = new QLineEdit("0");
    this->MMBus_lineEdit = new QLineEdit("0");
    this->ABusALU_lineEdit = new QLineEdit("0");;
    this->BBusALU_lineEdit = new QLineEdit("0");;
    this->CBusALU_lineEdit = new QLineEdit("0");;

    this->dataPathScroll = new QScrollArea;
}

void MainWindow::createMainMemoryWidgets()
{
    this->memory_label = new QLabel("Main Memory");

    this->file_button = new QPushButton("Input File");

    this->file = new QFile;
    this->file_RamMemory = new QFile;

    this->createTableMemory();
}

void MainWindow::configureWidgets()
{
    this->configureControlUnitWidgets();
    this->configureDataPathWidgets();
    this->configureMainMemoryWidgets();

    QDir::setCurrent("../..");
}

void MainWindow::configureControlUnitWidgets()
{
    this->controlUnit_label->setAlignment(Qt::AlignCenter);

    this->microInstruction_label->setAlignment(Qt::AlignCenter);
    this->PC_label->setAlignment(Qt::AlignCenter);
    this->IR_label->setAlignment(Qt::AlignCenter);
    this->AAddr_label->setAlignment(Qt::AlignCenter);
    this->BAddr_label->setAlignment(Qt::AlignCenter);
    this->AluOp_label->setAlignment(Qt::AlignCenter);
    this->SwitchPos_label->setAlignment(Qt::AlignCenter);
    this->CAddr_label->setAlignment(Qt::AlignCenter);
    this->RWAddr_label->setAlignment(Qt::AlignCenter);
    this->arrowIRToMIR->setAlignment(Qt::AlignBottom|Qt::AlignRight);

    this->arrowIRToPC->setPixmap(arrowBLeft->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowIRToMIR->setPixmap(arrowBTop->scaled(30, 30, Qt::KeepAspectRatio));

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

void MainWindow::configureDataPathWidgets()
{
    this->dataPath_label->setAlignment(Qt::AlignCenter);
    this->registerBank_label->setAlignment(Qt::AlignCenter);

    this->ABusAdr_label->setAlignment(Qt::AlignCenter);
    this->BBusAdr_label->setAlignment(Qt::AlignCenter);
    this->CBusAdr_label->setAlignment(Qt::AlignCenter);
    this->ABus_label->setAlignment(Qt::AlignCenter);
    this->BBus_label->setAlignment(Qt::AlignCenter);
    this->CBus_label->setAlignment(Qt::AlignCenter);
    this->MMBus_label->setAlignment(Qt::AlignCenter);

    this->arrowAAdrToABus->setPixmap(arrowBBot->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowBAdrToBBus->setPixmap(arrowBBot->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowABusToALU->setPixmap(arrowBBot->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowBBusToALU->setPixmap(arrowBBot->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowALUToCBus->setPixmap(arrowBTopLeft->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowCBusToMMBus->setPixmap(arrowBBot->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowMMBusToCBus->setPixmap(arrowBTop->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowCBusToCAdr->setPixmap(arrowBTop->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowAAdr->setPixmap(ballArrowTop->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowBAdr->setPixmap(ballArrowTop->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowCAdr->setPixmap(ballArrowTop->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowALU->setPixmap(ballArrowTop->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowAAdrToABus->setAlignment(Qt::AlignCenter);
    this->arrowBAdrToBBus->setAlignment(Qt::AlignCenter);
    this->arrowABusToALU->setAlignment(Qt::AlignCenter);
    this->arrowBBusToALU->setAlignment(Qt::AlignCenter);
    this->arrowALUToCBus->setAlignment(Qt::AlignCenter);
    this->arrowCBusToMMBus->setAlignment(Qt::AlignLeft);
    this->arrowMMBusToCBus->setAlignment(Qt::AlignRight);
    this->arrowCBusToCAdr->setAlignment(Qt::AlignCenter);
    this->ballArrowAAdr->setAlignment(Qt::AlignCenter);
    this->ballArrowBAdr->setAlignment(Qt::AlignCenter);
    this->ballArrowCAdr->setAlignment(Qt::AlignCenter);
    this->ballArrowALU->setAlignment(Qt::AlignCenter);

    this->rAAdr->append(new QLabel("R0"));
    this->rBAdr->append(new QLabel("R0"));
    this->rCAdr->append(new QLabel("R0"));
    this->rALU->append(new QLabel("A+B"));
    this->rAAdr->append(new QLabel("R1"));
    this->rBAdr->append(new QLabel("R1"));
    this->rCAdr->append(new QLabel("R1"));
    this->rALU->append(new QLabel("A-B"));
    this->rAAdr->append(new QLabel("R2"));
    this->rBAdr->append(new QLabel("R2"));
    this->rCAdr->append(new QLabel("R2"));
    this->rALU->append(new QLabel("A|B"));
    this->rAAdr->append(new QLabel("R3"));
    this->rBAdr->append(new QLabel("R3"));
    this->rCAdr->append(new QLabel("R3"));
    this->rALU->append(new QLabel("A&B"));

    for(int i = 0; i < 4; i++)
    {
        this->rAAdr->at(i)->setAlignment(Qt::AlignCenter);
        this->rBAdr->at(i)->setAlignment(Qt::AlignCenter);
        this->rCAdr->at(i)->setAlignment(Qt::AlignCenter);
        this->rALU->at(i)->setAlignment(Qt::AlignCenter);
    }
}

void MainWindow::configureMainMemoryWidgets()
{
    this->memory_label->setAlignment(Qt::AlignCenter);
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
    this->createControlUnitLayouts();
    this->createDataPathLayouts();
    this->createMainMemoryLayouts();

    this->split = new QSplitter(Qt::Vertical);

    this->mainLayoutWindow = new QWidget;

    this->mainLayout = new QHBoxLayout(this->mainLayoutWindow);
}

void MainWindow::createControlUnitLayouts()
{
    this->microInstructionLayoutWindow = new QWidget;
    this->pcirLayoutWindow = new QWidget;
    this->pcLayoutWindow = new QWidget;
    this->irLayoutWindow = new QWidget;
    this->controlUnitLayoutWindow = new QWidget;

    this->microInstructionLayout = new QGridLayout(this->microInstructionLayoutWindow);
    this->pcirLayout = new QHBoxLayout(this->pcirLayoutWindow);
    this->pcLayout = new QHBoxLayout(this->pcLayoutWindow);
    this->irLayout = new QHBoxLayout(this->irLayoutWindow);
    this->controlUnitLayout = new QVBoxLayout(this->controlUnitLayoutWindow);
}

void MainWindow::createDataPathLayouts()
{
    this->aAdrLayoutWindow = new QWidget;
    this->bAdrLayoutWindow = new QWidget;
    this->cAdrLayoutWindow = new QWidget;
    this->aluArrowLayoutWindow = new QWidget;
    this->aBusLayoutWindow = new QWidget;
    this->bBusLayoutWindow = new QWidget;
    this->cBusLayoutWindow = new QWidget;
    this->mmBusLayoutWindow = new QWidget;
    this->aBusALULayoutWindow = new QWidget;
    this->bBusALULayoutWindow = new QWidget;
    this->cBusALULayoutWindow = new QWidget;
    this->aluLayoutWindow = new QWidget;
    this->registersLayoutWindow = new QWidget;
    this->registerBankLayoutWindow = new QWidget;
    this->dataPathLayoutWindow = new QWidget;

    this->aAdrLayout = new QGridLayout(this->aAdrLayoutWindow);
    this->bAdrLayout = new QGridLayout(this->bAdrLayoutWindow);
    this->cAdrLayout = new QGridLayout(this->cAdrLayoutWindow);
    this->aluArrowLayout = new QGridLayout(this->aluArrowLayoutWindow);
    this->aBusLayout = new QVBoxLayout(this->aBusLayoutWindow);
    this->bBusLayout = new QVBoxLayout(this->bBusLayoutWindow);
    this->cBusLayout = new QVBoxLayout(this->cBusLayoutWindow);
    this->mmBusLayout = new QVBoxLayout(this->mmBusLayoutWindow);
    this->aBusALULayout = new QHBoxLayout(this->aBusALULayoutWindow);
    this->bBusALULayout = new QHBoxLayout(this->bBusALULayoutWindow);
    this->cBusALULayout = new QHBoxLayout(this->cBusALULayoutWindow);
    this->aluLayout = new QGridLayout(this->aluLayoutWindow);
    this->registersLayout = new QFormLayout(this->registersLayoutWindow);
    this->registerBankLayout = new QGridLayout(this->registerBankLayoutWindow);
    this->dataPathLayout = new QVBoxLayout(this->dataPathLayoutWindow);
}

void MainWindow::createMainMemoryLayouts()
{
    this->mainMemoryLayoutWindow = new QWidget;

    this->mainMemoryLayout = new QVBoxLayout(this->mainMemoryLayoutWindow);
}

void MainWindow::settingLayouts()
{
    this->settingControlUnitLayouts();
    this->settingDataPathLayouts();
    this->settingMainMemoryLayouts();

    this->split->setChildrenCollapsible(false);
    this->split->addWidget(this->dataPathScroll);
    this->split->addWidget(this->controlUnitScroll);

    this->mainLayout->addWidget(this->mainMemoryLayoutWindow);
    this->mainLayout->addWidget(this->split);

    this->setCentralWidget(this->mainLayoutWindow);
}

void MainWindow::settingControlUnitLayouts()
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
    this->microInstructionLayout->addWidget(this->arrowIRToMIR, 2, 4);
    this->microInstructionLayout->setRowMinimumHeight(2, 50);
    this->microInstructionLayout->setAlignment(Qt::AlignCenter);

    this->controlUnitLayout->addWidget(this->controlUnit_label);
    this->controlUnitLayout->addSpacing(50);
    this->controlUnitLayout->addWidget(this->microInstruction_label);
    this->controlUnitLayout->addWidget(this->microInstructionLayoutWindow);
    this->controlUnitLayout->addWidget(this->pcirLayoutWindow);
    this->controlUnitLayout->setAlignment(Qt::AlignCenter);

    this->controlUnitScroll->setWidget(this->controlUnitLayoutWindow);
    this->controlUnitScroll->setAlignment(Qt::AlignCenter);
}

void MainWindow::settingDataPathLayouts()
{
    this->aAdrLayout->addWidget(this->ABusAdr_label, 0, 1);
    this->aAdrLayout->addWidget(this->rAAdr->at(0), 1, 1);
    this->aAdrLayout->addWidget(this->rAAdr->at(1), 2, 2);
    this->aAdrLayout->addWidget(this->rAAdr->at(2), 3, 1);
    this->aAdrLayout->addWidget(this->rAAdr->at(3), 2, 0);
    this->aAdrLayout->addWidget(this->ballArrowAAdr, 2, 1);

    this->bAdrLayout->addWidget(this->BBusAdr_label, 0, 1);
    this->bAdrLayout->addWidget(this->rBAdr->at(0), 1, 1);
    this->bAdrLayout->addWidget(this->rBAdr->at(1), 2, 2);
    this->bAdrLayout->addWidget(this->rBAdr->at(2), 3, 1);
    this->bAdrLayout->addWidget(this->rBAdr->at(3), 2, 0);
    this->bAdrLayout->addWidget(this->ballArrowBAdr, 2, 1);

    this->cAdrLayout->addWidget(this->CBusAdr_label, 0, 1);
    this->cAdrLayout->addWidget(this->rCAdr->at(0), 1, 1);
    this->cAdrLayout->addWidget(this->rCAdr->at(1), 2, 2);
    this->cAdrLayout->addWidget(this->rCAdr->at(2), 3, 1);
    this->cAdrLayout->addWidget(this->rCAdr->at(3), 2, 0);
    this->cAdrLayout->addWidget(this->ballArrowCAdr, 2, 1);

    this->aluArrowLayout->addWidget(this->rALU->at(0), 1, 1);
    this->aluArrowLayout->addWidget(this->rALU->at(1), 2, 2);
    this->aluArrowLayout->addWidget(this->rALU->at(2), 3, 1);
    this->aluArrowLayout->addWidget(this->rALU->at(3), 2, 0);
    this->aluArrowLayout->addWidget(this->ballArrowALU, 2, 1);

    this->aBusLayout->addWidget(this->ABus_label);
    this->aBusLayout->addWidget(this->ABus_lineEdit);

    this->bBusLayout->addWidget(this->BBus_label);
    this->bBusLayout->addWidget(this->BBus_lineEdit);

    this->cBusLayout->addWidget(this->CBus_label);
    this->cBusLayout->addWidget(this->CBus_lineEdit);

    this->mmBusLayout->addWidget(this->MMBus_label);
    this->mmBusLayout->addWidget(this->MMBus_lineEdit);

    this->registersLayout->addRow(this->R0_label, this->R0_lineEdit);
    this->registersLayout->addRow(this->R1_label, this->R1_lineEdit);
    this->registersLayout->addRow(this->R2_label, this->R2_lineEdit);
    this->registersLayout->addRow(this->R3_label, this->R3_lineEdit);

    this->aBusALULayout->addWidget(this->ABusALU_label);
    this->aBusALULayout->addWidget(this->ABusALU_lineEdit);

    this->bBusALULayout->addWidget(this->BBusALU_label);
    this->bBusALULayout->addWidget(this->BBusALU_lineEdit);

    this->cBusALULayout->addWidget(this->CBusALU_label);
    this->cBusALULayout->addWidget(this->CBusALU_lineEdit);

    this->aluLayout->addWidget(new QLabel("Arietmetric Logic Unit"), 0, 0);
    this->aluLayout->addWidget(aBusALULayoutWindow, 1, 0);
    this->aluLayout->addWidget(bBusALULayoutWindow, 1, 1);
    this->aluLayout->addWidget(cBusALULayoutWindow, 2, 0);
    this->aluLayout->addWidget(aluArrowLayoutWindow, 2, 1);

    this->registerBankLayout->addWidget(this->cAdrLayoutWindow, 0, 0);
    this->registerBankLayout->addWidget(this->registersLayoutWindow, 0, 1);
    this->registerBankLayout->addWidget(this->aAdrLayoutWindow, 0, 2);
    this->registerBankLayout->addWidget(this->bAdrLayoutWindow, 0, 3);
    this->registerBankLayout->addWidget(this->arrowCBusToCAdr, 1, 0);
    this->registerBankLayout->addWidget(this->arrowAAdrToABus, 1, 2);
    this->registerBankLayout->addWidget(this->arrowBAdrToBBus, 1, 3);
    this->registerBankLayout->addWidget(this->cBusLayoutWindow, 2, 0);
    this->registerBankLayout->addWidget(this->aBusLayoutWindow, 2, 2);
    this->registerBankLayout->addWidget(this->bBusLayoutWindow, 2, 3);
    this->registerBankLayout->addWidget(this->arrowCBusToMMBus, 3, 0);
    this->registerBankLayout->addWidget(this->arrowMMBusToCBus, 3, 0);
    this->registerBankLayout->addWidget(this->arrowALUToCBus, 3, 1);
    this->registerBankLayout->addWidget(this->arrowABusToALU, 3, 2);
    this->registerBankLayout->addWidget(this->arrowBBusToALU, 3, 3);
    this->registerBankLayout->addWidget(this->mmBusLayoutWindow, 4, 0);
    this->registerBankLayout->addWidget(this->aluLayoutWindow, 4, 2, 4, 3);

    this->dataPathLayout->addWidget(this->dataPath_label);
    this->dataPathLayout->addSpacing(50);
    this->dataPathLayout->addWidget(this->registerBank_label);
    this->dataPathLayout->addWidget(this->registerBankLayoutWindow);
    this->dataPathLayout->setAlignment(Qt::AlignCenter);

    this->dataPathScroll->setWidget(this->dataPathLayoutWindow);
    this->dataPathScroll->setAlignment(Qt::AlignCenter);
}

void MainWindow::settingMainMemoryLayouts()
{
    this->mainMemoryLayout->addWidget(this->memory_label);
    this->mainMemoryLayout->addWidget(this->file_button);
    this->mainMemoryLayout->addWidget(this->tableMemory);
    this->mainMemoryLayoutWindow->setFixedWidth(270);
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
