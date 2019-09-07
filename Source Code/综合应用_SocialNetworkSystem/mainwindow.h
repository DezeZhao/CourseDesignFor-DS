#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "operatewindow.h"
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QApplication *app;
    //菜单栏
    QAction *Exit; //定义Exit动作
    QMenu *File;   //定义File菜单
    //label
    QLabel *Qlabel; //question
    QLabel *Tlabel; //title
    //button
    QPushButton *enter;
    // operate window
    OperateWindow ow;
public slots:
    void exitActionSlot();        //主页菜单栏的退出程序事件
    void onEnterButtonClick();    //点击进入演示按钮
    void operateWindowBackSlot(); //操作窗口返回时间
};

#endif // MAINWINDOW_H
