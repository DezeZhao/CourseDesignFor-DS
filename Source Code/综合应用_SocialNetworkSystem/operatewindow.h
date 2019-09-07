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
    void onCurrentIndexChangedSelectNodeComboBox(); //ѡ��ڵ�������˵��ı��ʱ��
    void onClickGenerateNodesButton();              //������ɽڵ���Ϣ��ť
    void onClickGenerateMatrixButton();             //��������ڽӾ���ť
    void onClickGenerateAdjlistButton();            //��������ڽ�����ť
    void onClickExitButton();                       //����˳���ť
    void onClickBackButton();                       //������ذ�ť
    void onClickNodeNetworkButton();                //����鿴�ڵ��ϵ���簴ť
    void onClickAddNodeButton();                    //�����ӽڵ㰴ť
    void operateWindowBackSlot1();                  //���ش����¼�
};

#endif // OPERATEWINDOW_H
