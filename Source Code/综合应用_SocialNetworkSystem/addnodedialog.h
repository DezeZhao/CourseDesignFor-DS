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

    bool isValid();         //�ж���д�ڵ���Ϣ�Ƿ���Ч
    void setMessage();      //��¼��д���ı�
    void setHobby();        //��¼ѡ�����Ȥ����
    void setFriend();       //��¼�������ڵ�ĺ��ѹ�ϵ
    QString **getMessage(); //�õ���¼���ı�
    bool *getHobby();       //�õ���¼����Ȥ����
    bool *getFriend();      //�õ���¼���������ڵ�ĺ��ѹ�ϵ
    void addFriendItem(MGraph *MG); //��̬��ӵ�ǰͼ�еĽڵ���Ϣ��Ϊ��ѡ��ĺ��ѹ�ϵ�ڵ�
    int cancelFlag = false; //���ȡ����ť��־

private slots:
    void onClickOkButton();     //���ȷ����ť
    void onClickCancelButton(); //���ȡ����ť

private:
    Ui::AddNodeDialog *ui;
    MGraph *mg;
    QString *message[6]; //�ö�ά���齫ÿ���˵�����message�洢�������������
    //������Ϣ��ʱ�������������Ϣ
    bool hobbyMsg[8];
    bool friendMsg[10];
    //���������Ϣ
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
