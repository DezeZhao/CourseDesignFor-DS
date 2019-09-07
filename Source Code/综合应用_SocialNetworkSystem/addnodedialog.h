#ifndef ADDNODEDIALOG_H
#define ADDNODEDIALOG_H
#include "mgraph.h"
#include <QButtonGroup>
#include <QCheckBox>
#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>

namespace Ui {
class AddNodeDialog;
}

class AddNodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNodeDialog(QWidget *parent = nullptr);
    ~AddNodeDialog();

    bool isValid();         //判断填写节点信息是否有效
    void setMessage();      //记录填写的文本
    void setHobby();        //记录选择和兴趣爱好
    void setFriend();       //记录与其他节点的好友关系
    QString **getMessage(); //得到记录的文本
    bool *getHobby();       //得到记录的兴趣爱好
    bool *getFriend();      //得到记录的与其他节点的好友关系
    void addFriendItem(MGraph *MG); //动态添加当前图中的节点信息作为备选择的好友关系节点
    int cancelFlag = false; //点击取消按钮标志

private slots:
    void onClickOkButton();     //点击确定按钮
    void onClickCancelButton(); //点击取消按钮

private:
    Ui::AddNodeDialog *ui;
    MGraph *mg;
    QString *message[6]; //用二维数组将每个人的输入message存储起来方便在输出
    //个人信息的时候按照索引输出信息
    bool hobbyMsg[8];
    bool friendMsg[10];
    //输入个人信息
    QLabel *nameLabel;
    QLabel *regionLabel;
    QLabel *primarySchoolLabel;
    QLabel *middleSchoolLabel;
    QLabel *highSchoolLabel;
    QLabel *workOrginizationLabel;

    QLineEdit *nameLineEdit;
    QLineEdit *regionLineEdit;
    QLineEdit *primarySchoolLineEdit;
    QLineEdit *middleSchoolLineEdit;
    QLineEdit *highSchoolLineEdit;
    QLineEdit *workOrginizationLineEdit;

    QHBoxLayout *buttonLayout;
    QButtonGroup *hobbyGroup;
    QGridLayout *gridLayout;
    QVBoxLayout *dialogLayout;

    QCheckBox *basketballButton;
    QCheckBox *footballButton;
    QCheckBox *pingpangButton;
    QCheckBox *badmintonButton;
    QCheckBox *swimmingButton;
    QCheckBox *travellingButton;
    QCheckBox *photographyButton;
    QCheckBox *readingButton;
    QCheckBox *programButton;
    QCheckBox *moviesButton;

    QLabel *spaceLabel1;
    QLabel *titleHobby;
    QLabel *spaceLabel2;
    QLabel *titleFriendList;
    QButtonGroup *friendList;
    QCheckBox *friend1;
    QCheckBox *friend2;

    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // ADDNODEDIALOG_H
