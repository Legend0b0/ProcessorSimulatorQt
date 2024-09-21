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

QString Processor::decToBin(int dec)
{
    QString bin;

    bin.setNum(dec, 2);

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
    while(1)
    {
        this->controlUnit->IR.clear();
        this->controlUnit->IR.append(this->mainMemory->at(this->controlUnit->PC));

        if(++this->controlUnit->PC == 32)
        {
            this->controlUnit->PC = 0;
        }

        emit this->throwPC();

        this->instructionInterpretation();

        emit this->throwControlUnit();

        break;
    }
}

void Processor::LOAD()
{
    QStringList inst = this->controlUnit->IR.split(' ');
    inst[1].removeFirst();

    this->controlUnit->AAddr = "00";
    this->controlUnit->BAddr = "00";
    this->controlUnit->UlaOp = "00";
    this->controlUnit->SwitchPos = "1010";
    this->controlUnit->CAddr = this->decToBin(inst[1].toInt());
    this->controlUnit->RWAddr = this->decToBin(inst[2].toInt());
}

void Processor::STORE()
{
    QStringList inst = this->controlUnit->IR.split(" ");
    inst[2].removeFirst();

    this->controlUnit->AAddr = this->decToBin(inst[2].toInt());
    this->controlUnit->BAddr = this->decToBin(inst[2].toInt());
    this->controlUnit->UlaOp = "01";
    this->controlUnit->SwitchPos = "0101";
    this->controlUnit->CAddr = "00";
    this->controlUnit->RWAddr = this->decToBin(inst[1].toInt());
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
