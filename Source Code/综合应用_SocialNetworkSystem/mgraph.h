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
    int adjvex;       //弧指向顶点的位置
    ArcNode *nextarc; //指向下一个与该顶点邻接的顶点
    int info;         //弧的相关信息
} ArcNode;            //边表结点
typedef struct VNode
{
    VertexType data;              //用于存储顶点
    ArcNode *firstarc;            //指向第一个与该顶点邻接的顶点
} VNode, AdjList[MAX_VERTEX_NUM]; //表头节点，顺序表存储

class MGraph
{
private:
    AdjList vertices;                //邻接表
    VertexType vexs[MAX_VERTEX_NUM]; //顶点表,类型是Person
    AdjMatrix arcs;                  //邻接矩阵
    int vexnum;                      //图的顶点数；
    int correlation[MAX_VERTEX_NUM]; //某结点对其他节点的关联度
public:
    MGraph();
    int getVexnum();                 //得到当前图的节点数
    QString displayNodesName();      //显示当前图的节点信息
    QString displayAdjMatrix();      //显示当前图代表的邻接矩阵
    QString displayAdjList();        //显示当前图代表的邻接链表
    QString getSelectedItem(int id); //得到下拉菜单选择的节点编号及名称
    void addPersonNode(VertexType *v, bool *friends); //向当前图中添加节点
    void setCorrelation(int id);                      //设置结点编号为id的关联度
    int *getCorrelation();        //得到某结点关联度数组
    bool correlate(int i, int j); //判断两个人是否关联
    VertexType getPersonNode(int id);
};

#endif // MGRAPH_H
