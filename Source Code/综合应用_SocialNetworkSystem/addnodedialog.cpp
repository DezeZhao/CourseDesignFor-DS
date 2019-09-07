#include "addnodedialog.h"
#include "ui_addnodedialog.h"
#include <QDebug>

AddNodeDialog::AddNodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNodeDialog)
{
    ui->setupUi(this);
    //   resize(600, 400);
    setWindowTitle(QString::fromLocal8Bit("添加节点页面"));

    //////////////////////////////////////详细信息////////////////////////////////////////
    nameLabel = new QLabel(QString::fromLocal8Bit("姓名"));
    regionLabel = new QLabel(QString::fromLocal8Bit("地区"));
    primarySchoolLabel = new QLabel(QString::fromLocal8Bit("小学"));
    middleSchoolLabel = new QLabel(QString::fromLocal8Bit("中学"));
    highSchoolLabel = new QLabel(QString::fromLocal8Bit("大学"));
    workOrginizationLabel = new QLabel(QString::fromLocal8Bit("工作单位"));
    spaceLabel1 = new QLabel(tr(" "));

    nameLineEdit = new QLineEdit;
    regionLineEdit = new QLineEdit;
    primarySchoolLineEdit = new QLineEdit;
    middleSchoolLineEdit = new QLineEdit;
    highSchoolLineEdit = new QLineEdit;
    workOrginizationLineEdit = new QLineEdit;

    //创建一个网格布局管理器对象，将lineedit 和label添加到其中
    //QWidget * widget, int fromRow, int fromColumn, int rowSpan, int columnSpan, Qt::Alignment
    gridLayout = new QGridLayout;
    gridLayout->addWidget(nameLabel, 0, 0, 1, 2);     //第一行，第一列 占1行1列
    gridLayout->addWidget(nameLineEdit, 0, 1, 1, 12); //第一行，第二列

    gridLayout->addWidget(regionLabel, 1, 0, 1, 1);
    gridLayout->addWidget(regionLineEdit, 1, 1, 1, 12);

    gridLayout->addWidget(primarySchoolLabel, 2, 0, 1, 1);
    gridLayout->addWidget(primarySchoolLineEdit, 2, 1, 1, 12);

    gridLayout->addWidget(middleSchoolLabel, 3, 0, 1, 1);
    gridLayout->addWidget(middleSchoolLineEdit, 3, 1, 1, 12);

    gridLayout->addWidget(highSchoolLabel, 4, 0, 1, 1);
    gridLayout->addWidget(highSchoolLineEdit, 4, 1, 1, 12);

    gridLayout->addWidget(workOrginizationLabel, 5, 0, 1, 1);
    gridLayout->addWidget(workOrginizationLineEdit, 5, 1, 1, 12);

    gridLayout->addWidget(spaceLabel1, 6, 0, 1, 16);
    /////////////////////////////////////////////////////////////////////////////////

    ///////////////兴趣爱好///////////////////////////////////////////////////////////
    titleHobby = new QLabel(QString::fromLocal8Bit("兴趣爱好:"));
    basketballButton = new QCheckBox(QString::fromLocal8Bit("打篮球"), this);
    footballButton = new QCheckBox(QString::fromLocal8Bit("踢足球"), this);
    pingpangButton = new QCheckBox(QString::fromLocal8Bit("打乒乓球"), this);
    badmintonButton = new QCheckBox(QString::fromLocal8Bit("打羽毛球"), this);
    swimmingButton = new QCheckBox(QString::fromLocal8Bit("游泳"), this);
    travellingButton = new QCheckBox(QString::fromLocal8Bit("旅行"), this);
    photographyButton = new QCheckBox(QString::fromLocal8Bit("摄影"), this);
    readingButton = new QCheckBox(QString::fromLocal8Bit("阅读"), this);
    programButton = new QCheckBox(QString::fromLocal8Bit("编程"), this);
    moviesButton = new QCheckBox(QString::fromLocal8Bit("看电影"), this);

    hobbyGroup = new QButtonGroup(this);
    hobbyGroup->addButton(basketballButton, 1);
    hobbyGroup->addButton(footballButton, 2);
    hobbyGroup->addButton(pingpangButton, 3);
    hobbyGroup->addButton(badmintonButton, 4);
    hobbyGroup->addButton(swimmingButton, 5);
    hobbyGroup->addButton(travellingButton, 6);
    hobbyGroup->addButton(photographyButton, 7);
    hobbyGroup->addButton(readingButton, 8);
    hobbyGroup->addButton(programButton, 9);
    hobbyGroup->addButton(moviesButton, 10);
    hobbyGroup->setExclusive(false);

    buttonLayout = new QHBoxLayout;
    gridLayout->addWidget(titleHobby, 7, 0, 1, 4);

    QList<QAbstractButton *> list = hobbyGroup->buttons();
    auto listEnd = list.end();
    auto listBegin = list.begin();
    int i;
    for (auto it = list.begin(); it != listEnd; ++it) {
        i = it - listBegin;
        if (i < 5) {
            gridLayout->addWidget(*it, 8, 4 * i, 1, 4);
        } else {
            gridLayout->addWidget(*it, 9, 4 * (i - 5), 1, 4);
        }
    }
    //////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////好友关系/////////////////////////////////////
    spaceLabel2 = new QLabel(tr(" "));
    titleFriendList = new QLabel(QString::fromLocal8Bit("与其他节点的好友关系:"));
    gridLayout->addWidget(spaceLabel2, 10, 0, 1, 16);
    gridLayout->addWidget(titleFriendList, 11, 0, 1, 16);
    friendList = new QButtonGroup(this);
    //初始化两个节点
    friend1 = new QCheckBox(QString::fromLocal8Bit("0-赵得泽"), this);
    friend2 = new QCheckBox(QString::fromLocal8Bit("1-汤海迪"), this);
    friendList->addButton(friend1, 1);
    friendList->addButton(friend2, 2);
    gridLayout->addWidget(friend1, 12, 0, 1, 2);
    gridLayout->addWidget(friend2, 12, 2, 1, 2);
    friendList->setExclusive(false);
    /////////////////////////////////////////////////////////////////////////////////
    //创建两个按钮对象和一个水平布局管理器对象，并将按钮添加到该布局管理器中
    okBtn = new QPushButton(QString::fromLocal8Bit("确定"));
    cancelBtn = new QPushButton(QString::fromLocal8Bit("取消"));
    buttonLayout = new QHBoxLayout;
    buttonLayout->setSpacing(60);
    buttonLayout->addWidget(okBtn);
    buttonLayout->addWidget(cancelBtn);

    //创建一个垂直布局管理器对象，并将水平和网格布局管理器添加到该管理器中
    dialogLayout = new QVBoxLayout;
    dialogLayout->setMargin(50);
    dialogLayout->addLayout(gridLayout);
    dialogLayout->addStretch(50);
    dialogLayout->addLayout(buttonLayout);
    setLayout(dialogLayout);

    //连接信号与槽
    connect(okBtn, SIGNAL(clicked()), this, SLOT(onClickOkButton()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(onClickCancelButton()));
}
void AddNodeDialog::onClickOkButton()
{
    setMessage();
    setHobby();
    setFriend();
    if (isValid()) {
        this->close();
    } else {
        QMessageBox warnning(QMessageBox::Warning,
                             "Warning",
                             QString::fromLocal8Bit("请将详细信息栏填写完整！"));
        warnning.exec();
    }
}
void AddNodeDialog::onClickCancelButton()
{
    cancelFlag = true;
    this->close();
}
void AddNodeDialog::setMessage()
{
    for (int i = 0; i < 6; i++)
        message[i] = new QString;

    *(message[0]) = nameLineEdit->text();
    *(message[1]) = regionLineEdit->text();
    *(message[2]) = primarySchoolLineEdit->text();
    *(message[3]) = middleSchoolLineEdit->text();
    *(message[4]) = highSchoolLineEdit->text();
    *(message[5]) = workOrginizationLineEdit->text();
}
void AddNodeDialog::setHobby()
{
    QList<QAbstractButton *> list = hobbyGroup->buttons();
    auto listBegin = list.begin();
    auto listEnd = list.end();
    for (auto it = list.begin(); it != listEnd; ++it) {
        int i = it - listBegin;
        if ((*it)->isChecked())
            hobbyMsg[i] = true;
        else
            hobbyMsg[i] = false;
    }
}
void AddNodeDialog::addFriendItem(MGraph *MG)
{
    if (MG->getVexnum() > 2) {
        this->mg = MG;
        for (int i = 2; i < mg->getVexnum(); i++) {
            VertexType *p1 = new Person;
            *p1 = mg->getPersonNode(i);
            friend1 = new QCheckBox(QString::number(p1->getId()) + "-" + p1->getName(), this);
            friendList->addButton(friend1, i + 1);
            if (i <= 4) {
                gridLayout->addWidget(friend1, 12, 2 * i, 1, 2);
            } else {
                gridLayout->addWidget(friend1, 13, 2 * (i - 5), 1, 2);
            }
        }
    }
}
void AddNodeDialog::setFriend()
{
    QList<QAbstractButton *> list = friendList->buttons();
    auto listBegin = list.begin();
    auto listEnd = list.end();
    for (auto it = list.begin(); it != listEnd; ++it) {
        int i = it - listBegin;
        if ((*it)->isChecked())
            friendMsg[i] = true;
        else
            friendMsg[i] = false;
    }
}
bool AddNodeDialog::isValid()
{
    bool e0 = (*message[0]).isEmpty();
    bool e1 = (*message[1]).isEmpty();
    bool e2 = (*message[2]).isEmpty();
    bool e3 = (*message[3]).isEmpty();
    bool e4 = (*message[4]).isEmpty();
    bool e5 = (*message[5]).isEmpty();
    if ((e0 || e1 || e2 || e3 || e4 || e5)) {
        return false;
    } else {
        return true;
    }
}
bool *AddNodeDialog::getHobby()
{
    return hobbyMsg;
}
bool *AddNodeDialog::getFriend()
{
    return friendMsg;
}
QString **AddNodeDialog::getMessage()
{
    return message;
}
AddNodeDialog::~AddNodeDialog()
{
    delete ui;
}
