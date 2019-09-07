#include "operatewindow.h"
#include "ui_operatewindow.h"
#include <QDebug>
#include <QPainter>
#include <QtMath>

OperateWindow::OperateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OperateWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900, 650);
    setWindowTitle(QString::fromLocal8Bit("����ҳ��"));

    graphBox = new QGroupBox(ui->centralwidget);
    graphBox->setTitle(QString::fromLocal8Bit("����ϵ����ͼ"));
    graphBox->setGeometry(20, 10, 550, 380);

    nodesLabel = new QLabel(ui->centralwidget);
    nodesLabel->setGeometry(20, 400, 128, 20);
    nodesLabel->setText(QString::fromLocal8Bit("�ڵ���Ϣ:"));
    nodesNameBrowser = new QTextBrowser(ui->centralwidget);
    nodesNameBrowser->setGeometry(20, 430, 128, 190);
    nodesNameBrowser->setLineWrapMode(QTextEdit::NoWrap);

    adjlistLabel = new QLabel(ui->centralwidget);
    adjlistLabel->setGeometry(160, 400, 200, 20);
    adjlistLabel->setText(QString::fromLocal8Bit("����ϵ�����ڽ�����:"));
    adjlistBrowser = new QTextBrowser(ui->centralwidget);
    adjlistBrowser->setGeometry(160, 430, 200, 190);
    adjlistBrowser->setLineWrapMode(QTextEdit::NoWrap);

    adjmatrixLabel = new QLabel(ui->centralwidget);
    adjmatrixLabel->setText(QString::fromLocal8Bit("����ϵ�����ڽӾ���:"));
    adjmatrixLabel->setGeometry(370, 400, 200, 20);
    adjmatrixBrowser = new QTextBrowser(ui->centralwidget);
    adjmatrixBrowser->setGeometry(370, 430, 200, 190);
    adjmatrixBrowser->setLineWrapMode(QTextEdit::NoWrap);

    groupBox = new QGroupBox(ui->centralwidget);
    groupBox->setGeometry(585, 10, 300, 430);

    groupBox1 = new QGroupBox(groupBox);
    groupBox1->setTitle(QString::fromLocal8Bit("��ѡ���ϵ�����е�ĳ�ڵ�:"));
    groupBox1->setGeometry(10, 20, 280, 80);

    selectNode = new QComboBox(groupBox1);
    selectNode->setGeometry(10, 30, 260, 40);
    selectNode->addItem(QString::fromLocal8Bit("��ѡ���ϵ�����еĽڵ�"));
    for (int i = 0; i < mg.getVexnum(); i++) {
        selectNode->addItem(mg.getSelectedItem(i));
    }

    nodeNetwork = new QPushButton(groupBox);
    nodeNetwork->setGeometry(20, 110, 260, 40);
    nodeNetwork->setText(QString::fromLocal8Bit("�鿴�ýڵ�Ĺ�ϵ����"));
    nodeNetwork->setStyleSheet("color:darkblue;font-size:18px;font-weight:bold;");
    nodeNetwork->setCursor(QCursor(Qt::PointingHandCursor));

    addNode = new QPushButton(groupBox);
    addNode->setGeometry(20, 160, 260, 40);
    addNode->setText(QString::fromLocal8Bit("��ӽڵ�"));
    addNode->setStyleSheet("color:darkblue;font-size:18px;font-weight:bold;");
    addNode->setCursor(QCursor(Qt::PointingHandCursor));

    groupBox2 = new QGroupBox(groupBox);
    groupBox2->setTitle(QString::fromLocal8Bit("������ϵ������в���"));
    groupBox2->setGeometry(10, 230, 280, 190);

    generateMatrix = new QPushButton(groupBox2);
    generateMatrix->setText(QString::fromLocal8Bit("�����ڽӾ���"));
    generateMatrix->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    generateMatrix->setCursor(QCursor(Qt::PointingHandCursor));
    generateMatrix->setGeometry(10, 130, 260, 40);

    generateAdjlist = new QPushButton(groupBox2);
    generateAdjlist->setText(QString::fromLocal8Bit("�����ڽ�����"));
    generateAdjlist->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    generateAdjlist->setCursor(QCursor(Qt::PointingHandCursor));
    generateAdjlist->setGeometry(10, 80, 260, 40);

    generateNodes = new QPushButton(groupBox2);
    generateNodes->setText(QString::fromLocal8Bit("���ɽڵ���Ϣ"));
    generateNodes->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    generateNodes->setCursor(QCursor(Qt::PointingHandCursor));
    generateNodes->setGeometry(10, 30, 260, 40);

    backBtn = new QPushButton(ui->centralwidget);
    backBtn->setText(QString::fromLocal8Bit("������ҳ"));
    backBtn->setGeometry(605, 580, 120, 40);
    backBtn->setCursor(QCursor(Qt::PointingHandCursor));
    exitBtn = new QPushButton(ui->centralwidget);
    exitBtn->setText(QString::fromLocal8Bit("�˳�����"));
    exitBtn->setGeometry(745, 580, 120, 40);
    exitBtn->setCursor(QCursor(Qt::PointingHandCursor));

    connect(selectNode,
            SIGNAL(currentIndexChanged(int)),
            this,
            SLOT(onCurrentIndexChangedSelectNodeComboBox())); //ѡ��Ҫ�鿴�Ľڵ�Ĺ�ϵ����
    connect(nodeNetwork, SIGNAL(clicked()), this, SLOT(onClickNodeNetworkButton()));
    connect(addNode, SIGNAL(clicked()), this, SLOT(onClickAddNodeButton()));
    connect(generateNodes,
            SIGNAL(clicked()),
            this,
            SLOT(onClickGenerateNodesButton())); //���ɽڵ���Ϣ
    connect(generateAdjlist,
            SIGNAL(clicked()),
            this,
            SLOT(onClickGenerateAdjlistButton())); //�����ڽ�����
    connect(generateMatrix,
            SIGNAL(clicked()),
            this,
            SLOT(onClickGenerateMatrixButton())); //�����ڽӾ���
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(onClickExitButton()));
    connect(backBtn, SIGNAL(clicked()), this, SLOT(onClickBackButton()));
    connect(&nw,
            &NetworkWindow::returnOperateWindow,
            this,
            &OperateWindow::operateWindowBackSlot1); //���巵���¼�
}
void OperateWindow::operateWindowBackSlot1()
{
    nw.hide();
    this->show();
}
void OperateWindow::paintEvent(QPaintEvent *)
{
    int radius = 50;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen; //����
    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(3);
    painter.setPen(pen); //��ӻ���

    QFont font; //��������
    font.setPixelSize(25);
    font.setWeight(QFont::Black);
    painter.setFont(font);

    int vexnum = mg.getVexnum();
    double angle = 0;
    double delta = 2 * 3.1415926 / vexnum;

    QTransform transform;
    transform.translate(270, 180); //���ĵ��ƶ���graphbox����
    transform.rotate(0);
    painter.setWorldTransform(transform);

    double cx = 0, cy = 0;
    double px = 150, py = 0;

    QPoint point[10];

    for (int i = 0; i < vexnum; i++) {
        cx = px * cos(angle) - py * sin(angle);
        cy = px * sin(angle) + py * cos(angle);

        QRect rect(int(cx), int(cy), radius, radius); //����һ������
        point[i] = rect.center();

        painter.drawEllipse(rect);
        painter.drawText(point[i].x() - 7, point[i].y() + 8, QString::number(i));
        angle += delta;
    }
    QPen pen2;
    pen2.setColor(Qt::darkRed);
    pen2.setWidth(3);
    painter.setPen(pen2);
    for (int i = 0; i < vexnum; i++)
        for (int j = 1 + i; j < vexnum; j++)
            if (mg.correlate(i, j))
                painter.drawLine(point[i], point[j]);
}
void OperateWindow::onCurrentIndexChangedSelectNodeComboBox()
{
    if (selectNode->currentIndex() != 0) {
        nw.setMGraph(&mg);
        nw.setId(selectNode->currentIndex() - 1);
    }
}
void OperateWindow::onClickGenerateNodesButton()
{
    nodesNameBrowser->setText(mg.displayNodesName());
}
void OperateWindow::onClickGenerateMatrixButton()
{
    adjmatrixBrowser->setText(mg.displayAdjMatrix());
}
void OperateWindow::onClickGenerateAdjlistButton()
{
    adjlistBrowser->setText(mg.displayAdjList());
}
void OperateWindow::onClickBackButton()
{
    emit returnMainWindow();
}
void OperateWindow::onClickExitButton()
{
    QApplication *app = nullptr;
    app->quit();
}
void OperateWindow::onClickNodeNetworkButton()
{
    if (selectNode->currentIndex() != 0) {
        this->hide();
        nw.show();
    } else {
        QMessageBox::warning(this, "Warning", QString::fromLocal8Bit("��ѡ��Ҫ�鿴��Ϣ�Ľڵ㣡"));
    }
}
void OperateWindow::onClickAddNodeButton()
{
    if (mg.getVexnum() >= MAX_VERTEX_NUM) {
        QString str;
        str += QString::fromLocal8Bit("�����Ŀ�Ѵ����ޣ���಻�ܳ���")
               + QString::number(mg.getVexnum()) + QString::fromLocal8Bit("����");
        QMessageBox::warning(this, "Warning", str);
        return;
    }
    AddNodeDialog addNodeDialog;
    addNodeDialog.addFriendItem(&mg);
    addNodeDialog.exec();
    addNodeDialog.setMessage();
    addNodeDialog.setHobby();
    addNodeDialog.setFriend(); //ͨ��dialog�Ի�������message���õ�hobby��friend
    // Dialog *da = new Dialog(this);
    //    da->show();
    //    ÿ�ιرնԻ��򲻻�ִ�������������������ڹرղŻ�ȫ���ͷ�
    //    exec() �ر�ģʽ�Ի���֮��ִ����ȥ
    //        ÿ�ιر�Dialog�Ի����ִ�������������ͷ��ڴ�
    if (!addNodeDialog.isValid() || addNodeDialog.cancelFlag) {
        return;
    }
    QString **msg;
    msg = addNodeDialog.getMessage();
    bool *hobbies = addNodeDialog.getHobby();  //�õ�����İ�����Ϣ
    bool *friends = addNodeDialog.getFriend(); //�õ���������ѹ�ϵ��Ϣ
    VertexType *v = new Person;
    v->setId(mg.getVexnum());
    v->setName(*(msg[0]));
    v->setRegion(*(msg[1]));
    v->setPrimarySchool(*(msg[2]));
    v->setMiddleSchool(*(msg[3]));
    v->setHighSchool(*(msg[4]));
    v->setWorkPlace(*(msg[5]));
    v->setHobbies(hobbies);

    bool friendList[10];
    for (int i = 0; i < 10; i++) {
        friendList[i] = friends[i];
    }
    mg.addPersonNode(v, friendList);
    selectNode->addItem(mg.getSelectedItem(mg.getVexnum() - 1));
    repaint();
}
OperateWindow::~OperateWindow()
{
    delete ui;
}
