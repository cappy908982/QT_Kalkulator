#include "calculator.h"

Calculator::Calculator(QObject *parent) :
    QObject(parent), m_lastResult(0), m_currentNumber(0), m_isAdding(true), m_isMultiplicating(true)
{
}

void Calculator::numEntered(int num)
{
    m_currentNumber = m_currentNumber*10 + num;
    emit displayChanged(QString::number(m_currentNumber));
}
void Calculator::negate()
{
    m_currentNumber = -m_currentNumber;     //liczby ujemne 
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::clear()
{
    m_currentNumber = 0;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::allClear()
{
    m_currentNumber = 0;
    m_lastResult = 0;
    emit displayChanged(QString::number(m_currentNumber));
}

void Calculator::additionMode()
{
    calculate();
    m_isAdding = true;
    m_isMultiplicating=true;
}
void Calculator::multiplicationMode()
{
    calculate();
    m_isMultiplicating=true;
    m_isAdding=false;
}
void Calculator::divisionMode()
{
    calculate();
    m_isMultiplicating=false;
    m_isAdding=true;
}

void Calculator::subtractionMode()
{
    calculate(); 
    m_isAdding = false;
    m_isMultiplicating=false;
}

void Calculator::calculate()
{
    if((m_isAdding)&&(m_isMultiplicating))//dodawanie
    {
        m_lastResult+=m_currentNumber;
    }
    else if((!m_isAdding)&&(!m_isMultiplicating))//odejmowanie
    {
        m_lastResult-=m_currentNumber;
    }
    else if((!m_isAdding)&&(m_isMultiplicating))//mnożenie
    {
        m_lastResult*=m_currentNumber;
    }
    else                                     //dzielenie
    {
        m_lastResult/=m_currentNumber;
    }
    m_currentNumber = 0;
    emit displayChanged(QString::number(m_lastResult));
}
