#include "addnodewindow.h"
#include "ui_addnodewindow.h"

AddNodeWindow::AddNodeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNodeWindow)
{
    ui->setupUi(this);
    nameLabel = new QLabel(tr("����"));
    regionLabel = new QLabel(tr("����"));
    primarySchoolLabel = new QLabel(tr("Сѧ"));
    middleSchoolLabel = new QLabel(tr("��ѧ"));
    highSchoolLabel = new QLabel(tr("��ѧ"));
    workOrginizationLabel = new QLabel(tr("������λ"));
    spaceLabel1 = new QLabel(tr(" "));
    TitleHobby = new QLabel(tr("��Ȥ���ã�"));

    //    usrLabel=new QLabel(tr("�û�����"));
    //    pwdLabel=new QLabel(tr("�� �룺"));

    nameLineEdit = new QLineEdit;
    regionLineEdit = new QLineEdit;
    primarySchoolLineEdit = new QLineEdit;
    middleSchoolLineEdit = new QLineEdit;
    highSchoolLineEdit = new QLineEdit;
    workOrginizationLineEdit = new QLineEdit;

    //        usrLineEdit=new QLineEdit;
    //        pwdLineEdit=new QLineEdit;

    //��������༭�����pwdLineEdit��������ʾ��ʽΪ�����Ǻš�*�������û�������ַ�
    //        pwdLineEdit->setEchoMode(QLineEdit::Password);

    //    //����һ�����񲼾ֹ��������󣬲������ڲ�����ӵ��ò��ֹ�������
    //    gridLayout=new QGridLayout;
    //    gridLayout->addWidget(usrLabel,0,0,1,1);
    //    gridLayout->addWidget(usrLineEdit,0,1,1,3);
    //    gridLayout->addWidget(pwdLabel,1,0,1,1);
    //    gridLayout->addWidget(pwdLineEdit,1,1,1,3);

    //����һ�����񲼾ֹ��������󣬲������ڲ�����ӵ��ò��ֹ�������
    gridLayout = new QGridLayout;
    gridLayout->addWidget(nameLabel, 0, 0, 1, 1);     //��һ�У���һ�� ռ1��1��
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

    //�����Ȥ���õ�ѡ��
    //    { Swimming, Basketball, Football, Taichi, Tennis, Reading, Gaming, Travelling }
    SwimmingButton = new QRadioButton("Swimming", this);
    BasketballButton = new QRadioButton("Basketball", this);
    FootballButton = new QRadioButton("Football", this);
    TaichiButton = new QRadioButton("Taichi", this);

    TennisButton = new QRadioButton("Tennis", this);
    ReadingButton = new QRadioButton("Reading", this);
    GamingButton = new QRadioButton("Gaming", this);
    TravellingButton = new QRadioButton("Travelling", this);

    HobbyGroup = new QButtonGroup(this);
    HobbyGroup->addButton(SwimmingButton, 1);
    HobbyGroup->addButton(BasketballButton, 2);
    HobbyGroup->addButton(FootballButton, 3);
    HobbyGroup->addButton(TaichiButton, 4);
    HobbyGroup->addButton(TennisButton, 5);
    HobbyGroup->addButton(ReadingButton, 6);
    HobbyGroup->addButton(GamingButton, 7);
    HobbyGroup->addButton(TravellingButton, 8);
    HobbyGroup->setExclusive(false);

    btnLayout = new QHBoxLayout;

    gridLayout->addWidget(SwimmingButton, 8, 0, 1, 4);
    gridLayout->addWidget(BasketballButton, 8, 4, 1, 4);
    gridLayout->addWidget(FootballButton, 8, 8, 1, 4);
    gridLayout->addWidget(TaichiButton, 8, 12, 1, 4);

    gridLayout->addWidget(TennisButton, 9, 0, 1, 4);
    gridLayout->addWidget(ReadingButton, 9, 4, 1, 4);
    gridLayout->addWidget(GamingButton, 9, 8, 1, 4);
    gridLayout->addWidget(TravellingButton, 9, 12, 1, 4);

    gridLayout->addWidget(TitleHobby, 7, 0, 1, 4);

    //�����б�
    FriendListGroup = new QButtonGroup(this);

    Friend1 = new QRadioButton("Node1", this);
    Friend2 = new QRadioButton("Node2", this);
    Friend3 = new QRadioButton("Node3", this);
    Friend4 = new QRadioButton("Node4", this);
    Friend5 = new QRadioButton("Node5", this);
    Friend6 = new QRadioButton("Node6", this);
    Friend7 = new QRadioButton("Node7", this);
    Friend8 = new QRadioButton("Node8", this);
    Friend9 = new QRadioButton("Node9", this);
    Friend10 = new QRadioButton("Node10", this);

    FriendListGroup->addButton(Friend1, 1);
    FriendListGroup->addButton(Friend2, 2);
    FriendListGroup->addButton(Friend3, 3);
    FriendListGroup->addButton(Friend4, 4);
    FriendListGroup->addButton(Friend5, 5);
    FriendListGroup->addButton(Friend6, 6);
    FriendListGroup->addButton(Friend7, 7);
    FriendListGroup->addButton(Friend8, 8);
    FriendListGroup->addButton(Friend9, 9);
    FriendListGroup->addButton(Friend10, 10);
    FriendListGroup->setExclusive(false);

    spaceLabel2 = new QLabel(tr(" "));
    TitleFriendList = new QLabel(tr("���������ĺ��ѹ�ϵ��"));
    gridLayout->addWidget(spaceLabel2, 10, 0, 1, 16);
    gridLayout->addWidget(TitleFriendList, 11, 0, 1, 16);

    gridLayout->addWidget(Friend1, 12, 0, 1, 2);
    gridLayout->addWidget(Friend2, 12, 2, 1, 2);
    gridLayout->addWidget(Friend3, 12, 4, 1, 2);
    gridLayout->addWidget(Friend4, 12, 6, 1, 2);
    gridLayout->addWidget(Friend5, 12, 8, 1, 2);

    gridLayout->addWidget(Friend6, 13, 0, 1, 2);
    gridLayout->addWidget(Friend7, 13, 2, 1, 2);
    gridLayout->addWidget(Friend8, 13, 4, 1, 2);
    gridLayout->addWidget(Friend9, 13, 6, 1, 2);
    gridLayout->addWidget(Friend10, 13, 8, 1, 2);

    //    // �����źŲ�
    //    connect(HobbyGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onButtonHobbyClicked(QAbstractButton*)));
    //    connect(FriendListGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onButtonFriendClicked()));

    //����������ť�����һ��ˮƽ���ֹ��������󣬲�����ť������ӵ��ò��ֹ�������
    okBtn = new QPushButton(tr("ȷ��"));
    cancelBtn = new QPushButton(tr("ȡ��"));
    btnLayout = new QHBoxLayout;
    btnLayout->setSpacing(60);
    btnLayout->addWidget(okBtn);
    btnLayout->addWidget(cancelBtn);

    //����һ����ֱ���ֹ��������󣬲���ˮƽ�����񲼾ֹ�������ӵ��ù�������
    dlgLayout = new QVBoxLayout;
    dlgLayout->setMargin(50);
    dlgLayout->addLayout(gridLayout);
    dlgLayout->addStretch(50);
    dlgLayout->addLayout(btnLayout);
    setLayout(dlgLayout);

    //��������ť���ź���۹�������

    //���öԻ���ı���ʹ�С
    setWindowTitle(tr("��ӽ��"));
    resize(600, 400);
}

AddNodeWindow::~AddNodeWindow()
{
    delete ui;
}
