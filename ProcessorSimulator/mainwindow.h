#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QComboBox>
#include <QDebug>
#include <QSplitter>
#include <QScrollArea>
#include <QSizePolicy>
#include <QLineEdit>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QRegularExpression>
#include <QMessageBox>
#include <QFileDialog>
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include "processor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *controlUnit_label = nullptr;
    QLabel *microInstruction_label = nullptr;
    QLabel *PC_label = nullptr;
    QLabel *IR_label = nullptr;
    QLabel *AAddr_label = nullptr;
    QLabel *BAddr_label = nullptr;
    QLabel *AluOp_label = nullptr;
    QLabel *SwitchPos_label = nullptr;
    QLabel *CAddr_label = nullptr;
    QLabel *RWAddr_label = nullptr;
    QLabel *time_label = nullptr;
    QLabel *arrowIRToPC = nullptr;
    QLabel *arrowIRToMIR = nullptr;

    QLabel *dataPath_label = nullptr;
    QLabel *registerBank_label = nullptr;
    QLabel *ABusAdr_label = nullptr;
    QLabel *BBusAdr_label = nullptr;
    QLabel *CBusAdr_label = nullptr;
    QLabel *ABus_label = nullptr;
    QLabel *BBus_label = nullptr;
    QLabel *CBus_label = nullptr;
    QLabel *MMBus_label = nullptr;
    QLabel *R0_label = nullptr;
    QLabel *R1_label = nullptr;
    QLabel *R2_label = nullptr;
    QLabel *R3_label = nullptr;
    QLabel *ABusALU_label = nullptr;
    QLabel *BBusALU_label = nullptr;
    QLabel *CBusALU_label = nullptr;
    QLabel *ALU_label = nullptr;
    QLabel *arrowAAdrToABus = nullptr;
    QLabel *arrowBAdrToBBus = nullptr;
    QLabel *arrowABusToALU = nullptr;
    QLabel *arrowBBusToALU = nullptr;
    QLabel *arrowALUToCBus = nullptr;
    QLabel *arrowCBusToMMBus = nullptr;
    QLabel *arrowMMBusToCBus = nullptr;
    QLabel *arrowCBusToCAdr = nullptr;
    QLabel *ballArrowAAdr = nullptr;
    QLabel *ballArrowBAdr = nullptr;
    QLabel *ballArrowCAdr = nullptr;
    QLabel *ballArrowALU = nullptr;
    QVector<QLabel*> *rAAdr = nullptr;
    QVector<QLabel*> *rBAdr = nullptr;
    QVector<QLabel*> *rCAdr = nullptr;
    QVector<QLabel*> *rALU = nullptr;

    QLabel *memory_label = nullptr;

    QVector<QPixmap*> *arrowBlue = nullptr;
    QVector<QPixmap*> *arrowRed = nullptr;
    QVector<QPixmap*> *ballArrow = nullptr;

    QLineEdit *PC_lineEdit = nullptr;
    QLineEdit *IR_lineEdit = nullptr;
    QLineEdit *AAddr_lineEdit = nullptr;
    QLineEdit *BAddr_lineEdit = nullptr;
    QLineEdit *AluOp_lineEdit = nullptr;
    QLineEdit *SwitchPos_lineEdit = nullptr;
    QLineEdit *CAddr_lineEdit = nullptr;
    QLineEdit *RWAddr_lineEdit = nullptr;

    QVector<QLineEdit*> *R_lineEdit = nullptr;
    QLineEdit *ABus_lineEdit = nullptr;
    QLineEdit *BBus_lineEdit = nullptr;
    QLineEdit *CBus_lineEdit = nullptr;
    QLineEdit *MMBus_lineEdit = nullptr;
    QLineEdit *ABusALU_lineEdit = nullptr;
    QLineEdit *BBusALU_lineEdit = nullptr;
    QLineEdit *CBusALU_lineEdit = nullptr;

    QPushButton *file_button = nullptr;
    QPushButton *resetPC_button = nullptr;
    QPushButton *execute_button = nullptr;
    QPushButton *halt_button = nullptr;

    QComboBox *time_comboBox = nullptr;

    QFile *file = nullptr;
    QFile *file_RamMemory = nullptr;
    QFile *file_PCIR = nullptr;
    QFile *file_registers = nullptr;

    QSplitter *split = nullptr;

    QTableWidget *tableMemory = nullptr;

    Processor *processor = nullptr;

    QScrollArea *controlUnitScroll = nullptr;
    QScrollArea *dataPathScroll = nullptr;

    // Layouts Widgets
    QWidget *buttonsLayoutWindow = nullptr;
    QWidget *microInstructionLayoutWindow = nullptr;
    QWidget *microVInstructionLayoutWindow = nullptr;
    QWidget *microHInstructionLayoutWindow = nullptr;
    QWidget *pcirLayoutWindow = nullptr;
    QWidget *pcLayoutWindow = nullptr;
    QWidget *irLayoutWindow = nullptr;
    QWidget *controlUnitLayoutWindow = nullptr;

    QWidget *aAdrLayoutWindow = nullptr;
    QWidget *bAdrLayoutWindow = nullptr;
    QWidget *cAdrLayoutWindow = nullptr;
    QWidget *aluArrowLayoutWindow = nullptr;
    QWidget *aBusLayoutWindow = nullptr;
    QWidget *bBusLayoutWindow = nullptr;
    QWidget *cBusLayoutWindow = nullptr;
    QWidget *mmBusLayoutWindow = nullptr;
    QWidget *aBusALULayoutWindow = nullptr;
    QWidget *bBusALULayoutWindow = nullptr;
    QWidget *cBusALULayoutWindow = nullptr;
    QWidget *aluFormLayoutWindow = nullptr;
    QWidget *aluVLayoutWindow = nullptr;
    QWidget *registersLayoutWindow = nullptr;
    QWidget *registerBankLayoutWindow = nullptr;
    QWidget *dataPathLayoutWindow = nullptr;

    QWidget *mainMemoryLayoutWindow = nullptr;

    QWidget *mainLayoutWindow = nullptr;

    // Layouts
    QVBoxLayout *buttonsLayout = nullptr;
    QGridLayout *microInstructionLayout = nullptr;
    QVBoxLayout *microVInstructionLayout = nullptr;
    QHBoxLayout *microHInstructionLayout = nullptr;
    QHBoxLayout *pcirLayout = nullptr;
    QHBoxLayout *pcLayout = nullptr;
    QHBoxLayout *irLayout = nullptr;
    QVBoxLayout *controlUnitLayout = nullptr;

    QGridLayout *aAdrLayout = nullptr;
    QGridLayout *bAdrLayout = nullptr;
    QGridLayout *cAdrLayout = nullptr;
    QGridLayout *aluArrowLayout = nullptr;
    QVBoxLayout *aBusLayout = nullptr;
    QVBoxLayout *bBusLayout = nullptr;
    QVBoxLayout *cBusLayout = nullptr;
    QVBoxLayout *mmBusLayout = nullptr;
    QHBoxLayout *aBusALULayout = nullptr;
    QHBoxLayout *bBusALULayout = nullptr;
    QHBoxLayout *cBusALULayout = nullptr;
    QFormLayout *aluFormLayout = nullptr;
    QVBoxLayout *aluVLayout = nullptr;
    QFormLayout *registersLayout = nullptr;
    QGridLayout *registerBankLayout = nullptr;
    QVBoxLayout *dataPathLayout = nullptr;

    QVBoxLayout *mainMemoryLayout = nullptr;

    QHBoxLayout *mainLayout = nullptr;

