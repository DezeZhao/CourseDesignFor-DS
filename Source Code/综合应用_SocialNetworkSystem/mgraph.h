#ifndef MGRAPH_H
#define MGRAPH_H
#define MAX_VERTEX_NUM 10
#include "person.h"
#include <QString>
typedef Person VertexType;
extern int vis[MAX_VERTEX_NUM];
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct ArcNode
{
    int adjvex;       //��ָ�򶥵��λ��
    ArcNode *nextarc; //ָ����һ����ö����ڽӵĶ���
    int info;         //���������Ϣ
} ArcNode;            //�߱���
typedef struct VNode
{
    VertexType data;              //���ڴ洢����
    ArcNode *firstarc;            //ָ���һ����ö����ڽӵĶ���
} VNode, AdjList[MAX_VERTEX_NUM]; //��ͷ�ڵ㣬˳���洢

class MGraph
{
private:
    AdjList vertices;                //�ڽӱ�
    VertexType vexs[MAX_VERTEX_NUM]; //�����,������Person
    AdjMatrix arcs;                  //�ڽӾ���
    int vexnum;                      //ͼ�Ķ�������
    int correlation[MAX_VERTEX_NUM]; //ĳ���������ڵ�Ĺ�����
public:
    MGraph();
    int getVexnum();                 //�õ���ǰͼ�Ľڵ���
    QString displayNodesName();      //��ʾ��ǰͼ�Ľڵ���Ϣ
    QString displayAdjMatrix();      //��ʾ��ǰͼ������ڽӾ���
    QString displayAdjList();        //��ʾ��ǰͼ������ڽ�����
    QString getSelectedItem(int id); //�õ������˵�ѡ��Ľڵ��ż�����
    void addPersonNode(VertexType *v, bool *friends); //��ǰͼ����ӽڵ�
    void setCorrelation(int id);                      //���ý����Ϊid�Ĺ�����
    int *getCorrelation();        //�õ�ĳ������������
    bool correlate(int i, int j); //�ж��������Ƿ����
    VertexType getPersonNode(int id);
};

#endif // MGRAPH_H
