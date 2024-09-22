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
    delete this->ALU_label;
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

    this->arrowBlue->clear();
    delete this->arrowBlue;
    this->arrowRed->clear();
    delete this->arrowRed;
    this->ballArrow->clear();
    delete this->ballArrow;

    delete this->PC_lineEdit;
    delete this->IR_lineEdit;
    delete this->AAddr_lineEdit;
    delete this->BAddr_lineEdit;
    delete this->AluOp_lineEdit;
    delete this->SwitchPos_lineEdit;
    delete this->CAddr_lineEdit;
    delete this->RWAddr_lineEdit;

    this->R_lineEdit->clear();
    delete this->R_lineEdit;

    delete this->ABus_lineEdit;
    delete this->BBus_lineEdit;
    delete this->CBus_lineEdit;
    delete this->MMBus_lineEdit;
    delete this->ABusALU_lineEdit;
    delete this->BBusALU_lineEdit;
    delete this->CBusALU_lineEdit;

    delete this->file_button;
    delete this->resetPC_button;
    delete this->execute_button;

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
    delete this->aluFormLayout;
    delete this->aluFormLayoutWindow;
    delete this->aluVLayout;
    delete this->aluVLayoutWindow;
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

    this->arrowBlue = new QVector<QPixmap*>;
    this->arrowRed = new QVector<QPixmap*>;
    this->ballArrow = new QVector<QPixmap*>;
    this->arrowBlue->append(new QPixmap(":/img/ArrowBTop.png"));
    this->arrowBlue->append(new QPixmap(":/img/ArrowBRight.png"));
    this->arrowBlue->append(new QPixmap(":/img/ArrowBBot.png"));
    this->arrowBlue->append(new QPixmap(":/img/ArrowBLeft.png"));
    this->arrowBlue->append(new QPixmap(":/img/ArrowBTopLeft.png"));
    this->arrowRed->append(new QPixmap(":/img/ArrowRTop.png"));
    this->arrowRed->append(new QPixmap(":/img/ArrowRRight.png"));
    this->arrowRed->append(new QPixmap(":/img/ArrowRBot.png"));
    this->arrowRed->append(new QPixmap(":/img/ArrowRLeft.png"));
    this->arrowRed->append(new QPixmap(":/img/ArrowRTopLeft.png"));
    this->ballArrow->append(new QPixmap(":/img/BallArrowTop.png"));
    this->ballArrow->append(new QPixmap(":/img/BallArrowRight.png"));
    this->ballArrow->append(new QPixmap(":/img/BallArrowBot.png"));
    this->ballArrow->append(new QPixmap(":/img/BallArrowLeft.png"));

    this->processor = new Processor(this);
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

    this->resetPC_button = new QPushButton("Reset");

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
    this->ALU_label = new QLabel("Arithmetic and Logic Unit (ALU)");
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
    this->rALU->append(new QLabel("A&B"));
    this->rAAdr->append(new QLabel("R3"));
    this->rBAdr->append(new QLabel("R3"));
    this->rCAdr->append(new QLabel("R3"));
    this->rALU->append(new QLabel("A|B"));

    this->R_lineEdit = new QVector<QLineEdit*>;
    this->R_lineEdit->append(new QLineEdit("0"));
    this->R_lineEdit->append(new QLineEdit("0"));
    this->R_lineEdit->append(new QLineEdit("0"));
    this->R_lineEdit->append(new QLineEdit("0"));

    this->ABus_lineEdit = new QLineEdit("0");
    this->BBus_lineEdit = new QLineEdit("0");
    this->CBus_lineEdit = new QLineEdit("0");
    this->MMBus_lineEdit = new QLineEdit("0");
    this->ABusALU_lineEdit = new QLineEdit("0");
    this->BBusALU_lineEdit = new QLineEdit("0");
    this->CBusALU_lineEdit = new QLineEdit("0");

    this->execute_button = new QPushButton("Execute");

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

    this->arrowIRToPC->setPixmap(arrowBlue->at(3)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowIRToMIR->setPixmap(arrowBlue->at(0)->scaled(30, 30, Qt::KeepAspectRatio));

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

    this->PC_lineEdit->setReadOnly(true);
    this->IR_lineEdit->setReadOnly(true);
    this->AAddr_lineEdit->setReadOnly(true);
    this->BAddr_lineEdit->setReadOnly(true);
    this->AluOp_lineEdit->setReadOnly(true);
    this->SwitchPos_lineEdit->setReadOnly(true);
    this->CAddr_lineEdit->setReadOnly(true);
    this->RWAddr_lineEdit->setReadOnly(true);

    this->resetPC_button->setFixedWidth(60);
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
    this->ALU_label->setAlignment(Qt::AlignCenter);

    this->arrowAAdrToABus->setPixmap(arrowBlue->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowBAdrToBBus->setPixmap(arrowBlue->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowABusToALU->setPixmap(arrowBlue->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowBBusToALU->setPixmap(arrowBlue->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowALUToCBus->setPixmap(arrowBlue->at(4)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowCBusToMMBus->setPixmap(arrowBlue->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowMMBusToCBus->setPixmap(arrowBlue->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowCBusToCAdr->setPixmap(arrowBlue->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowAAdr->setPixmap(ballArrow->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowBAdr->setPixmap(ballArrow->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowCAdr->setPixmap(ballArrow->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowALU->setPixmap(ballArrow->at(0)->scaled(30, 30, Qt::KeepAspectRatio));

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

    for(int i = 0; i < 4; i++)
    {
        this->rAAdr->at(i)->setAlignment(Qt::AlignCenter);
        this->rBAdr->at(i)->setAlignment(Qt::AlignCenter);
        this->rCAdr->at(i)->setAlignment(Qt::AlignCenter);
        this->rALU->at(i)->setAlignment(Qt::AlignCenter);
    }

    this->R_lineEdit->at(0)->setReadOnly(true);
    this->R_lineEdit->at(1)->setReadOnly(true);
    this->R_lineEdit->at(2)->setReadOnly(true);
    this->R_lineEdit->at(3)->setReadOnly(true);
    this->ABus_lineEdit->setReadOnly(true);
    this->BBus_lineEdit->setReadOnly(true);
    this->CBus_lineEdit->setReadOnly(true);
    this->MMBus_lineEdit->setReadOnly(true);
    this->ABusALU_lineEdit->setReadOnly(true);
    this->BBusALU_lineEdit->setReadOnly(true);
    this->CBusALU_lineEdit->setReadOnly(true);
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
    this->aluFormLayoutWindow = new QWidget;
    this->aluVLayoutWindow = new QWidget;
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
    this->aluFormLayout = new QFormLayout(this->aluFormLayoutWindow);
    this->aluVLayout = new QVBoxLayout(this->aluVLayoutWindow);
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
    this->pcLayout->addWidget(this->resetPC_button);

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
    this->controlUnitLayout->addSpacing(30);
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

    this->registersLayout->addRow(this->R0_label, this->R_lineEdit->at(0));
    this->registersLayout->addRow(this->R1_label, this->R_lineEdit->at(1));
    this->registersLayout->addRow(this->R2_label, this->R_lineEdit->at(2));
    this->registersLayout->addRow(this->R3_label, this->R_lineEdit->at(3));

    this->aBusALULayout->addWidget(this->ABusALU_label);
    this->aBusALULayout->addWidget(this->ABusALU_lineEdit);

    this->bBusALULayout->addWidget(this->BBusALU_label);
    this->bBusALULayout->addWidget(this->BBusALU_lineEdit);

    this->cBusALULayout->addWidget(this->CBusALU_label);
    this->cBusALULayout->addWidget(this->CBusALU_lineEdit);

    this->aluFormLayout->addRow(this->aBusALULayoutWindow, this->bBusALULayoutWindow);
    this->aluFormLayout->addRow(this->cBusALULayoutWindow, this->aluArrowLayoutWindow);

    this->aluVLayout->addWidget(this->ALU_label);
    this->aluVLayout->addWidget(this->aluFormLayoutWindow);

    this->registerBankLayout->addWidget(this->cAdrLayoutWindow, 0, 0);
    this->registerBankLayout->addWidget(this->registersLayoutWindow, 0, 1);
    this->registerBankLayout->addWidget(this->aAdrLayoutWindow, 0, 2);
    this->registerBankLayout->addWidget(this->bAdrLayoutWindow, 0, 3);
    this->registerBankLayout->addWidget(this->arrowCBusToCAdr, 1, 0);
    this->registerBankLayout->addWidget(this->arrowAAdrToABus, 1, 2);
    this->registerBankLayout->addWidget(this->arrowBAdrToBBus, 1, 3);
    this->registerBankLayout->addWidget(this->cBusLayoutWindow, 2, 0);
    this->registerBankLayout->addWidget(this->execute_button, 2, 1);
    this->registerBankLayout->addWidget(this->aBusLayoutWindow, 2, 2);
    this->registerBankLayout->addWidget(this->bBusLayoutWindow, 2, 3);
    this->registerBankLayout->addWidget(this->arrowCBusToMMBus, 3, 0);
    this->registerBankLayout->addWidget(this->arrowMMBusToCBus, 3, 0);
    this->registerBankLayout->addWidget(this->arrowALUToCBus, 3, 1);
    this->registerBankLayout->addWidget(this->arrowABusToALU, 3, 2);
    this->registerBankLayout->addWidget(this->arrowBBusToALU, 3, 3);
    this->registerBankLayout->addWidget(this->mmBusLayoutWindow, 4, 0);
    this->registerBankLayout->addWidget(this->aluVLayoutWindow, 4, 2, 4, 3);

    this->dataPathLayout->addWidget(this->dataPath_label);
    this->dataPathLayout->addSpacing(30);
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
    QObject::connect(this->resetPC_button, &QPushButton::clicked, this, &MainWindow::resetPC);
    QObject::connect(this->execute_button, &QPushButton::clicked, this, &MainWindow::execute);
    QObject::connect(this->file_button, &QPushButton::clicked, this, &MainWindow::readFile);
    QObject::connect(this->tableMemory, &QTableWidget::itemChanged, this, &MainWindow::textChanged);

    QObject::connect(this->processor, &Processor::updateInstruction, this, &MainWindow::instructionUpdated);
    QObject::connect(this->processor, &Processor::updateIR, this, &MainWindow::irUpdated);
    QObject::connect(this->processor, &Processor::updateArrowsControlUnit, this, &MainWindow::arrowsControlUnitUpdated);
    QObject::connect(this->processor, &Processor::updatePC, this, &MainWindow::pcUpdated);
    QObject::connect(this->processor, &Processor::updateControlUnit, this, &MainWindow::controlUnitUpdated);
    QObject::connect(this->processor, &Processor::updateAaddr_Baddr, this, &MainWindow::Aaddr_BaddrUpdated);
    QObject::connect(this->processor, &Processor::updateABus_BBus, this, &MainWindow::ABus_BBusUpdated);
    QObject::connect(this->processor, &Processor::updateALU_1, this, &MainWindow::ALU_1Updated);
    QObject::connect(this->processor, &Processor::updateALU_2, this, &MainWindow::ALU_2Updated);
    QObject::connect(this->processor, &Processor::updateArrowAluToCBus, this, &MainWindow::ArrowAluToCBusUpdated);
    QObject::connect(this->processor, &Processor::updateCBus, this, &MainWindow::CBusUpdated);
    QObject::connect(this->processor, &Processor::updateArrowCBusToMMBus, this, &MainWindow::ArrowCBusToMMBusUpdated);
    QObject::connect(this->processor, &Processor::updateMMBus, this, &MainWindow::MMBusUpdated);
    QObject::connect(this->processor, &Processor::updateMainMemory, this, &MainWindow::MainMemoryUpdated);
    QObject::connect(this->processor, &Processor::updateArrowMMBusToCBus, this, &MainWindow::ArrowMMBusToCBusUpdated);
    QObject::connect(this->processor, &Processor::updateArrowCBusToCAdr, this, &MainWindow::ArrowCBusToCAdrUpdated);
    QObject::connect(this->processor, &Processor::updateRegisters, this, &MainWindow::RegistersUpdated);
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

    int i = 0;

    for(; ((!in.atEnd()) && (i < 32)); i++)
    {
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

    for(; i < 32; i++)
    {
        tableMemory->item(i, 1)->setText("0");
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
            this->tableMemory->item(i, 2)->setText("Syntax Error");
            this->tableMemory->item(i, 2)->setForeground(QBrush(QColor(255, 0, 0)));
            break;
        }
    }
}

void MainWindow::resetPC()
{
    this->processor->controlUnit->PC = 0;
    this->PC_lineEdit->setText(QString::number(this->processor->controlUnit->PC));
}

void MainWindow::execute()
{
    for(int i = 0; i < 32; i++)
    {
        if(this->tableMemory->item(i,2)->text() == "Syntax Error")
        {
            QMessageBox::information(this,"Error","Syntax Error at Main Memory");
            return;
        }
    }

    for(int i = 0; i < 32; i++)
    {
        this->processor->mainMemory->replace(i, this->tableMemory->item(i, 1)->text());
    }

    this->processor->clock();

    return;
}

void MainWindow::instructionUpdated()
{
    // Pisca PC
    // Pisca Linha da Main Memory
    this->PC_lineEdit->setStyleSheet("color: red;");
    this->processor->delay(this->processor->time);
    this->PC_lineEdit->setStyleSheet("color: black;");

    this->tableMemory->item(this->processor->controlUnit->PC, 1)->setForeground(QBrush(QColor(255, 0, 0)));
    this->processor->delay(this->processor->time);
    this->tableMemory->item(this->processor->controlUnit->PC, 1)->setForeground(QBrush(QColor(0, 0, 0)));

}

void MainWindow::irUpdated()
{
    this->IR_lineEdit->setText(this->processor->controlUnit->IR);

    this->IR_lineEdit->setStyleSheet("color: red;");
    this->processor->delay(this->processor->time);
    this->IR_lineEdit->setStyleSheet("color: black;");
}

void MainWindow::arrowsControlUnitUpdated()
{
    // Pisca ArrowIRtoPC
    this->arrowIRToPC->setPixmap(arrowRed->at(3)->scaled(30, 30, Qt::KeepAspectRatio));
    if(this->processor->cicle_dataPath)
    {
        // Pisca ArrowIRtoMIR
        this->arrowIRToMIR->setPixmap(arrowRed->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
    }

    this->processor->delay(this->processor->time);

    this->arrowIRToPC->setPixmap(arrowBlue->at(3)->scaled(30, 30, Qt::KeepAspectRatio));
    if(this->processor->cicle_dataPath)
    {
        this->arrowIRToMIR->setPixmap(arrowBlue->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
    }
}

void MainWindow::pcUpdated()
{
    this->PC_lineEdit->setText(QString::number(this->processor->controlUnit->PC));

    this->PC_lineEdit->setStyleSheet("color: red;");
    this->processor->delay(this->processor->time);
    this->PC_lineEdit->setStyleSheet("color: black;");
}

void MainWindow::controlUnitUpdated()
{
    this->PC_lineEdit->setText(QString::number(this->processor->controlUnit->PC));

    this->PC_lineEdit->setStyleSheet("color: red;");

    if(this->processor->cicle_dataPath)
    {
        this->AAddr_lineEdit->setText(this->processor->controlUnit->AAddr);
        this->BAddr_lineEdit->setText(this->processor->controlUnit->BAddr);
        this->AluOp_lineEdit->setText(this->processor->controlUnit->UlaOp);
        this->SwitchPos_lineEdit->setText(this->processor->controlUnit->SwitchPos);
        this->CAddr_lineEdit->setText(this->processor->controlUnit->CAddr);
        this->RWAddr_lineEdit->setText(this->processor->controlUnit->RWAddr);

        this->AAddr_lineEdit->setStyleSheet("color: red;");
        this->BAddr_lineEdit->setStyleSheet("color: red;");
        this->AluOp_lineEdit->setStyleSheet("color: red;");
        this->SwitchPos_lineEdit->setStyleSheet("color: red;");
        this->CAddr_lineEdit->setStyleSheet("color: red;");
        this->RWAddr_lineEdit->setStyleSheet("color: red;");
    }

    this->processor->delay(this->processor->time);

    if(this->processor->cicle_dataPath)
    {
        this->AAddr_lineEdit->setStyleSheet("color: black;");
        this->BAddr_lineEdit->setStyleSheet("color: black;");
        this->AluOp_lineEdit->setStyleSheet("color: black;");
        this->SwitchPos_lineEdit->setStyleSheet("color: black;");
        this->CAddr_lineEdit->setStyleSheet("color: black;");
        this->RWAddr_lineEdit->setStyleSheet("color: black;");
    }

    this->PC_lineEdit->setStyleSheet("color: black;");

    //Arrumar BallArrows
    this->ballArrowAAdr->setPixmap(ballArrow->at(this->processor->binToDec(this->processor->controlUnit->AAddr))->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowBAdr->setPixmap(ballArrow->at(this->processor->binToDec(this->processor->controlUnit->BAddr))->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowCAdr->setPixmap(ballArrow->at(this->processor->binToDec(this->processor->controlUnit->CAddr))->scaled(30, 30, Qt::KeepAspectRatio));
    this->ballArrowALU->setPixmap(ballArrow->at(this->processor->binToDec(this->processor->controlUnit->UlaOp))->scaled(30, 30, Qt::KeepAspectRatio));
}

void MainWindow::Aaddr_BaddrUpdated()
{
    // Pisca Registradores q são usados
    this->R_lineEdit->at(this->processor->binToDec(this->processor->controlUnit->AAddr))->setText(QString::number(this->processor->dataPath->R[this->processor->binToDec(this->processor->controlUnit->AAddr)]));
    this->R_lineEdit->at(this->processor->binToDec(this->processor->controlUnit->BAddr))->setText(QString::number(this->processor->dataPath->R[this->processor->binToDec(this->processor->controlUnit->BAddr)]));

    this->R_lineEdit->at(this->processor->binToDec(this->processor->controlUnit->AAddr))->setStyleSheet("color: red;");
    this->R_lineEdit->at(this->processor->binToDec(this->processor->controlUnit->BAddr))->setStyleSheet("color: red;");
    this->processor->delay(this->processor->time);
    this->R_lineEdit->at(this->processor->binToDec(this->processor->controlUnit->AAddr))->setStyleSheet("color: black;");
    this->R_lineEdit->at(this->processor->binToDec(this->processor->controlUnit->BAddr))->setStyleSheet("color: black;");

    // Pisca Arrow AAdr to Abus e  Arrow BAdr to Bbus
    this->arrowAAdrToABus->setPixmap(arrowRed->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowBAdrToBBus->setPixmap(arrowRed->at(2)->scaled(30, 30, Qt::KeepAspectRatio));

    this->processor->delay(this->processor->time);

    this->arrowAAdrToABus->setPixmap(arrowBlue->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowBAdrToBBus->setPixmap(arrowBlue->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
}

void MainWindow::ABus_BBusUpdated()
{
    // Pisca Abus e Bbus
    this->ABus_lineEdit->setText(QString::number(this->processor->dataPath->ABus));
    this->BBus_lineEdit->setText(QString::number(this->processor->dataPath->BBus));

    this->ABus_lineEdit->setStyleSheet("color: red;");
    this->BBus_lineEdit->setStyleSheet("color: red;");
    this->processor->delay(this->processor->time);
    this->ABus_lineEdit->setStyleSheet("color: black;");
    this->BBus_lineEdit->setStyleSheet("color: black;");

    // Pisca Arrow AbusToalu e Arrow BbusToalu
    this->arrowABusToALU->setPixmap(arrowRed->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowBBusToALU->setPixmap(arrowRed->at(2)->scaled(30, 30, Qt::KeepAspectRatio));

    this->processor->delay(this->processor->time);

    this->arrowABusToALU->setPixmap(arrowBlue->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
    this->arrowBBusToALU->setPixmap(arrowBlue->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
}

void MainWindow::ALU_1Updated()
{
    // Pisca alu->a e alu->b
    this->ABusALU_lineEdit->setText(QString::number(this->processor->dataPath->alu->A));
    this->BBusALU_lineEdit->setText(QString::number(this->processor->dataPath->alu->B));

    this->ABusALU_lineEdit->setStyleSheet("color: red;");
    this->BBusALU_lineEdit->setStyleSheet("color: red;");
    this->processor->delay(this->processor->time);
    this->ABusALU_lineEdit->setStyleSheet("color: black;");
    this->BBusALU_lineEdit->setStyleSheet("color: black;");
}

void MainWindow::ALU_2Updated()
{
    // pisca alu->c
    this->CBusALU_lineEdit->setText(QString::number(this->processor->dataPath->alu->C));

    this->CBusALU_lineEdit->setStyleSheet("color: red;");
    this->processor->delay(this->processor->time);
    this->CBusALU_lineEdit->setStyleSheet("color: black;");
}

void MainWindow::ArrowAluToCBusUpdated()
{
    // pisca alu to c
    this->arrowALUToCBus->setPixmap(arrowRed->at(4)->scaled(30, 30, Qt::KeepAspectRatio));

    this->processor->delay(this->processor->time);

    this->arrowALUToCBus->setPixmap(arrowBlue->at(4)->scaled(30, 30, Qt::KeepAspectRatio));
}

void MainWindow::CBusUpdated()
{
    // pisca c bus
    this->CBus_lineEdit->setText(QString::number(this->processor->dataPath->CBus));

    this->CBus_lineEdit->setStyleSheet("color: red;");
    this->processor->delay(this->processor->time);
    this->CBus_lineEdit->setStyleSheet("color: black;");
}

void MainWindow::ArrowCBusToMMBusUpdated()
{
    // pisca c to mm
    this->arrowCBusToMMBus->setPixmap(arrowRed->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
    this->processor->delay(this->processor->time);
    this->arrowCBusToMMBus->setPixmap(arrowBlue->at(2)->scaled(30, 30, Qt::KeepAspectRatio));
}

void MainWindow::MMBusUpdated()
{
    // pisca mm bus
    this->MMBus_lineEdit->setText(QString::number(this->processor->dataPath->MainMemoryBus));

    this->MMBus_lineEdit->setStyleSheet("color: red;");
    this->processor->delay(this->processor->time);
    this->MMBus_lineEdit->setStyleSheet("color: black;");
}

void MainWindow::MainMemoryUpdated()
{
    // pisca mm
    this->tableMemory->item(this->processor->binToDec(this->processor->controlUnit->RWAddr), 1)->setText(QString::number(this->processor->dataPath->MainMemoryBus));

    this->tableMemory->item(this->processor->binToDec(this->processor->controlUnit->RWAddr), 1)->setForeground(QBrush(QColor(255, 0, 0)));
    this->processor->delay(this->processor->time);
    this->tableMemory->item(this->processor->binToDec(this->processor->controlUnit->RWAddr), 1)->setForeground(QBrush(QColor(0, 0, 0)));
}

void MainWindow::ArrowMMBusToCBusUpdated()
{
    // pisca mm to c
    this->arrowMMBusToCBus->setPixmap(arrowRed->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
    this->processor->delay(this->processor->time);
    this->arrowMMBusToCBus->setPixmap(arrowBlue->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
}

void MainWindow::ArrowCBusToCAdrUpdated()
{
    //pisca cbus to cadr
    this->arrowCBusToCAdr->setPixmap(arrowRed->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
    this->processor->delay(this->processor->time);
    this->arrowCBusToCAdr->setPixmap(arrowBlue->at(0)->scaled(30, 30, Qt::KeepAspectRatio));
}

void MainWindow::RegistersUpdated()
{
    // pisca registrador
    this->R_lineEdit->at(this->processor->binToDec(this->processor->controlUnit->CAddr))->setText(QString::number(this->processor->dataPath->R[this->processor->binToDec(this->processor->controlUnit->CAddr)]));

    this->R_lineEdit->at(this->processor->binToDec(this->processor->controlUnit->CAddr))->setStyleSheet("color: red;");
    this->processor->delay(this->processor->time);
    this->R_lineEdit->at(this->processor->binToDec(this->processor->controlUnit->CAddr))->setStyleSheet("color: black;");
}
