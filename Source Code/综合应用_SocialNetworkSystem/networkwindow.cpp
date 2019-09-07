#include "networkwindow.h"
#include "ui_networkwindow.h"
#include <QtMath>

NetworkWindow::NetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NetworkWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 680);
    setWindowTitle(QString::fromLocal8Bit("个人社会关系网络及详细信息页面"));

    graphBox = new QGroupBox(ui->centralwidget);
    graphBox->setTitle(QString::fromLocal8Bit("个人社会关系网络图"));
    graphBox->setGeometry(20, 10, 550, 380);

    detailInfoLabel = new QLabel(ui->centralwidget);
    detailInfoLabel->setGeometry(20, 400, 165, 20);
    detailInfoLabel->setText(QString::fromLocal8Bit("详细信息:"));
    detailInfoBrowser = new QTextBrowser(ui->centralwidget);
    detailInfoBrowser->setGeometry(20, 430, 165, 190);
    detailInfoBrowser->setLineWrapMode(QTextEdit::NoWrap);

    hobbyLabel = new QLabel(ui->centralwidget);
    hobbyLabel->setGeometry(205, 400, 165, 20);
    hobbyLabel->setText(QString::fromLocal8Bit("兴趣爱好:"));
    hobbyBrowser = new QTextBrowser(ui->centralwidget);
    hobbyBrowser->setGeometry(205, 430, 165, 190);
    hobbyBrowser->setLineWrapMode(QTextEdit::NoWrap);

    correlationLabel = new QLabel(ui->centralwidget);
    correlationLabel->setText(QString::fromLocal8Bit("关联度解析:"));
    correlationLabel->setGeometry(390, 400, 165, 20);
    correlationBrowser = new QTextBrowser(ui->centralwidget);
    correlationBrowser->setGeometry(390, 430, 165, 190);
    correlationBrowser->setLineWrapMode(QTextEdit::NoWrap);

    backBtn = new QPushButton(ui->centralwidget);
    backBtn->setText(QString::fromLocal8Bit("返回操作页"));
    backBtn->setGeometry(605, 500, 160, 40);
    backBtn->setCursor(QCursor(Qt::PointingHandCursor));
    exitBtn = new QPushButton(ui->centralwidget);
    exitBtn->setText(QString::fromLocal8Bit("退出程序"));
    exitBtn->setGeometry(605, 560, 160, 40);
    exitBtn->setCursor(QCursor(Qt::PointingHandCursor));

    //槽函数与信号连接
    connect(backBtn, SIGNAL(clicked()), this, SLOT(onClickBackButton()));
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(onClickExitButton()));
}
void NetworkWindow::onClickBackButton()
{
    emit returnOperateWindow();
}
void NetworkWindow::onClickExitButton()
{
    QApplication *app = nullptr;
    app->quit();
}
void NetworkWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen; //画笔
    painter.setRenderHint(QPainter::Antialiasing);
    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(3);
    //    QBrush brush(QColor(0, 255, 0, 125)); //画刷
    painter.setPen(pen); //添加画笔
                         //   painter.setBrush(brush);              //添加画刷

    int examRadius = 30;
    int examX = 610;
    int examY = 30;
    QRect rectExam1(examX, examY, examRadius, examRadius); //构造一个矩形
    pen.setColor(QColor(Qt::red));
    painter.setPen(pen); //添加画笔
    painter.drawEllipse(rectExam1);
    pen.setColor(QColor(Qt::black));
    painter.setPen(pen);
    QString examStr = QString::fromLocal8Bit("当前结点");
    QPoint pt = {rectExam1.bottomRight().rx() + 10,
                 int((rectExam1.bottomRight().ry() + rectExam1.topRight().ry()) / 2) + 5};
    painter.drawText(pt, examStr);

    QRect rectExam2(examX, examY + 40, examRadius, examRadius); //构造一个矩形
    pen.setColor(QColor(Qt::blue));
    painter.setPen(pen); //添加画笔
    painter.drawEllipse(rectExam2);
    pen.setColor(QColor(Qt::black));
    painter.setPen(pen);
    examStr = QString::fromLocal8Bit("好友结点");
    pt = {rectExam2.bottomRight().rx() + 10,
          int((rectExam2.bottomRight().ry() + rectExam2.topRight().ry()) / 2) + 5};
    painter.drawText(pt, examStr);

    QRect rectExam3(examX, examY + 80, examRadius, examRadius); //构造一个矩形
    pen.setColor(QColor(Qt::darkGreen));
    painter.setPen(pen); //添加画笔
    painter.drawEllipse(rectExam3);
    pen.setColor(QColor(Qt::black));
    painter.setPen(pen);
    examStr = QString::fromLocal8Bit("可能认识的结点");
    pt = {rectExam3.bottomRight().rx() + 10,
          int((rectExam3.bottomRight().ry() + rectExam3.topRight().ry()) / 2) + 5};
    painter.drawText(pt, examStr);

    int radius = 50;
    VertexType p = mg->getPersonNode(id); //取得id结点
    int vexnum = mg->getVexnum();
    double angle = 0;
    double delta = 2 * 3.1415926 / vexnum;

    QTransform transform;
    transform.translate(270, 180);
    transform.rotate(0);
    painter.setWorldTransform(transform);

    double cx = 0, cy = 0;
    double px = 150, py = 0;

    QPoint point[MAX_VERTEX_NUM];

    for (int i = 0; i < vexnum; i++) {
        cx = px * cos(angle) - py * sin(angle);
        cy = px * sin(angle) + py * cos(angle);

        QRect rect(int(cx), int(cy), radius, radius); //构造一个矩形
        point[i] = rect.center();

        if (i == id) {
            QPen pen((QColor(Qt::red)));
            pen.setWidth(3);
            painter.setPen(pen);
        } else if (mg->correlate(i, id)) {
            QPen pen((QColor(Qt::blue)));
            pen.setWidth(3);
            painter.setPen(pen);
        } else {
            QPen pen((QColor(Qt::darkGreen)));
            pen.setWidth(3);
            painter.setPen(pen);
        }

        painter.drawEllipse(rect);
        angle += delta;
    }
    pen.setColor(QColor(Qt::black));
    painter.setPen(pen);
    for (int i = 0; i < vexnum - 1; i++) {
        for (int j = 1 + i; j < vexnum; j++) {
            if (mg->correlate(i, j) == 1)
                painter.drawLine(point[i], point[j]);
        }
    }
    QFont font; //设置字体
    font.setPixelSize(25);
    font.setWeight(QFont::Black);
    painter.setFont(font);
    for (int i = 0; i < vexnum; i++) {
        VertexType p = mg->getPersonNode(i);
        painter.drawText(point[i].x() - 7, point[i].y() + 8, QString::number(p.getId()));
    }
    //detailInfoBrowser
    QString qstr = nullptr;
    qstr += QString::fromLocal8Bit("姓名：") + p.getName() + "\n";
    qstr += QString::fromLocal8Bit("地区：") + p.getRegion() + "\n";
    qstr += QString::fromLocal8Bit("小学：") + p.getPrimarySchool() + "\n";
    qstr += QString::fromLocal8Bit("中学：") + p.getMiddleSchool() + "\n";
    qstr += QString::fromLocal8Bit("大学：") + p.getHighSchool() + "\n";
    qstr += QString::fromLocal8Bit("工作单位：") + p.getWorkPlace() + "\n";
    detailInfoBrowser->setText(qstr);

    //hobbyBrowser
    qstr = nullptr;
    bool flag = false;
    bool *Hobby = p.getHobbies();
    if (Hobby[0]) {
        qstr += QString::fromLocal8Bit("打篮球\n");
        flag = true;
    }
    if (Hobby[1]) {
        qstr += QString::fromLocal8Bit("踢足球\n");
        flag = true;
    }
    if (Hobby[2]) {
        qstr += QString::fromLocal8Bit("打乒乓球\n");
        flag = true;
    }
    if (Hobby[3]) {
        qstr += QString::fromLocal8Bit("打羽毛球\n");
        flag = true;
    }
    if (Hobby[4]) {
        qstr += QString::fromLocal8Bit("游泳\n");
        flag = true;
    }
    if (Hobby[5]) {
        qstr += QString::fromLocal8Bit("旅行\n");
        flag = true;
    }
    if (Hobby[6]) {
        qstr += QString::fromLocal8Bit("摄影\n");
        flag = true;
    }
    if (Hobby[7]) {
        qstr += QString::fromLocal8Bit("阅读\n");
        flag = true;
    }
    if (Hobby[8]) {
        qstr += QString::fromLocal8Bit("编程\n");
        flag = true;
    }
    if (Hobby[9]) {
        qstr += QString::fromLocal8Bit("看电影\n");
        flag = true;
    }

    if (!flag)
        qstr += QString::fromLocal8Bit("该节点兴趣爱好.\n");
    hobbyBrowser->setText(qstr);

    // correlationBrowser
    qstr = nullptr;
    mg->setCorrelation(id);
    int *correlation = mg->getCorrelation();
    int a[MAX_VERTEX_NUM];
    for (int i = 0; i < MAX_VERTEX_NUM; i++)
        a[i] = i;
    int temp = 0;
    for (int i = 0; i < vexnum - 1; i++) {
        for (int j = 0; j < vexnum - i - 1; j++) {
            if (correlation[j] < correlation[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                temp = correlation[j];
                correlation[j] = correlation[j + 1];
                correlation[j + 1] = temp;
            }
        }
    }
    if (correlation[0] == -1) {
        qstr += QString::fromLocal8Bit("该节点与非好友节点无关联.\n");
    } else {
        for (int i = 0; i < vexnum; i++) {
            if (correlation[i] != -1) {
                VertexType p = mg->getPersonNode(a[i]);
                qstr += QString::number(p.getId()) + "-" + p.getName()
                        + QString::fromLocal8Bit("-关联度-") + QString::number(correlation[i])
                        + "\n";
            }
        }
    }
    correlationBrowser->setText(qstr);
    //end
}
void NetworkWindow::setId(int id)
{
    this->id = id;
}
void NetworkWindow::setMGraph(MGraph *mg)
{
    this->mg = mg;
}
NetworkWindow::~NetworkWindow()
{
    delete ui;
}
