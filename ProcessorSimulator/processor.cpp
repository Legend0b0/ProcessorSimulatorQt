#include "processor.h"

Processor::Processor(QObject*)
{
    this->controlUnit = new ControlUnit;
    this->dataPath = new DataPath;
    this->mainMemory = new QStringList;

    this->mainMemory->fill("0", 32);
}

Processor::~Processor()
{
    delete this->controlUnit;
    delete this->dataPath;
    delete this->mainMemory;
}

int Processor::binToDec(QString bin)
{
    bool ok;

    return(bin.toInt(&ok, 2));
}

QString Processor::decToBin(int dec, int bits)
{
    QString bin;

    bin.setNum(dec, 2);

    while(bin.size() < bits)
    {
        bin.prepend('0');
    }

    return(bin);
}

void Processor::instructionInterpretation()
{
    if(this->controlUnit->IR.startsWith("LOAD"))
    {
        this->LOAD();
        return;
    }
    if(this->controlUnit->IR.startsWith("STORE"))
    {
        this->STORE();
        return;
    }
    if(this->controlUnit->IR.startsWith("MOVE"))
    {
        this->MOVE();
        return;
    }
    if(this->controlUnit->IR.startsWith("ADD"))
    {
        this->ADD();
        return;
    }
    if(this->controlUnit->IR.startsWith("SUB"))
    {
        this->SUB();
        return;
    }
    if(this->controlUnit->IR.startsWith("AND"))
    {
        this->AND();
        return;
    }
    if(this->controlUnit->IR.startsWith("OR"))
    {
        this->OR();
        return;
    }
    if(this->controlUnit->IR.startsWith("BRANCH"))
    {
        this->BRANCH();
        return;
    }
    if(this->controlUnit->IR.startsWith("BZERO"))
    {
        this->BZERO();
        return;
    }
    if(this->controlUnit->IR.startsWith("BNEG"))
    {
        this->BNEG();
        return;
    }
    if(this->controlUnit->IR.startsWith("HALT"))
    {
        this->HALT();
        return;
    }
    if(this->controlUnit->IR.startsWith("NOP"))
    {
        this->NOP();
        return;
    }

    this->NOP();
    return;
}

void Processor::clock()
{
    while(!this->halt)
    {
        this->controlUnit->IR.clear();
        this->controlUnit->IR.append(this->mainMemory->at(this->controlUnit->PC));

        this->instructionInterpretation();

        if((!this->halt) && (this->cicle_dataPath))
        {
            if(++this->controlUnit->PC == 32)
            {
                this->controlUnit->PC = 0;
            }

            emit this->throwPC();
            emit this->throwControlUnit();

            // dataPath cicle
            this->dataPath->ABus = this->dataPath->R[this->binToDec(this->controlUnit->AAddr)];
            this->dataPath->BBus = this->dataPath->R[this->binToDec(this->controlUnit->BAddr)];

            this->dataPath->alu->A = this->dataPath->ABus;
            this->dataPath->alu->B = this->dataPath->BBus;

            this->dataPath->alu->Op[this->binToDec(this->controlUnit->UlaOp)];

            if(this->controlUnit->SwitchPos[3] == '1')
            {
                this->dataPath->CBus = this->dataPath->alu->C;
            }

            if(this->controlUnit->SwitchPos[1] == '1')
            {
                this->dataPath->CBus = this->dataPath->MainMemoryBus;
            }
            else if(this->controlUnit->SwitchPos[2] == '1')
            {
                this->dataPath->MainMemoryBus = this->dataPath->CBus;
            }

            if(this->controlUnit->SwitchPos[0] == '1')
            {
                this->dataPath->R[this->binToDec(this->controlUnit->CAddr)] = this->dataPath->CBus = this->dataPath->CBus;
            }
        }
    }
}

void Processor::LOAD()
{
    QStringList inst = this->controlUnit->IR.split(' ');
    inst[1].removeFirst();

    this->controlUnit->AAddr = this->decToBin(0, 2);
    this->controlUnit->BAddr = this->decToBin(0, 2);
    this->controlUnit->UlaOp = this->decToBin(0, 2);
    this->controlUnit->SwitchPos = "1010";
    this->controlUnit->CAddr = this->decToBin(inst[1].toInt(), 2);
    this->controlUnit->RWAddr = this->decToBin(inst[2].toInt(), 5);

    this->cicle_dataPath = true;
}

void Processor::STORE()
{
    QStringList inst = this->controlUnit->IR.split(" ");
    inst[2].removeFirst();

    this->controlUnit->AAddr = this->decToBin(inst[2].toInt(), 2);
    this->controlUnit->BAddr = this->decToBin(inst[2].toInt(), 2);
    this->controlUnit->UlaOp = this->decToBin(1, 2);
    this->controlUnit->SwitchPos = "0101";
    this->controlUnit->CAddr = this->decToBin(0, 2);
    this->controlUnit->RWAddr = this->decToBin(inst[1].toInt(), 5);

    this->cicle_dataPath = true;
}

