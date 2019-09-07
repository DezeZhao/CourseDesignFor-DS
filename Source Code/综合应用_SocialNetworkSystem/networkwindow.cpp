#include "networkwindow.h"
#include "ui_networkwindow.h"
#include <QtMath>

NetworkWindow::NetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NetworkWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 680);
    setWindowTitle(QString::fromLocal8Bit("��������ϵ���缰��ϸ��Ϣҳ��"));

    graphBox = new QGroupBox(ui->centralwidget);
    graphBox->setTitle(QString::fromLocal8Bit("��������ϵ����ͼ"));
    graphBox->setGeometry(20, 10, 550, 380);

    detailInfoLabel = new QLabel(ui->centralwidget);
    detailInfoLabel->setGeometry(20, 400, 165, 20);
    detailInfoLabel->setText(QString::fromLocal8Bit("��ϸ��Ϣ:"));
    detailInfoBrowser = new QTextBrowser(ui->centralwidget);
    detailInfoBrowser->setGeometry(20, 430, 165, 190);
    detailInfoBrowser->setLineWrapMode(QTextEdit::NoWrap);

    hobbyLabel = new QLabel(ui->centralwidget);
    hobbyLabel->setGeometry(205, 400, 165, 20);
    hobbyLabel->setText(QString::fromLocal8Bit("��Ȥ����:"));
    hobbyBrowser = new QTextBrowser(ui->centralwidget);
    hobbyBrowser->setGeometry(205, 430, 165, 190);
    hobbyBrowser->setLineWrapMode(QTextEdit::NoWrap);

    correlationLabel = new QLabel(ui->centralwidget);
    correlationLabel->setText(QString::fromLocal8Bit("�����Ƚ���:"));
    correlationLabel->setGeometry(390, 400, 165, 20);
    correlationBrowser = new QTextBrowser(ui->centralwidget);
    correlationBrowser->setGeometry(390, 430, 165, 190);
    correlationBrowser->setLineWrapMode(QTextEdit::NoWrap);

    backBtn = new QPushButton(ui->centralwidget);
    backBtn->setText(QString::fromLocal8Bit("���ز���ҳ"));
    backBtn->setGeometry(605, 500, 160, 40);
    backBtn->setCursor(QCursor(Qt::PointingHandCursor));
    exitBtn = new QPushButton(ui->centralwidget);
    exitBtn->setText(QString::fromLocal8Bit("�˳�����"));
    exitBtn->setGeometry(605, 560, 160, 40);
    exitBtn->setCursor(QCursor(Qt::PointingHandCursor));

    //�ۺ������ź�����
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
    QPen pen; //����
    painter.setRenderHint(QPainter::Antialiasing);
    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(3);
    //    QBrush brush(QColor(0, 255, 0, 125)); //��ˢ
    painter.setPen(pen); //��ӻ���
                         //   painter.setBrush(brush);              //��ӻ�ˢ

    int examRadius = 30;
    int examX = 610;
    int examY = 30;
    QRect rectExam1(examX, examY, examRadius, examRadius); //����һ������
    pen.setColor(QColor(Qt::red));
    painter.setPen(pen); //��ӻ���
    painter.drawEllipse(rectExam1);
    pen.setColor(QColor(Qt::black));
    painter.setPen(pen);
    QString examStr = QString::fromLocal8Bit("��ǰ���");
    QPoint pt = {rectExam1.bottomRight().rx() + 10,
                 int((rectExam1.bottomRight().ry() + rectExam1.topRight().ry()) / 2) + 5};
    painter.drawText(pt, examStr);

    QRect rectExam2(examX, examY + 40, examRadius, examRadius); //����һ������
    pen.setColor(QColor(Qt::blue));
    painter.setPen(pen); //��ӻ���
    painter.drawEllipse(rectExam2);
    pen.setColor(QColor(Qt::black));
    painter.setPen(pen);
    examStr = QString::fromLocal8Bit("���ѽ��");
    pt = {rectExam2.bottomRight().rx() + 10,
          int((rectExam2.bottomRight().ry() + rectExam2.topRight().ry()) / 2) + 5};
    painter.drawText(pt, examStr);

    QRect rectExam3(examX, examY + 80, examRadius, examRadius); //����һ������
    pen.setColor(QColor(Qt::darkGreen));
    painter.setPen(pen); //��ӻ���
    painter.drawEllipse(rectExam3);
    pen.setColor(QColor(Qt::black));
    painter.setPen(pen);
    examStr = QString::fromLocal8Bit("������ʶ�Ľ��");
    pt = {rectExam3.bottomRight().rx() + 10,
          int((rectExam3.bottomRight().ry() + rectExam3.topRight().ry()) / 2) + 5};
    painter.drawText(pt, examStr);

    int radius = 50;
    VertexType p = mg->getPersonNode(id); //ȡ��id���
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

        QRect rect(int(cx), int(cy), radius, radius); //����һ������
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
    QFont font; //��������
    font.setPixelSize(25);
    font.setWeight(QFont::Black);
    painter.setFont(font);
    for (int i = 0; i < vexnum; i++) {
        VertexType p = mg->getPersonNode(i);
        painter.drawText(point[i].x() - 7, point[i].y() + 8, QString::number(p.getId()));
    }
    //detailInfoBrowser
    QString qstr = nullptr;
    qstr += QString::fromLocal8Bit("������") + p.getName() + "\n";
    qstr += QString::fromLocal8Bit("������") + p.getRegion() + "\n";
    qstr += QString::fromLocal8Bit("Сѧ��") + p.getPrimarySchool() + "\n";
    qstr += QString::fromLocal8Bit("��ѧ��") + p.getMiddleSchool() + "\n";
    qstr += QString::fromLocal8Bit("��ѧ��") + p.getHighSchool() + "\n";
    qstr += QString::fromLocal8Bit("������λ��") + p.getWorkPlace() + "\n";
    detailInfoBrowser->setText(qstr);

    //hobbyBrowser
    qstr = nullptr;
    bool flag = false;
    bool *Hobby = p.getHobbies();
    if (Hobby[0]) {
        qstr += QString::fromLocal8Bit("������\n");
        flag = true;
    }
    if (Hobby[1]) {
        qstr += QString::fromLocal8Bit("������\n");
        flag = true;
    }
    if (Hobby[2]) {
        qstr += QString::fromLocal8Bit("��ƹ����\n");
        flag = true;
    }
    if (Hobby[3]) {
        qstr += QString::fromLocal8Bit("����ë��\n");
        flag = true;
    }
    if (Hobby[4]) {
        qstr += QString::fromLocal8Bit("��Ӿ\n");
        flag = true;
    }
    if (Hobby[5]) {
        qstr += QString::fromLocal8Bit("����\n");
        flag = true;
    }
    if (Hobby[6]) {
        qstr += QString::fromLocal8Bit("��Ӱ\n");
        flag = true;
    }
    if (Hobby[7]) {
        qstr += QString::fromLocal8Bit("�Ķ�\n");
        flag = true;
    }
    if (Hobby[8]) {
        qstr += QString::fromLocal8Bit("���\n");
        flag = true;
    }
    if (Hobby[9]) {
        qstr += QString::fromLocal8Bit("����Ӱ\n");
        flag = true;
    }

    if (!flag)
        qstr += QString::fromLocal8Bit("�ýڵ���Ȥ����.\n");
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
        qstr += QString::fromLocal8Bit("�ýڵ���Ǻ��ѽڵ��޹���.\n");
    } else {
        for (int i = 0; i < vexnum; i++) {
            if (correlation[i] != -1) {
                VertexType p = mg->getPersonNode(a[i]);
                qstr += QString::number(p.getId()) + "-" + p.getName()
                        + QString::fromLocal8Bit("-������-") + QString::number(correlation[i])
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