protected:
    void configureWindow();

    void createWidgets();
    void createControlUnitWidgets();
    void createDataPathWidgets();
    void createMainMemoryWidgets();

    void configureWidgets();
    void configureControlUnitWidgets();
    void configureDataPathWidgets();
    void configureMainMemoryWidgets();
    void createTableMemory();

    void createLayouts();
    void createControlUnitLayouts();
    void createDataPathLayouts();
    void createMainMemoryLayouts();

    void settingLayouts();
    void settingControlUnitLayouts();
    void settingDataPathLayouts();
    void settingMainMemoryLayouts();

    void connects();

    void verifyInstruction(QTableWidgetItem *item);

public slots:
    void darkTheme();
    void created_files();
    void readFile();
    void textChanged(QTableWidgetItem *item);
    void sintaxeMemoryCatch(int i, int signal);

    void resetPC();
    void execute();
    void halt();

    void instructionUpdated();
    void irUpdated();
    void arrowsControlUnitUpdated();
    void pcUpdated();
    void controlUnitUpdated();
    void Aaddr_BaddrUpdated();
    void ABus_BBusUpdated();
    void ALU_1Updated();
    void ALU_2Updated();
    void ArrowAluToCBusUpdated();
    void CBusUpdated();
    void ArrowCBusToMMBusUpdated();
    void MMBusUpdated();
    void MainMemoryUpdated();
    void ArrowMMBusToCBusUpdated();
    void ArrowCBusToCAdrUpdated();
    void RegistersUpdated();

signals:
    void sintaxeMemoryThrow(int i, int signal);
};

#endif // MAINWINDOW_H
