#include "mgraph.h"

MGraph::MGraph()
{
    //�ڽӾ����ʼ��
    for (int i = 0; i < MAX_VERTEX_NUM; ++i)
        for (int j = 0; j < MAX_VERTEX_NUM; ++j)
            arcs[i][j] = 0;
    VertexType *p0 = new Person();
    p0->setId(0);
    p0->setName(QString::fromLocal8Bit("�Ե���"));
    p0->setRegion(QString::fromLocal8Bit("����"));
    p0->setPrimarySchool(QString::fromLocal8Bit("����Сѧ"));
    p0->setMiddleSchool(QString::fromLocal8Bit("��̲��ѧ"));
    p0->setHighSchool(QString::fromLocal8Bit("ͬ�ô�ѧ"));
    p0->setWorkPlace(QString::fromLocal8Bit("�Ϻ�"));
    bool hobbies0[10] = {false, true, false, true, true, true, true, true, false, false};
    p0->setHobbies(hobbies0);
    vexs[0] = *p0;

    VertexType *p1 = new Person();
    p1->setId(1);
    p1->setName(QString::fromLocal8Bit("������"));
    p1->setRegion(QString::fromLocal8Bit("����"));
    p1->setPrimarySchool(QString::fromLocal8Bit("����Сѧ"));
    p1->setMiddleSchool(QString::fromLocal8Bit("��̲��ѧ"));
    p1->setHighSchool(QString::fromLocal8Bit("ɽ����ѧ"));
    p1->setWorkPlace(QString::fromLocal8Bit("����"));
    bool hobbies1[10] = {true, false, true, true, false, true, false, true, false, true};
    p1->setHobbies(hobbies1);
    vexs[1] = *p1;

    //��ʼ���ڽӾ���
    arcs[0][1] = 1;
    arcs[1][0] = 1; //0��1��ʶ

    //�����ʼ���ڽ�����
    ArcNode *v0, *v1;
    vertices[0].data = *p0;
    vertices[1].data = *p1;

    v0 = new ArcNode;
    v0->adjvex = p1->getId();
    v0->nextarc = nullptr;
    vertices[0].firstarc = v0;

    v1 = new ArcNode;
    v1->adjvex = p0->getId();
    v1->nextarc = nullptr;
    vertices[1].firstarc = v1;

    vexnum = 2; //��ʼ���ڵ���ĿΪ2
}
int MGraph::getVexnum()
{
    return vexnum;
}
void MGraph::addPersonNode(VertexType *v, bool *friends)
{
    VertexType *p = new Person();
    p = v;
    p->setId(vexnum);
    vexs[vexnum] = *p;

    vertices[vexnum].data = *p;
    vertices[vexnum].firstarc = nullptr;
    int flag = 1;
    ArcNode *u0, *u1 = nullptr;

    for (int i = 0; i < vexnum; i++) {
        if (friends[i]) { //���vexnum����i�����ʶ
            arcs[i][vexnum] = 1;
            arcs[vexnum][i] = 1;
            //�ڵ�i�ڵ㴦���ӽ��vexnum
            u0 = new ArcNode;
            u0->adjvex = vexnum;
            u0->nextarc = nullptr;

            ArcNode *u2 = vertices[i].firstarc;
            if (vertices[i].firstarc == nullptr) {
                //����i���û���ӽڵ㣬��ֱ�ӽ���͵�vexnum�ڵ�����
                vertices[i].firstarc = u0;
            } else {
                while (u2->nextarc) {
                    u2 = u2->nextarc;
                }
                u2->nextarc = u0; //��vexnum������ӵ�vertice[i]��������
            }
            //�ڵ�vexnum��㴦��ӽ��i
            u2 = new ArcNode;
            u2->adjvex = i;
            u2->nextarc = nullptr;
            if (flag) { //ÿ�θղ����½ڵ�vexnum��ʱ��flag=1����ʾvertice[vexnum].firarc==null
                //����һ��֮���ֱ�����ϴ��Ѿ�����ڵ�ĺ�������½ڵ�(0~vexnum-1)
                flag = 0;
                vertices[vexnum].firstarc = u2;
            } else {
                u1->nextarc = u2;
            }
            u1 = u2;
        }
    }
    vexnum += 1; //�����+1
}
QString MGraph::displayNodesName()
{
    QString qstr;
    for (int i = 0; i < vexnum; i++) {
        qstr += QString::number(vertices[i].data.getId()) + ": " + vertices[i].data.getName()
                + "\n";
    }
    return qstr;
}
QString MGraph::displayAdjMatrix()
{
    QString qstr;
    for (int i = 0; i < vexnum; ++i) {
        for (int j = 0; j < vexnum; ++j)
            qstr += QString::number(arcs[i][j]) + " ";
        qstr += "\n";
    }
    return qstr;
}
QString MGraph::displayAdjList()
{
    QString qstr;
    ArcNode *p;
    for (int i = 0; i < vexnum; ++i) {
        qstr += vertices[i].data.getName() + "-->";
        p = vertices[i].firstarc;
        while (p) {
            qstr += QString::number(p->adjvex) + "-" + getPersonNode(p->adjvex).getName() + " ";
            p = p->nextarc;
        }
        qstr += "\n";
    }
    return qstr;
}
int *MGraph::getCorrelation()
{
    return correlation;
}
void MGraph::setCorrelation(int id)
{
    for (int i = 0; i < vexnum; i++)
        correlation[i] = -1;
    for (int i = 0; i < vexnum; i++) {
        if (arcs[i][id] == 1 || i == id) { //i��id�໥��ʶ��������
            correlation[i] = -1;
            continue; //ֱ��i��id����ʶ
        }
        correlation[i] = 0;
        for (int j = 0; j < vexnum; j++) {
            if (arcs[i][j] == 1 && arcs[j][id] == 1) { //j��i��ʶ��j��id��ʶ
                correlation[i] += 1;                   //id��i�Ĺ����ȼ�1
            }
        }
    }
}
bool MGraph::correlate(int i, int j)
{
    if (arcs[i][j] || arcs[j][i]) {
        return true;
    } else {
        return false;
    }
}
QString MGraph::getSelectedItem(int id)
{
    return QString::number(vexs[id].getId()) + "-" + vexs[id].getName();
}
VertexType MGraph::getPersonNode(int id)
{
    return vexs[id];
}
