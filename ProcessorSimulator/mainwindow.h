#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
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
    QLabel *microInstruction_label = nullptr;
    QLabel *PC_label = nullptr;
    QLabel *IR_label = nullptr;
    QLabel *AAddr_label = nullptr;
    QLabel *BAddr_label = nullptr;
    QLabel *AluOp_label = nullptr;
    QLabel *SwitchPos_label = nullptr;
    QLabel *CAddr_label = nullptr;
    QLabel *RWAddr_label = nullptr;

    QLabel *arrowIRToPC = nullptr;
    QLabel *arrowIRToMIR = nullptr;

    QLabel *controlUnit_label = nullptr;
    QLabel *dataPath_label = nullptr;
    QLabel *memory_label = nullptr;

    QPixmap *arrowBTop = nullptr;
    QPixmap *arrowBBot = nullptr;
    QPixmap *arrowBRight = nullptr;
    QPixmap *arrowBLeft = nullptr;
    QPixmap *arrowRTop = nullptr;
    QPixmap *arrowRBot = nullptr;
    QPixmap *arrowRRight = nullptr;
    QPixmap *arrowRLeft = nullptr;

    QLineEdit *PC_lineEdit = nullptr;
    QLineEdit *IR_lineEdit = nullptr;
    QLineEdit *AAddr_lineEdit = nullptr;
    QLineEdit *BAddr_lineEdit = nullptr;
    QLineEdit *AluOp_lineEdit = nullptr;
    QLineEdit *SwitchPos_lineEdit = nullptr;
    QLineEdit *CAddr_lineEdit = nullptr;
    QLineEdit *RWAddr_lineEdit = nullptr;

    QPushButton *file_button = nullptr;
    QPushButton *PC_button = nullptr;

    QFile *file = nullptr;
    QFile *file_RamMemory = nullptr;

    QSplitter *split = nullptr;

    QTableWidget *tableMemory = nullptr;

    Processor *processor = nullptr;

    QScrollArea *controlUnitScroll = nullptr;
    QScrollArea *dataPathScroll = nullptr;

    // Layouts Widgets
    QWidget *microInstructionLayoutWindow = nullptr;
    QWidget *pcirLayoutWindow = nullptr;
    QWidget *pcLayoutWindow = nullptr;
    QWidget *irLayoutWindow = nullptr;
    QWidget *controlUnitLayoutWindow = nullptr;

    QWidget *dataPathLayoutWindow = nullptr;

    QWidget *mainMemoryLayoutWindow = nullptr;

    QWidget *mainLayoutWindow = nullptr;

    // Layouts
    QGridLayout *microInstructionLayout = nullptr;
    QHBoxLayout *pcirLayout = nullptr;
    QHBoxLayout *pcLayout = nullptr;
    QHBoxLayout *irLayout = nullptr;
    QVBoxLayout *controlUnitLayout = nullptr;

    QVBoxLayout *dataPathLayout = nullptr;

    QVBoxLayout *mainMemoryLayout = nullptr;

    QHBoxLayout *mainLayout = nullptr;

protected:
    void configureWindow();
    void createWidgets();
    void configureWidgets();
    void createTableMemory();
    void createLayouts();
    void settingLayouts();
    void iniciateMemory();
    void connects();
    void verifyInstruction(QTableWidgetItem *item);

public slots:
    void darkTheme();
    void readFile();
    void textChanged(QTableWidgetItem *item);
    void sintaxeMemoryCatch(int i, int signal);

signals:
    void sintaxeMemoryThrow(int i, int signal);
};

#endif // MAINWINDOW_H
