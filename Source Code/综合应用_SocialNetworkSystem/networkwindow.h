#ifndef NETWORKWINDOW_H
#define NETWORKWINDOW_H

#include "mgraph.h"
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QPushButton>
#include <QTextBrowser>
namespace Ui {
class NetworkWindow;
}

class NetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NetworkWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void setId(int id);
    void setMGraph(MGraph *mg);
    ~NetworkWindow();
private slots:
    void onClickBackButton();
    void onClickExitButton();

private:
    Ui::NetworkWindow *ui;
    int id;
    MGraph *mg;
    QGroupBox *graphBox;
    QGroupBox *groupBox;
    QGroupBox *groupBox1;
    QGroupBox *groupBox2;
    QComboBox *selectNode;
    QPushButton *nodeNetwork;
    QPushButton *addNode;
    QTextBrowser *hobbyBrowser;
    QTextBrowser *detailInfoBrowser;
    QTextBrowser *correlationBrowser;
    QLabel *hobbyLabel;
    QLabel *detailInfoLabel;
    QLabel *correlationLabel;
    QPushButton *backBtn;
    QPushButton *exitBtn;
signals:
    void returnOperateWindow();
};

#endif // NETWORKWINDOW_H
