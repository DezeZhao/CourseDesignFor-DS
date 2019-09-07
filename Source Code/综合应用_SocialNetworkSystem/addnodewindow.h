#ifndef ADDNODEWINDOW_H
#define ADDNODEWINDOW_H

#include <QButtonGroup>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>

namespace Ui {
class AddNodeWindow;
}

class AddNodeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNodeWindow(QWidget *parent = nullptr);
    ~AddNodeWindow();

private:
    Ui::AddNodeWindow *ui;

private:
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

    QPushButton *okBtn;
    QPushButton *cancelBtn;

    QHBoxLayout *btnLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *dlgLayout;

    QString *message[6];
    bool hobbyMes[8];
    bool friendMes[10];

    QButtonGroup *HobbyGroup;

    QRadioButton *SwimmingButton;
    QRadioButton *BasketballButton;
    QRadioButton *FootballButton;
    QRadioButton *TaichiButton;
    QRadioButton *TennisButton;
    QRadioButton *ReadingButton;
    QRadioButton *GamingButton;
    QRadioButton *TravellingButton;

    QLabel *spaceLabel1;
    QLabel *TitleHobby;

    QButtonGroup *FriendListGroup;

    QRadioButton *Friend1;
    QRadioButton *Friend2;
    QRadioButton *Friend3;
    QRadioButton *Friend4;
    QRadioButton *Friend5;
    QRadioButton *Friend6;
    QRadioButton *Friend7;
    QRadioButton *Friend8;
    QRadioButton *Friend9;
    QRadioButton *Friend10;

    QLabel *spaceLabel2;
    QLabel *TitleFriendList;
};

#endif // ADDNODEWINDOW_H
