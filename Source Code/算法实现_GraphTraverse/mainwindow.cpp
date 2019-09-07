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
    //�˵�
    File = menuBar()->addMenu(tr("File"));
    Exit = new QAction(tr("Exit"), this); //��ʼ������
    File->addAction(Exit);                //��������ӵ��˵���
    //�����źźͲ�
    connect(Exit, SIGNAL(triggered()), this, SLOT(exitActionSlot()));

    Tlabel = new QLabel(ui->centralWidget);
    QString title = QString::fromLocal8Bit("��ӭʹ��ͼ�ı�������");
    Tlabel->setText(title);
    Tlabel->setStyleSheet("font-weight:bold;"
                          "font-size:30px;");
    Tlabel->setGeometry(280, 10, 400, 50);

    Qlabel = new QLabel(ui->centralWidget);
    QString question = QString::fromLocal8Bit(
        "����������\n"
        "���ڽӾ���ķ�ʽȷ��һ��ͼ:\n"
        "1.��������ʾ�������ڽ�����.\n"
        "2.�Եݹ鼰�ǵݹ�ķ�ʽ����������ȱ�������ʾ�������,����ʱ��ʾջ���롢�����.\n"
        "3.�Ը�ͼ���й�����ȱ�������ʾ�����Ľ��������ʱ��ʾ���е��롢�����");
    Qlabel->setText(question);
    Qlabel->setStyleSheet("font-size:24px;font-weight:bold;"
                          "border:2px solid gray;");
    Qlabel->setGeometry(80, 80, 755, 250);
    Qlabel->setWordWrap(1);

    enter = new QPushButton(ui->centralWidget);
    enter->setText(QString::fromLocal8Bit("��ʾ"));
    enter->setStyleSheet("font-size:20px;font-weight:bold;color:darkblue;");
    enter->setGeometry(400, 350, 100, 50);
    enter->setCursor(QCursor(Qt::PointingHandCursor));
    //�ź�����
    connect(enter, SIGNAL(clicked()), this, SLOT(onEnterButtonClick()));
    connect(&ow, &OperateWindow::returnMainWindow, this, &MainWindow::operateWindowBackSlot);
    //ow��returnMainWindow�ź���MainWindow��Ӧ�۵Ĳۺ���operateWindowBackSlot����
    //��operateWindow�ķ��ذ�ť����returnMainWindow�źţ���ǰ����MainWindow����this�ͻ�ִ��ʵ���źŹ��ܵĲۺ�����
    //������operateWindow,��ʾ��ǰ����
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
