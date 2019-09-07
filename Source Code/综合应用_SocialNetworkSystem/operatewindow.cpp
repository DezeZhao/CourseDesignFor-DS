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
    setWindowTitle(QString::fromLocal8Bit("操作页面"));

    graphBox = new QGroupBox(ui->centralwidget);
    graphBox->setTitle(QString::fromLocal8Bit("社会关系网络图"));
    graphBox->setGeometry(20, 10, 550, 380);

    nodesLabel = new QLabel(ui->centralwidget);
    nodesLabel->setGeometry(20, 400, 128, 20);
    nodesLabel->setText(QString::fromLocal8Bit("节点信息:"));
    nodesNameBrowser = new QTextBrowser(ui->centralwidget);
    nodesNameBrowser->setGeometry(20, 430, 128, 190);
    nodesNameBrowser->setLineWrapMode(QTextEdit::NoWrap);

    adjlistLabel = new QLabel(ui->centralwidget);
    adjlistLabel->setGeometry(160, 400, 200, 20);
    adjlistLabel->setText(QString::fromLocal8Bit("社会关系网络邻接链表:"));
    adjlistBrowser = new QTextBrowser(ui->centralwidget);
    adjlistBrowser->setGeometry(160, 430, 200, 190);
    adjlistBrowser->setLineWrapMode(QTextEdit::NoWrap);

    adjmatrixLabel = new QLabel(ui->centralwidget);
    adjmatrixLabel->setText(QString::fromLocal8Bit("社会关系网络邻接矩阵:"));
    adjmatrixLabel->setGeometry(370, 400, 200, 20);
    adjmatrixBrowser = new QTextBrowser(ui->centralwidget);
    adjmatrixBrowser->setGeometry(370, 430, 200, 190);
    adjmatrixBrowser->setLineWrapMode(QTextEdit::NoWrap);

    groupBox = new QGroupBox(ui->centralwidget);
    groupBox->setGeometry(585, 10, 300, 430);

    groupBox1 = new QGroupBox(groupBox);
    groupBox1->setTitle(QString::fromLocal8Bit("请选择关系网络中的某节点:"));
    groupBox1->setGeometry(10, 20, 280, 80);

    selectNode = new QComboBox(groupBox1);
    selectNode->setGeometry(10, 30, 260, 40);
    selectNode->addItem(QString::fromLocal8Bit("请选择关系网络中的节点"));
    for (int i = 0; i < mg.getVexnum(); i++) {
        selectNode->addItem(mg.getSelectedItem(i));
    }

    nodeNetwork = new QPushButton(groupBox);
    nodeNetwork->setGeometry(20, 110, 260, 40);
    nodeNetwork->setText(QString::fromLocal8Bit("查看该节点的关系网络"));
    nodeNetwork->setStyleSheet("color:darkblue;font-size:18px;font-weight:bold;");
    nodeNetwork->setCursor(QCursor(Qt::PointingHandCursor));

    addNode = new QPushButton(groupBox);
    addNode->setGeometry(20, 160, 260, 40);
    addNode->setText(QString::fromLocal8Bit("添加节点"));
    addNode->setStyleSheet("color:darkblue;font-size:18px;font-weight:bold;");
    addNode->setCursor(QCursor(Qt::PointingHandCursor));

    groupBox2 = new QGroupBox(groupBox);
    groupBox2->setTitle(QString::fromLocal8Bit("对社会关系网络进行操作"));
    groupBox2->setGeometry(10, 230, 280, 190);

    generateMatrix = new QPushButton(groupBox2);
    generateMatrix->setText(QString::fromLocal8Bit("生成邻接矩阵"));
    generateMatrix->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    generateMatrix->setCursor(QCursor(Qt::PointingHandCursor));
    generateMatrix->setGeometry(10, 130, 260, 40);

    generateAdjlist = new QPushButton(groupBox2);
    generateAdjlist->setText(QString::fromLocal8Bit("生成邻接链表"));
    generateAdjlist->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    generateAdjlist->setCursor(QCursor(Qt::PointingHandCursor));
    generateAdjlist->setGeometry(10, 80, 260, 40);

    generateNodes = new QPushButton(groupBox2);
    generateNodes->setText(QString::fromLocal8Bit("生成节点信息"));
    generateNodes->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    generateNodes->setCursor(QCursor(Qt::PointingHandCursor));
    generateNodes->setGeometry(10, 30, 260, 40);

    backBtn = new QPushButton(ui->centralwidget);
    backBtn->setText(QString::fromLocal8Bit("返回主页"));
    backBtn->setGeometry(605, 580, 120, 40);
    backBtn->setCursor(QCursor(Qt::PointingHandCursor));
    exitBtn = new QPushButton(ui->centralwidget);
    exitBtn->setText(QString::fromLocal8Bit("退出程序"));
    exitBtn->setGeometry(745, 580, 120, 40);
    exitBtn->setCursor(QCursor(Qt::PointingHandCursor));

    connect(selectNode,
            SIGNAL(currentIndexChanged(int)),
            this,
            SLOT(onCurrentIndexChangedSelectNodeComboBox())); //选择要查看的节点的关系网络
    connect(nodeNetwork, SIGNAL(clicked()), this, SLOT(onClickNodeNetworkButton()));
    connect(addNode, SIGNAL(clicked()), this, SLOT(onClickAddNodeButton()));
    connect(generateNodes,
            SIGNAL(clicked()),
            this,
            SLOT(onClickGenerateNodesButton())); //生成节点信息
    connect(generateAdjlist,
            SIGNAL(clicked()),
            this,
            SLOT(onClickGenerateAdjlistButton())); //生成邻接链表
    connect(generateMatrix,
            SIGNAL(clicked()),
            this,
            SLOT(onClickGenerateMatrixButton())); //生成邻接矩阵
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(onClickExitButton()));
    connect(backBtn, SIGNAL(clicked()), this, SLOT(onClickBackButton()));
    connect(&nw,
            &NetworkWindow::returnOperateWindow,
            this,
            &OperateWindow::operateWindowBackSlot1); //窗体返回事件
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
    QPen pen; //画笔
    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(3);
    painter.setPen(pen); //添加画笔

    QFont font; //设置字体
    font.setPixelSize(25);
    font.setWeight(QFont::Black);
    painter.setFont(font);

    int vexnum = mg.getVexnum();
    double angle = 0;
    double delta = 2 * 3.1415926 / vexnum;

    QTransform transform;
    transform.translate(270, 180); //中心点移动到graphbox中心
    transform.rotate(0);
    painter.setWorldTransform(transform);

    double cx = 0, cy = 0;
    double px = 150, py = 0;

    QPoint point[10];

    for (int i = 0; i < vexnum; i++) {
        cx = px * cos(angle) - py * sin(angle);
        cy = px * sin(angle) + py * cos(angle);

        QRect rect(int(cx), int(cy), radius, radius); //构造一个矩形
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
        QMessageBox::warning(this, "Warning", QString::fromLocal8Bit("请选择要查看信息的节点！"));
    }
}
void OperateWindow::onClickAddNodeButton()
{
    if (mg.getVexnum() >= MAX_VERTEX_NUM) {
        QString str;
        str += QString::fromLocal8Bit("结点数目已达上限！最多不能超过")
               + QString::number(mg.getVexnum()) + QString::fromLocal8Bit("个！");
        QMessageBox::warning(this, "Warning", str);
        return;
    }
    AddNodeDialog addNodeDialog;
    addNodeDialog.addFriendItem(&mg);
    addNodeDialog.exec();
    addNodeDialog.setMessage();
    addNodeDialog.setHobby();
    addNodeDialog.setFriend(); //通过dialog对话框设置message，得到hobby和friend
    // Dialog *da = new Dialog(this);
    //    da->show();
    //    每次关闭对话框不会执行析构函数，当主窗口关闭才会全部释放
    //    exec() 关闭模式对话框之后执行下去
    //        每次关闭Dialog对话框会执行析构函数，释放内存
    if (!addNodeDialog.isValid() || addNodeDialog.cancelFlag) {
        return;
    }
    QString **msg;
    msg = addNodeDialog.getMessage();
    bool *hobbies = addNodeDialog.getHobby();  //得到输入的爱好信息
    bool *friends = addNodeDialog.getFriend(); //得到输入的朋友关系信息
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
