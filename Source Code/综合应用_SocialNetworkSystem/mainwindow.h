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
    //�˵���
    QAction *Exit; //����Exit����
    QMenu *File;   //����File�˵�
    //label
    QLabel *Qlabel; //question
    QLabel *Tlabel; //title
    //button
    QPushButton *enter;
    // operate window
    OperateWindow ow;
public slots:
    void exitActionSlot();        //��ҳ�˵������˳������¼�
    void onEnterButtonClick();    //���������ʾ��ť
    void operateWindowBackSlot(); //�������ڷ���ʱ��
};

#endif // MAINWINDOW_H
