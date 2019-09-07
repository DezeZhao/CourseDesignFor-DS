#include "operatewindow.h"
#include "ui_operatewindow.h"
#include <QPainter>
#include <QtMath>

OperateWindow::OperateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OperateWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900, 650);

    groupBox = new QGroupBox(ui->centralwidget);
    groupBox->setGeometry(585, 10, 300, 360);

    groupBox1 = new QGroupBox(groupBox);
    groupBox1->setTitle(QString::fromLocal8Bit("请选择建立图的邻接矩阵的大小"));
    groupBox1->setGeometry(10, 20, 280, 80);

    MatrixSize = new QComboBox(groupBox1);
    QStringList size;
    size << QString::fromLocal8Bit("邻接矩阵大小") << "2*2"
         << "3*3"
         << "4*4"
         << "5*5"
         << "6*6"
         << "7*7"
         << "8*8"
         << "9*9"
         << "10*10";
    MatrixSize->addItems(size);
    MatrixSize->setGeometry(10, 30, 260, 40);

    groupBox2 = new QGroupBox(groupBox);
    groupBox2->setTitle(QString::fromLocal8Bit("请选择建立图的种类"));
    groupBox2->setGeometry(10, 120, 280, 80);
    GraphKind = new QComboBox(groupBox2);
    QStringList kind;
    kind << QString::fromLocal8Bit("图的种类") << QString::fromLocal8Bit("有向图")
         << QString::fromLocal8Bit("无向图");
    GraphKind->addItems(kind);
    GraphKind->setGeometry(10, 30, 260, 40);

    generateMatrix = new QPushButton(groupBox);
    generateMatrix->setText(QString::fromLocal8Bit("生成邻接矩阵"));
    generateMatrix->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    generateMatrix->setCursor(QCursor(Qt::PointingHandCursor));
    generateMatrix->setGeometry(20, 210, 260, 40);

    generateAdjlist = new QPushButton(groupBox);
    generateAdjlist->setText(QString::fromLocal8Bit("由邻接矩阵生成邻接链表"));
    generateAdjlist->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    generateAdjlist->setCursor(QCursor(Qt::PointingHandCursor));
    generateAdjlist->setGeometry(20, 260, 260, 40);

    generateGraph = new QPushButton(groupBox);
    generateGraph->setText(QString::fromLocal8Bit("由邻接矩阵生成图"));
    generateGraph->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    generateGraph->setCursor(QCursor(Qt::PointingHandCursor));
    generateGraph->setGeometry(20, 310, 260, 40);

    groupBox3 = new QGroupBox(ui->centralwidget);
    groupBox3->setTitle(QString::fromLocal8Bit("广度优先遍历(BFS)"));
    groupBox3->setGeometry(585, 380, 300, 80);

    bfsTraverse = new QPushButton(groupBox3);
    bfsTraverse->setText(QString::fromLocal8Bit("非递归"));
    bfsTraverse->setCursor(QCursor(Qt::PointingHandCursor));
    bfsTraverse->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    bfsTraverse->setGeometry(20, 30, 260, 40);

    groupBox4 = new QGroupBox(ui->centralwidget);
    groupBox4->setTitle(QString::fromLocal8Bit("深度优先遍历(DFS)"));
    groupBox4->setGeometry(585, 480, 300, 80);

    dfsRecurTraverse = new QPushButton(groupBox4);
    dfsRecurTraverse->setText(QString::fromLocal8Bit("递归"));
    dfsRecurTraverse->setCursor(QCursor(Qt::PointingHandCursor));
    dfsRecurTraverse->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    dfsRecurTraverse->setGeometry(20, 30, 120, 40);

    dfsNonrecurTraverse = new QPushButton(groupBox4);
    dfsNonrecurTraverse->setText(QString::fromLocal8Bit("非递归"));
    dfsNonrecurTraverse->setCursor(QCursor(Qt::PointingHandCursor));
    dfsNonrecurTraverse->setStyleSheet("color:darkred;font-size:20px;font-weight:bold;");
    dfsNonrecurTraverse->setGeometry(160, 30, 120, 40);

    graphBox = new QGroupBox(ui->centralwidget);
    graphBox->setTitle(QString::fromLocal8Bit("生成的图"));
    graphBox->setGeometry(20, 10, 550, 380);

    bfsLabel = new QLabel(ui->centralwidget);
    bfsLabel->setGeometry(20, 400, 128, 20);
    bfsLabel->setText(QString::fromLocal8Bit("BFS结果:"));
    bfsBrowser = new QTextBrowser(ui->centralwidget);
    bfsBrowser->setGeometry(20, 430, 128, 190);
    bfsBrowser->setLineWrapMode(QTextEdit::NoWrap);

    dfsLabel = new QLabel(ui->centralwidget);
    dfsLabel->setText((QString::fromLocal8Bit("DFS结果:")));
    dfsLabel->setGeometry(158, 400, 128, 20);
    dfsBrowser = new QTextBrowser(ui->centralwidget);
    dfsBrowser->setGeometry(158, 430, 128, 190);
    dfsBrowser->setLineWrapMode(QTextEdit::NoWrap);

    adjlistLabel = new QLabel(ui->centralwidget);
    adjlistLabel->setGeometry(296, 400, 128, 20);
    adjlistLabel->setText(QString::fromLocal8Bit("邻接链表:"));
    adjlistBrowser = new QTextBrowser(ui->centralwidget);
    adjlistBrowser->setGeometry(296, 430, 128, 190);
    adjlistBrowser->setLineWrapMode(QTextEdit::NoWrap);

    adjmatrixLabel = new QLabel(ui->centralwidget);
    adjmatrixLabel->setText(QString::fromLocal8Bit("邻接矩阵"));
    adjmatrixLabel->setGeometry(434, 400, 128, 20);
    adjmatrixBrowser = new QTextBrowser(ui->centralwidget);
    adjmatrixBrowser->setGeometry(434, 430, 128, 190);
    adjmatrixBrowser->setLineWrapMode(QTextEdit::NoWrap);

    backBtn = new QPushButton(ui->centralwidget);
    backBtn->setText(QString::fromLocal8Bit("返回主页"));
    backBtn->setGeometry(605, 580, 120, 40);
    backBtn->setCursor(QCursor(Qt::PointingHandCursor));
    exitBtn = new QPushButton(ui->centralwidget);
    exitBtn->setText(QString::fromLocal8Bit("退出程序"));
    exitBtn->setGeometry(745, 580, 120, 40);
    exitBtn->setCursor(QCursor(Qt::PointingHandCursor));

    //信号槽连接
    connect(generateGraph, SIGNAL(clicked()), this, SLOT(onClickGenerateGraphButton())); //生成图
    connect(generateAdjlist,
            SIGNAL(clicked()),
            this,
            SLOT(onClickGenerateAdjlistButton())); //生成邻接链表
    connect(generateMatrix,
            SIGNAL(clicked()),
            this,
            SLOT(onClickGenerateMatrixButton())); //生成邻接矩阵
    connect(MatrixSize,
            SIGNAL(currentIndexChanged(int)),
            this,
            SLOT(onCurrentIndexChangedMatrixSizeComboBox())); //选择邻接矩阵大小之后触发
    connect(GraphKind,
            SIGNAL(currentIndexChanged(int)),
            this,
            SLOT(onCurrentIndexChangedGraphKindComboBox())); //选择图的类型之后触发
    connect(bfsTraverse, SIGNAL(clicked()), this, SLOT(onClickBfsButton()));           //bfs遍历
    connect(dfsRecurTraverse, SIGNAL(clicked()), this, SLOT(onClickDfsRecurButton())); //dfs递归遍历
    connect(dfsNonrecurTraverse,
            SIGNAL(clicked()),
            this,
            SLOT(onClickDfsNonrecurButton())); //dfs非递归遍历
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(onClickExitButton()));
    connect(backBtn, SIGNAL(clicked()), this, SLOT(onClickBackButton()));
}
void OperateWindow::onClickGenerateMatrixButton()
{
    if (MatrixSize->currentIndex() != 0 && GraphKind->currentIndex() != 0) {
        startToGenerateMatrix = true;
        mg.setVexnum(size);
        mg.setGraphkind(kind);
        mg.generateMatrix();
        adjmatrixBrowser->setText(mg.CreateGraph());
    } else if (MatrixSize->currentIndex() != 0 && GraphKind->currentIndex() == 0) {
        startToGenerateMatrix = false;
        QMessageBox message(QMessageBox::NoIcon,
                            "Warning!",
                            QString::fromLocal8Bit("请选择建立的图的种类！"));
        message.exec();
    } else if (MatrixSize->currentIndex() == 0 && GraphKind->currentIndex() != 0) {
        startToGenerateMatrix = false;
        QMessageBox message(QMessageBox::NoIcon,
                            "Warning!",
                            QString::fromLocal8Bit("请选择邻接矩阵大小！"));
        message.exec();
    } else {
        startToGenerateMatrix = false;
        QMessageBox message(QMessageBox::NoIcon,
                            "Warning!",
                            QString::fromLocal8Bit("请选择邻接矩阵大小和建立的图的种类！"));
        message.exec();
    }
}
void OperateWindow::onClickGenerateAdjlistButton()
{
    if (startToGenerateMatrix == false) {
        QMessageBox message(QMessageBox::NoIcon,
                            "Warning!",
                            QString::fromLocal8Bit("请先生成邻接矩阵！"));
        message.exec();
    } else if (startToGenerateMatrix == true) {
        adjlistBrowser->setText(mg.DisplayALGraph());
    }
}
void OperateWindow::onClickGenerateGraphButton()
{
    if (startToGenerateMatrix == false) {
        startToGenerateGraph = false;
        QMessageBox message(QMessageBox::NoIcon,
                            "Warning!",
                            QString::fromLocal8Bit("请先生成邻接矩阵！"));
        message.exec();
    } else if (startToGenerateMatrix == true) {
        startToGenerateGraph = true;
        repaint(20, 10, 550, 380);
    }
}
void OperateWindow::onClickBfsButton()
{
    if (startToGenerateGraph || startToGenerateMatrix) {
        bfsBrowser->setText(mg.BFSTraverse());
    } else {
        QMessageBox message(QMessageBox::NoIcon,
                            "Warning!",
                            QString::fromLocal8Bit("请先生成邻接矩阵或图！"));
        message.exec();
    }
}
void OperateWindow::onClickDfsRecurButton()
{
    if (startToGenerateGraph || startToGenerateMatrix) {
        dfsBrowser->setText(mg.DFS_recursive());
    } else {
        QMessageBox message(QMessageBox::NoIcon,
                            "Warning!",
                            QString::fromLocal8Bit("请先生成邻接矩阵或图！"));
        message.exec();
    }
}
void OperateWindow::onClickDfsNonrecurButton()
{
    if (startToGenerateGraph || startToGenerateMatrix) {
        dfsBrowser->setText(mg.DFS_Nonrecursive());
    } else {
        QMessageBox message(QMessageBox::NoIcon,
                            "Warning!",
                            QString::fromLocal8Bit("请先生成邻接矩阵或图！"));
        message.exec();
    }
}
void OperateWindow::onCurrentIndexChangedGraphKindComboBox()
{
    kind = GraphKind->currentText();
    startToGenerateGraph = false;
    startToGenerateMatrix = false;
}
void OperateWindow::onCurrentIndexChangedMatrixSizeComboBox()
{
    size = MatrixSize->currentText();
    startToGenerateGraph = false;
    startToGenerateMatrix = false;
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
    transform.translate(280, 180); //中心点移动到graphbox中心
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
        painter.drawText(point[i].x() - 7, point[i].y() + 8, QString::number(i + 1));
        angle += delta;
    }
    QPen pen2;
    pen2.setColor(Qt::darkRed);
    pen2.setWidth(3);
    painter.setPen(pen2);
    if (mg.getGraphkind() == 1) { //有向图
                                  //        int **m;
                                  //        m = mg.getMatrix();
        for (int i = 0; i < vexnum; i++)
            for (int j = 1 + i; j < vexnum; j++)
                if (mg.arcs[i][j] != 0)
                    drawArrow(point[i], point[j], painter);
    } else if (mg.getGraphkind() == 3) { //无向图
                                         //        int **m;
                                         //        m = mg.getMatrix();
        for (int i = 0; i < vexnum; i++)
            for (int j = 1 + i; j < vexnum; j++)
                if (mg.arcs[i][j] != 0)
                    painter.drawLine(point[i], point[j]);
    }
}
void OperateWindow::drawArrow(QPoint startPoint, QPoint endPoint, QPainter &painter)
{
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0; //箭头的两点坐标
    //求得箭头两点坐标
    calcVertexes(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y(), x1, y1, x2, y2);
    painter.drawLine(startPoint, endPoint);                         //绘制线段
    painter.drawLine(endPoint.x(), endPoint.y(), int(x1), int(y1)); //绘制箭头一半
    painter.drawLine(endPoint.x(), endPoint.y(), int(x2), int(y2)); //绘制箭头另一半
}
void OperateWindow::calcVertexes(double start_x,
                                 double start_y,
                                 double end_x,
                                 double end_y,
                                 double &x1,
                                 double &y1,
                                 double &x2,
                                 double &y2)
{
    double arrow_lenght_ = 20;   //箭头长度，一般固定
    double arrow_degrees_ = 0.4; //箭头角度，一般固定

    double angle = atan2(end_y - start_y, end_x - start_x) + 3.1415926; //

    x1 = end_x + arrow_lenght_ * cos(angle - arrow_degrees_); //求得箭头点1坐标
    y1 = end_y + arrow_lenght_ * sin(angle - arrow_degrees_);
    x2 = end_x + arrow_lenght_ * cos(angle + arrow_degrees_); //求得箭头点2坐标
    y2 = end_y + arrow_lenght_ * sin(angle + arrow_degrees_);
}

OperateWindow::~OperateWindow()
{
    delete ui;
}
