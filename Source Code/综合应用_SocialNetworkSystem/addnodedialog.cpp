#include "addnodedialog.h"
#include "ui_addnodedialog.h"
#include <QDebug>

AddNodeDialog::AddNodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNodeDialog)
{
    ui->setupUi(this);
    //   resize(600, 400);
    setWindowTitle(QString::fromLocal8Bit("��ӽڵ�ҳ��"));

    //////////////////////////////////////��ϸ��Ϣ////////////////////////////////////////
    nameLabel = new QLabel(QString::fromLocal8Bit("����"));
    regionLabel = new QLabel(QString::fromLocal8Bit("����"));
    primarySchoolLabel = new QLabel(QString::fromLocal8Bit("Сѧ"));
    middleSchoolLabel = new QLabel(QString::fromLocal8Bit("��ѧ"));
    highSchoolLabel = new QLabel(QString::fromLocal8Bit("��ѧ"));
    workOrginizationLabel = new QLabel(QString::fromLocal8Bit("������λ"));
    spaceLabel1 = new QLabel(tr(" "));

    nameLineEdit = new QLineEdit;
    regionLineEdit = new QLineEdit;
    primarySchoolLineEdit = new QLineEdit;
    middleSchoolLineEdit = new QLineEdit;
    highSchoolLineEdit = new QLineEdit;
    workOrginizationLineEdit = new QLineEdit;

    //����һ�����񲼾ֹ��������󣬽�lineedit ��label��ӵ�����
    //QWidget * widget, int fromRow, int fromColumn, int rowSpan, int columnSpan, Qt::Alignment
    gridLayout = new QGridLayout;
    gridLayout->addWidget(nameLabel, 0, 0, 1, 2);     //��һ�У���һ�� ռ1��1��
    gridLayout->addWidget(nameLineEdit, 0, 1, 1, 12); //��һ�У��ڶ���

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

    ///////////////��Ȥ����///////////////////////////////////////////////////////////
    titleHobby = new QLabel(QString::fromLocal8Bit("��Ȥ����:"));
    basketballButton = new QCheckBox(QString::fromLocal8Bit("������"), this);
    footballButton = new QCheckBox(QString::fromLocal8Bit("������"), this);
    pingpangButton = new QCheckBox(QString::fromLocal8Bit("��ƹ����"), this);
    badmintonButton = new QCheckBox(QString::fromLocal8Bit("����ë��"), this);
    swimmingButton = new QCheckBox(QString::fromLocal8Bit("��Ӿ"), this);
    travellingButton = new QCheckBox(QString::fromLocal8Bit("����"), this);
    photographyButton = new QCheckBox(QString::fromLocal8Bit("��Ӱ"), this);
    readingButton = new QCheckBox(QString::fromLocal8Bit("�Ķ�"), this);
    programButton = new QCheckBox(QString::fromLocal8Bit("���"), this);
    moviesButton = new QCheckBox(QString::fromLocal8Bit("����Ӱ"), this);

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

    /////////////////////////////////////���ѹ�ϵ/////////////////////////////////////
    spaceLabel2 = new QLabel(tr(" "));
    titleFriendList = new QLabel(QString::fromLocal8Bit("�������ڵ�ĺ��ѹ�ϵ:"));
    gridLayout->addWidget(spaceLabel2, 10, 0, 1, 16);
    gridLayout->addWidget(titleFriendList, 11, 0, 1, 16);
    friendList = new QButtonGroup(this);
    //��ʼ�������ڵ�
    friend1 = new QCheckBox(QString::fromLocal8Bit("0-�Ե���"), this);
    friend2 = new QCheckBox(QString::fromLocal8Bit("1-������"), this);
    friendList->addButton(friend1, 1);
    friendList->addButton(friend2, 2);
    gridLayout->addWidget(friend1, 12, 0, 1, 2);
    gridLayout->addWidget(friend2, 12, 2, 1, 2);
    friendList->setExclusive(false);
    /////////////////////////////////////////////////////////////////////////////////
    //����������ť�����һ��ˮƽ���ֹ��������󣬲�����ť��ӵ��ò��ֹ�������
    okBtn = new QPushButton(QString::fromLocal8Bit("ȷ��"));
    cancelBtn = new QPushButton(QString::fromLocal8Bit("ȡ��"));
    buttonLayout = new QHBoxLayout;
    buttonLayout->setSpacing(60);
    buttonLayout->addWidget(okBtn);
    buttonLayout->addWidget(cancelBtn);

    //����һ����ֱ���ֹ��������󣬲���ˮƽ�����񲼾ֹ�������ӵ��ù�������
    dialogLayout = new QVBoxLayout;
    dialogLayout->setMargin(50);
    dialogLayout->addLayout(gridLayout);
    dialogLayout->addStretch(50);
    dialogLayout->addLayout(buttonLayout);
    setLayout(dialogLayout);

    //�����ź����
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
                             QString::fromLocal8Bit("�뽫��ϸ��Ϣ����д������"));
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
