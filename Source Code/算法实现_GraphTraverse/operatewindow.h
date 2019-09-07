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
    void onClickGenerateGraphButton();   //点击生成图按钮
    void onClickGenerateMatrixButton();  //点击生成邻接矩阵按钮
    void onClickGenerateAdjlistButton(); //点击生成邻接链表按钮
    void onCurrentIndexChangedMatrixSizeComboBox(); //选择邻接矩阵大小的下拉菜单项的索引改变事件发生时
    void onCurrentIndexChangedGraphKindComboBox(); //选择图的种类的下拉菜单项的索引改变事件发生时
    void onClickBfsButton();                       //点击BFS遍历按钮
    void onClickDfsRecurButton();    //点击dfs递归遍历按钮
    void onClickDfsNonrecurButton(); //点击dfs非递归遍历按钮
    void onClickExitButton();        //点击退出程序按钮
    void onClickBackButton();        //点击返回按钮
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
