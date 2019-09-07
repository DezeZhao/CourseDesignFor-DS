#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900, 600);
    setWindowTitle(QString::fromLocal8Bit("主页面"));
    //菜单
    File = menuBar()->addMenu(tr("File"));
    Exit = new QAction(tr("Exit"), this); //初始化动作
    File->addAction(Exit);                //将动作添加到菜单上
    //连接信号和槽函数
    connect(Exit, SIGNAL(triggered()), this, SLOT(exitActionSlot()));

    Tlabel = new QLabel(ui->centralWidget);
    QString title = QString::fromLocal8Bit("欢迎使用社会关系网络系统！");
    Tlabel->setText(title);
    Tlabel->setStyleSheet("font-weight:bold;"
                          "font-size:30px;");
    Tlabel->setGeometry(280, 10, 400, 50);

    Qlabel = new QLabel(ui->centralWidget);
    QString question = QString::fromLocal8Bit(
        "问题描述：\n"
        "在某社会关系网络系统中，一个人属性包括所在地区、就读的各级学校、工作单位等，每一个"
        "人有众多好友，并可以根据个人兴趣及社会活动加入到某些群组。现需设计一算法，从该社会"
        "关系网络中某一人出发，寻找其可能认识的人。例如根据两个人共同的好友数量及所在群组的情况"
        "来发现可能认识的人；通过就读的学校情况发现可能认识的同学:\n"
        "1.通过图形化界面显示某一人的社会关系网络.\n"
        "2.寻找某一人可能认识的人(不是其好友)，并查看这些人与其关联度(共同好友数).\n"
        "3.根据可能认识的人与其关联度对这些人进行排序.");
    Qlabel->setText(question);
    Qlabel->setStyleSheet("font-size:22px;font-weight:bold;"
                          "border:2px solid gray;");
    Qlabel->setGeometry(80, 80, 755, 380);
    Qlabel->setWordWrap(1);

    enter = new QPushButton(ui->centralWidget);
    enter->setText(QString::fromLocal8Bit("演示"));
    enter->setStyleSheet("font-size:20px;font-weight:bold;color:darkblue;");
    enter->setGeometry(400, 480, 100, 50);
    enter->setCursor(QCursor(Qt::PointingHandCursor));
    //信号连接
    connect(enter, SIGNAL(clicked()), this, SLOT(onEnterButtonClick()));
    connect(&ow, &OperateWindow::returnMainWindow, this, &MainWindow::operateWindowBackSlot);
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
