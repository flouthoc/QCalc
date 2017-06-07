#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>

double firstBuffer;
double secondBuffer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    /*Signals for digits*/
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(push_button_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(push_button_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(push_button_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(push_button_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(push_button_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(push_button_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(push_button_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(push_button_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(push_button_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(push_button_pressed()));

    /*Signals for operation*/
    connect(ui->operation_add, SIGNAL(released()), this, SLOT(push_operation_pressed()));
    connect(ui->operation_sub, SIGNAL(released()), this, SLOT(push_operation_pressed()));
    connect(ui->operation_mul, SIGNAL(released()), this, SLOT(push_operation_pressed()));
    connect(ui->operation_div, SIGNAL(released()), this, SLOT(push_operation_pressed()));

    /*Signals for clear and equals*/
    connect(ui->pushButton_clear, SIGNAL(released()), this, SLOT(push_clear_pressed()));
    connect(ui->equal, SIGNAL(released()), this, SLOT(push_equals_pressed()));

    ui->operation_add->setCheckable(true);
    ui->operation_sub->setCheckable(true);
    ui->operation_mul->setCheckable(true);
    ui->operation_div->setCheckable(true);

    /*Signal for Quit*/
    connect(ui->closeButton, SIGNAL(released()), this, SLOT(close_button_pressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *evt)
{
    oldPos = evt->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *evt)
{
    const QPoint delta = evt->globalPos() - oldPos;
    move(x()+delta.x(), y()+delta.y());
    oldPos = evt->globalPos();
}



void MainWindow::push_operation_pressed(){

    QPushButton *button = (QPushButton *)sender();
    button->setChecked(true);
    firstBuffer = (ui->label->text()).toDouble();
    ui->label->setText("0");

}

void MainWindow::push_clear_pressed(){

    firstBuffer = 0;
    secondBuffer = 0;
    ui->operation_add->setChecked(false);
    ui->operation_sub->setChecked(false);
    ui->operation_mul->setChecked(false);
    ui->operation_div->setChecked(false);

    ui->label->setText("0");

}

void MainWindow::push_equals_pressed(){

    double result;
    QString resultString;

    secondBuffer = (ui->label->text()).toDouble();
    if(ui->operation_add->isChecked()){

        result = firstBuffer + secondBuffer;

    }else if(ui->operation_sub->isChecked()){

        result = firstBuffer - secondBuffer;

    }else if(ui->operation_mul->isChecked()){

        result = firstBuffer * secondBuffer;

    }else if(ui->operation_div->isChecked()){

        result = firstBuffer / secondBuffer;

    }else{

        firstBuffer = 0;
        secondBuffer = 0;
        ui->operation_add->setChecked(false);
        ui->operation_sub->setChecked(false);
        ui->operation_mul->setChecked(false);
        ui->operation_div->setChecked(false);

        return;

    }

    secondBuffer = result;
    firstBuffer = 0;
    resultString = QString::number(result, 'g', 20);
    ui->label->setText(resultString);


}

void MainWindow::push_button_pressed(){

    QPushButton *button = (QPushButton *)sender();
    double number;
    QString finalString;
    number = (ui->label->text() + button->text()).toDouble();
    finalString = QString::number(number,'g',20);

    ui->label->setText(finalString);

}

void MainWindow::close_button_pressed(){
    QApplication::quit();
}
