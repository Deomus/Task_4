#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette pal = ui -> centralWidget -> palette();
    pal.setColor(QPalette::Window, Qt::red  );
    ui -> centralWidget -> setAutoFillBackground(true);
    ui -> centralWidget -> setPalette(pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// основная функция вычисления
void MainWindow::calculate()
{
    // объявляем и задаем значение переменным
    bool op1 =  ui -> comboBox_op1 -> currentIndex() == 1;
    bool op2 = ui -> comboBox_op2 -> currentIndex() == 1;
    bool res = true;
    int index = ui-> comboBox_operation -> currentIndex();

    // создаем палитру
    QPalette pal = ui -> centralWidget -> palette();
    // делаем видимым второй операнд
    ui -> comboBox_op2 -> setVisible(true);

    // вычисляем значение
    switch (index) {
    case 0:
        ui->comboBox_op2->show();
        res = op1 && op2;
        break;
    case 1:
        ui->comboBox_op2->show();
        res = op1 || op2;
        break;
    case 2:
        ui->comboBox_op2->hide();
        res = !op1;
        break;
    case 3:
        ui->comboBox_op2->show();
        res = !op1 || op2;
        break;
    case 4:
        ui->comboBox_op2->show();
        res = op1 == op2;
        break;
    case 5:
        ui->comboBox_op2->show();
        res = op1 != op2;
        break;
    }

    // задаем цвет фону
    if(res)
        pal.setColor(QPalette::Window, Qt::green);
    else
        pal.setColor(QPalette::Window, Qt::red);

    ui -> centralWidget -> setAutoFillBackground(true);
    ui -> centralWidget -> setPalette(pal);
}

// функция изменения пепрвого операнда
void MainWindow::on_comboBox_op1_currentIndexChanged(int)
{
    calculate();
}

// функция изменения второго операнда
void MainWindow::on_comboBox_op2_currentIndexChanged(int)
{
    calculate();
}

// функция изменения операции
void MainWindow::on_comboBox_operation_currentIndexChanged(int)
{
    calculate();
}
