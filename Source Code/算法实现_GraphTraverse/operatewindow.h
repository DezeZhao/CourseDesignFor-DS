#ifndef OPERATEWINDOW_H
#define OPERATEWINDOW_H

#include "mgraph.h"
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTextBrowser>

namespace Ui {
class OperateWindow;
}

class OperateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OperateWindow(QWidget *parent = nullptr);
    ~OperateWindow();
    void calcVertexes(double start_x,
                      double start_y,
                      double end_x,
                      double end_y,
                      double &x1,
                      double &y1,
                      double &x2,
                      double &y2);
    void drawArrow(QPoint startPoint, QPoint endPoint, QPainter &painter);
    void paintEvent(QPaintEvent *);

private slots:
    void onClickGenerateGraphButton();   //�������ͼ��ť
    void onClickGenerateMatrixButton();  //��������ڽӾ���ť
    void onClickGenerateAdjlistButton(); //��������ڽ�����ť
    void onCurrentIndexChangedMatrixSizeComboBox(); //ѡ���ڽӾ����С�������˵���������ı��¼�����ʱ
    void onCurrentIndexChangedGraphKindComboBox(); //ѡ��ͼ������������˵���������ı��¼�����ʱ
    void onClickBfsButton();                       //���BFS������ť
    void onClickDfsRecurButton();    //���dfs�ݹ������ť
    void onClickDfsNonrecurButton(); //���dfs�ǵݹ������ť
    void onClickExitButton();        //����˳�����ť
    void onClickBackButton();        //������ذ�ť
signals:
    void returnMainWindow();

private:
    Ui::OperateWindow *ui;
    bool startToGenerateMatrix = false;
    bool startToGenerateGraph = false;
    QComboBox *MatrixSize;
    QComboBox *GraphKind;
    QGroupBox *groupBox;
    QGroupBox *groupBox1;
    QGroupBox *groupBox2;
    QGroupBox *groupBox3;
    QGroupBox *groupBox4;
    QGroupBox *graphBox;
    QPushButton *generateMatrix;
    QPushButton *generateAdjlist;
    QPushButton *generateGraph;
    QPushButton *bfsTraverse;
    QPushButton *dfsRecurTraverse;
    QPushButton *dfsNonrecurTraverse;
    QTextBrowser *bfsBrowser;
    QTextBrowser *dfsBrowser;
    QTextBrowser *adjlistBrowser;
    QTextBrowser *adjmatrixBrowser;
    QLabel *bfsLabel;
    QLabel *dfsLabel;
    QLabel *adjlistLabel;
    QLabel *adjmatrixLabel;
    QPushButton *backBtn;
    QPushButton *exitBtn;
    MGraph mg;
    QString size;
    QString kind;
};

#endif // OPERATEWINDOW_H
