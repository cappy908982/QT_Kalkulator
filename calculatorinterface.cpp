#include "calculatorinterface.h"
#include "ui_calculatorinterface.h"

#include <QSignalMapper>
#include "calculator.h"

CalculatorInterface::CalculatorInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorInterface),
    m_calculator(new Calculator(this))
{
    ui->setupUi(this);

    QSignalMapper *m = new QSignalMapper(this);
    connect(ui->buttonZero, SIGNAL(clicked()), m, SLOT(map()));
    connect(ui->buttonOne, SIGNAL(clicked()), m, SLOT(map()));
    connect(ui->buttonTwo, SIGNAL(clicked()), m, SLOT(map()));
    connect(ui->buttonThree, SIGNAL(clicked()), m, SLOT(map()));
    connect(ui->buttonFour, SIGNAL(clicked()), m, SLOT(map()));
    connect(ui->buttonFive, SIGNAL(clicked()), m, SLOT(map()));
    connect(ui->buttonSix, SIGNAL(clicked()), m, SLOT(map()));
    connect(ui->buttonSeven, SIGNAL(clicked()), m, SLOT(map()));
    connect(ui->buttonEight, SIGNAL(clicked()), m, SLOT(map()));
    connect(ui->buttonNine, SIGNAL(clicked()), m, SLOT(map()));

    m->setMapping(ui->buttonZero, 0);
    m->setMapping(ui->buttonOne, 1);
    m->setMapping(ui->buttonTwo, 2);
    m->setMapping(ui->buttonThree, 3);
    m->setMapping(ui->buttonFour, 4);
    m->setMapping(ui->buttonFive, 5);
    m->setMapping(ui->buttonSix, 6);
    m->setMapping(ui->buttonSeven, 7);
    m->setMapping(ui->buttonEight, 8);
    m->setMapping(ui->buttonNine, 9);

    connect(m, SIGNAL(mapped(int)), m_calculator, SLOT(numEntered(int)));
    connect(m_calculator, SIGNAL(displayChanged(QString)), ui->entryLabel, SLOT(setText(QString)));
    connect(ui->buttonAllClear, SIGNAL(clicked()), m_calculator, SLOT(allClear()));
    connect(ui->buttonAdd, SIGNAL(clicked()), m_calculator, SLOT(additionMode()));
    connect(ui->buttonSubtract, SIGNAL(clicked()), m_calculator, SLOT(subtractionMode()));
    connect(ui->buttonCalculate, SIGNAL(clicked()), m_calculator, SLOT(calculate()));
    connect(ui->buttonClear, SIGNAL(clicked()), m_calculator, SLOT(clear()));

     m_calculator->allClear();
}

CalculatorInterface::~CalculatorInterface()
{
    delete ui;
}

void CalculatorInterface::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
