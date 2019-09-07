#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900, 500);
    //菜单
    File = menuBar()->addMenu(tr("File"));
    Exit = new QAction(tr("Exit"), this); //初始化动作
    File->addAction(Exit);                //将动作添加到菜单上
    //连接信号和槽
    connect(Exit, SIGNAL(triggered()), this, SLOT(exitActionSlot()));

    Tlabel = new QLabel(ui->centralWidget);
    QString title = QString::fromLocal8Bit("欢迎使用图的遍历程序！");
    Tlabel->setText(title);
    Tlabel->setStyleSheet("font-weight:bold;"
                          "font-size:30px;");
    Tlabel->setGeometry(280, 10, 400, 50);

    Qlabel = new QLabel(ui->centralWidget);
    QString question = QString::fromLocal8Bit(
        "问题描述：\n"
        "以邻接矩阵的方式确定一个图:\n"
        "1.建立并显示出它的邻接链表.\n"
        "2.以递归及非递归的方式进行深度优先遍历，显示遍历结果,并随时显示栈的入、出情况.\n"
        "3.对该图进行广度优先遍历，显示遍历的结果，并随时显示队列的入、出情况");
    Qlabel->setText(question);
    Qlabel->setStyleSheet("font-size:24px;font-weight:bold;"
                          "border:2px solid gray;");
    Qlabel->setGeometry(80, 80, 755, 250);
    Qlabel->setWordWrap(1);

    enter = new QPushButton(ui->centralWidget);
    enter->setText(QString::fromLocal8Bit("演示"));
    enter->setStyleSheet("font-size:20px;font-weight:bold;color:darkblue;");
    enter->setGeometry(400, 350, 100, 50);
    enter->setCursor(QCursor(Qt::PointingHandCursor));
    //信号连接
    connect(enter, SIGNAL(clicked()), this, SLOT(onEnterButtonClick()));
    connect(&ow, &OperateWindow::returnMainWindow, this, &MainWindow::operateWindowBackSlot);
    //ow的returnMainWindow信号与MainWindow反应槽的槽函数operateWindowBackSlot链接
    //当operateWindow的返回按钮触发returnMainWindow信号，当前窗口MainWindow对象this就会执行实现信号功能的槽函数，
    //即隐藏operateWindow,显示当前窗口
}
void MainWindow::operateWindowBackSlot()
{
    ow.hide();
    this->show();
}
void MainWindow::exitActionSlot()
{
    app->quit();
}

void MainWindow::onEnterButtonClick()
{
    this->hide();
    ow.show();
}
MainWindow::~MainWindow()
{
    delete ui;
}
