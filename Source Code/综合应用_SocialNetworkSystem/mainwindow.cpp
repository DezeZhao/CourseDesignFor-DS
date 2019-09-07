#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900, 600);
    setWindowTitle(QString::fromLocal8Bit("��ҳ��"));
    //�˵�
    File = menuBar()->addMenu(tr("File"));
    Exit = new QAction(tr("Exit"), this); //��ʼ������
    File->addAction(Exit);                //��������ӵ��˵���
    //�����źźͲۺ���
    connect(Exit, SIGNAL(triggered()), this, SLOT(exitActionSlot()));

    Tlabel = new QLabel(ui->centralWidget);
    QString title = QString::fromLocal8Bit("��ӭʹ������ϵ����ϵͳ��");
    Tlabel->setText(title);
    Tlabel->setStyleSheet("font-weight:bold;"
                          "font-size:30px;");
    Tlabel->setGeometry(280, 10, 400, 50);

    Qlabel = new QLabel(ui->centralWidget);
    QString question = QString::fromLocal8Bit(
        "����������\n"
        "��ĳ����ϵ����ϵͳ�У�һ�������԰������ڵ������Ͷ��ĸ���ѧУ��������λ�ȣ�ÿһ��"
        "�����ڶ���ѣ������Ը��ݸ�����Ȥ��������뵽ĳЩȺ�顣�������һ�㷨���Ӹ����"
        "��ϵ������ĳһ�˳�����Ѱ���������ʶ���ˡ�������������˹�ͬ�ĺ�������������Ⱥ������"
        "�����ֿ�����ʶ���ˣ�ͨ���Ͷ���ѧУ������ֿ�����ʶ��ͬѧ:\n"
        "1.ͨ��ͼ�λ�������ʾĳһ�˵�����ϵ����.\n"
        "2.Ѱ��ĳһ�˿�����ʶ����(���������)�����鿴��Щ�����������(��ͬ������).\n"
        "3.���ݿ�����ʶ������������ȶ���Щ�˽�������.");
    Qlabel->setText(question);
    Qlabel->setStyleSheet("font-size:22px;font-weight:bold;"
                          "border:2px solid gray;");
    Qlabel->setGeometry(80, 80, 755, 380);
    Qlabel->setWordWrap(1);

    enter = new QPushButton(ui->centralWidget);
    enter->setText(QString::fromLocal8Bit("��ʾ"));
    enter->setStyleSheet("font-size:20px;font-weight:bold;color:darkblue;");
    enter->setGeometry(400, 480, 100, 50);
    enter->setCursor(QCursor(Qt::PointingHandCursor));
    //�ź�����
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
