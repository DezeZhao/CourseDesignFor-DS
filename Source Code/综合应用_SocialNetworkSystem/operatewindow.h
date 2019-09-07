#ifndef OPERATEWINDOW_H
#define OPERATEWINDOW_H

#include "addnodedialog.h"
#include "mgraph.h"
#include "networkwindow.h"
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
    void paintEvent(QPaintEvent *);
    ~OperateWindow();
signals:
    void returnMainWindow();

private:
    Ui::OperateWindow *ui;
    MGraph mg;
    QGroupBox *graphBox;
    QGroupBox *groupBox;
    QGroupBox *groupBox1;
    QGroupBox *groupBox2;
    QComboBox *selectNode;
    QPushButton *nodeNetwork;
    QPushButton *addNode;
    QTextBrowser *nodesNameBrowser;
    QTextBrowser *adjlistBrowser;
    QTextBrowser *adjmatrixBrowser;
    QLabel *nodesLabel;
    QLabel *adjlistLabel;
    QLabel *adjmatrixLabel;
    QPushButton *generateMatrix;
    QPushButton *generateAdjlist;
    QPushButton *generateGraph;
    QPushButton *generateNodes;
    QPushButton *backBtn;
    QPushButton *exitBtn;
    NetworkWindow nw;

private slots:
    void onCurrentIndexChangedSelectNodeComboBox(); //选择节点的下拉菜单改变的时候
    void onClickGenerateNodesButton();              //点击生成节点信息按钮
    void onClickGenerateMatrixButton();             //点击生成邻接矩阵按钮
    void onClickGenerateAdjlistButton();            //点击生成邻接链表按钮
    void onClickExitButton();                       //点击退出按钮
    void onClickBackButton();                       //点击返回按钮
    void onClickNodeNetworkButton();                //点击查看节点关系网络按钮
    void onClickAddNodeButton();                    //点击添加节点按钮
    void operateWindowBackSlot1();                  //返回窗体事件
};

#endif // OPERATEWINDOW_H