void Processor::MOVE()
{
    QStringList inst = this->controlUnit->IR.split(" ");
    inst[1].removeFirst();
    inst[2].removeFirst();

    this->controlUnit->AAddr = this->decToBin(inst[2].toInt(), 2);
    this->controlUnit->BAddr = this->decToBin(inst[2].toInt(), 2);
    this->controlUnit->UlaOp = this->decToBin(1, 2);
    this->controlUnit->SwitchPos = "1001";
    this->controlUnit->CAddr = this->decToBin(inst[1].toInt(), 2);
    this->controlUnit->RWAddr = this->decToBin(0, 5);
}

void Processor::ADD()
{
    QStringList inst = this->controlUnit->IR.split(" ");
    inst[1].removeFirst();
    inst[2].removeFirst();
    inst[3].removeFirst();

    this->controlUnit->AAddr = this->decToBin(inst[2].toInt(), 2);
    this->controlUnit->BAddr = this->decToBin(inst[3].toInt(), 2);
    this->controlUnit->UlaOp = this->decToBin(0, 2);
    this->controlUnit->SwitchPos = "1001";
    this->controlUnit->CAddr = this->decToBin(inst[1].toInt(), 2);
    this->controlUnit->RWAddr = this->decToBin(0, 5);

    this->cicle_dataPath = true;
}

void Processor::SUB()
{
    QStringList inst = this->controlUnit->IR.split(" ");
    inst[1].removeFirst();
    inst[2].removeFirst();
    inst[3].removeFirst();

    this->controlUnit->AAddr = this->decToBin(inst[2].toInt(), 2);
    this->controlUnit->BAddr = this->decToBin(inst[3].toInt(), 2);
    this->controlUnit->UlaOp = this->decToBin(1, 2);
    this->controlUnit->SwitchPos = "1001";
    this->controlUnit->CAddr = this->decToBin(inst[1].toInt(), 2);
    this->controlUnit->RWAddr = this->decToBin(0, 5);

    this->cicle_dataPath = true;
}

void Processor::AND()
{
    QStringList inst = this->controlUnit->IR.split(" ");
    inst[1].removeFirst();
    inst[2].removeFirst();
    inst[3].removeFirst();

    this->controlUnit->AAddr = this->decToBin(inst[2].toInt(), 2);
    this->controlUnit->BAddr = this->decToBin(inst[3].toInt(), 2);
    this->controlUnit->UlaOp = this->decToBin(2, 2);
    this->controlUnit->SwitchPos = "1001";
    this->controlUnit->CAddr = this->decToBin(inst[1].toInt(), 2);
    this->controlUnit->RWAddr = this->decToBin(0, 5);

    this->cicle_dataPath = true;
}

void Processor::OR()
{
    QStringList inst = this->controlUnit->IR.split(" ");
    inst[1].removeFirst();
    inst[2].removeFirst();
    inst[3].removeFirst();

    this->controlUnit->AAddr = this->decToBin(inst[2].toInt(), 2);
    this->controlUnit->BAddr = this->decToBin(inst[3].toInt(), 2);
    this->controlUnit->UlaOp = this->decToBin(3, 2);
    this->controlUnit->SwitchPos = "1001";
    this->controlUnit->CAddr = this->decToBin(inst[1].toInt(), 2);
    this->controlUnit->RWAddr = this->decToBin(0, 5);

    this->cicle_dataPath = true;
}

void Processor::BRANCH()
{
    QStringList inst = this->controlUnit->IR.split(" ");

    this->controlUnit->PC = inst[1].toInt();
    this->cicle_dataPath = false;
}

void Processor::BZERO()
{
    if(this->dataPath->alu->C == 0)
    {
        QStringList inst = this->controlUnit->IR.split(" ");

        this->controlUnit->PC = inst[1].toInt();
    }
    this->cicle_dataPath = false;
}

void Processor::BNEG()
{
    if(this->dataPath->alu->C < 0)
    {
        QStringList inst = this->controlUnit->IR.split(" ");

        this->controlUnit->PC = inst[1].toInt();
    }
    this->cicle_dataPath = false;
}

void Processor::NOP()
{
    this->controlUnit->AAddr = this->decToBin(0, 2);
    this->controlUnit->BAddr = this->decToBin(0, 2);
    this->controlUnit->UlaOp = this->decToBin(0, 2);
    this->controlUnit->SwitchPos = "0000";
    this->controlUnit->CAddr = this->decToBin(0, 2);
    this->controlUnit->RWAddr = this->decToBin(0, 5);

    this->cicle_dataPath = false;
}

void Processor::HALT()
{
    this->halt = true;
}
