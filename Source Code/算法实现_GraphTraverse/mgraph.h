#ifndef MGRAPH_H
#define MGRAPH_H
#include "define.h"
#include <QComboBox>
#include <QString>
class MGraph
{
private:
    VertexType vexs[MAX_VERTEX_NUM]; //顶点表
    int vexnum;                      //图的顶点数；
    int Graphkind;
    int r[100];

public:
    MGraph();
    AdjMatrix arcs;                 //邻接矩阵
    int LocateVertex(VertexType v); //定位节点的位置
    QString CreateGraph();          //创建图的种类
    QString CreateDG();             //创建有向图
    QString CreateUDG();            //创建无向图
    QString DisplayALGraph();       //显示邻接链表
    QString BFSTraverse(); //广度优先遍历
    QString DFS_recursive();
    void DFS_RecursiveTraverse(VertexType v, QString &qstr); //深度优先递归遍历
    QString DFS_Nonrecursive();
    void DFS_NonRecursiveTraverse(VertexType v, QString &qstr, QString &qstr2); //深度优先非递归遍历
    void setVexnum(QString qstr);    //设置图的节点数目
    void setGraphkind(QString qstr); //设置图的种类
    void generateMatrix();           //生成随机01序列为矩阵赋值
    int **getMatrix();               //得到当前邻接矩阵
    int getVexnum();                 //得到当前图的节点数
    int getGraphkind();              //得到图的种类
};
#endif // MGRAPH_H
