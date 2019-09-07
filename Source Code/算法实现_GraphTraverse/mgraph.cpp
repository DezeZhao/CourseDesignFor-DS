#include "mgraph.h"
#include "mainwindow.h"
#include "sqqueue.h"
#include "sqstack.h"
#include <ctime>
#include <iostream>
using namespace std;
int vis[MAX_VERTEX_NUM];
MGraph::MGraph()
{
    for (int i = 0; i < vexnum; i++)
        for (int j = 0; j < vexnum; j++)
            arcs[i][j] = 0;
    //    for (int i = 0; i < vexnum; i++) {
    //        vexs[i] = i + 1;
    //    }
    vexs[0] = 1;
    vexs[1] = 2;
    vexs[2] = 3;
    vexs[3] = 4;
    vexs[4] = 5;
    vexs[5] = 6;
    vexs[6] = 7;
    vexs[7] = 8;
    vexs[8] = 9;
    vexs[9] = 10;
}
/**************************************************************
函数功能：定位顶点
函数说明：通过遍历查找与目标顶点相同的顶点的编号返回即可。
***************************************************************/
int MGraph::LocateVertex(VertexType v)
{
    for (int i = 0; i < vexnum; i++)
        if (vexs[i] == v)
            return i;
    return -1;
}

/*创建有向图*/
QString MGraph::CreateDG()
{
    int k = 0;
    for (int i = 0; i < vexnum; i++)
        for (int j = 0; j < vexnum; j++)
            if (i == j)
                arcs[i][j] = 1;
            else if (i < j)
                arcs[i][j] = r[k++];

    QString qstr;
    for (int i = 0; i < vexnum; i++) {
        for (int j = 0; j < vexnum; j++)
            qstr += QString::number(arcs[i][j]) + " ";
        qstr += "\n";
    }
    return qstr;
}
/*创建无向图*/
QString MGraph::CreateUDG()
{
    int k = 0;
    for (int i = 0; i < vexnum; i++)
        for (int j = 0; j < vexnum; j++)
            if (i == j)
                arcs[i][j] = 1;
            else if (i < j)
                arcs[i][j] = r[k++];
            else if (i > j)
                arcs[i][j] = arcs[j][i];
    QString qstr;
    for (int i = 0; i < vexnum; i++) {
        for (int j = 0; j < vexnum; j++)
            qstr += QString::number(arcs[i][j]) + " ";
        qstr += "\n";
    }
    return qstr;
}
/*根据图的种类创建图*/
QString MGraph::CreateGraph()
{
    memset(arcs, 0, sizeof(arcs));
    switch (Graphkind) {
    case 1: //DG
        return CreateDG();
    case 3: //UDG
        return CreateUDG();
    default:
        return "";
    }
}
/*打印图的邻接链表*/
QString MGraph::DisplayALGraph()
{
    QString qstr;
    for (int i = 0; i < vexnum; i++) {
        qstr += QString::number(vexs[i]) + "-->";
        for (int j = 0; j < vexnum; j++)
            if (Graphkind == 1) {
                if (i < j && arcs[i][j] != 0)
                    qstr += QString::number(j + 1) + " ";
            } else if (Graphkind == 3) {
                if (i != j && arcs[i][j] != 0) {
                    qstr += QString::number(j + 1) + " ";
                }
            }
        qstr += "\n";
    }
    return qstr;
}
/**************************************************************
函数功能：BFS非递归遍历图（邻接矩阵/邻接表）
函数说明：建立一个标记数组vis[],若该顶点访问过就标记为1，否则置零；
遍历的时候，首先找到一个未访问的顶点，入队，然后如果队列不空，就
一直循环，并且每次循环都要出队一个元素，再在以该元素为顶点的链表
或者矩阵的某一行中进行查找，如果某个顶点未访问，则进行访问，然后
vis置1，表示已经访问，再入队，直到队为空，退出本次循环，再查找顶
点表中的第二个顶点或者矩阵中的第二行，以此类推得到广度优先搜索序
列，每次大的循环其实就是一个连通子集。
***************************************************************/
QString MGraph::BFSTraverse()
{
    QString qstr, qstr2;
    SqQueue Q;
    VertexType u;
    for (int v = 0; v < vexnum; v++)
        vis[v] = 0;
    for (int v = 0; v < vexnum; v++) {
        if (!vis[v]) {
            //cout << "{";
            Q.EnQueue(vexs[v]);
            qstr2 += QString::number(vexs[v]) + " ";
            qstr += QString::number(vexs[v]) + QString::fromLocal8Bit(" 入队\n");
            vis[v] = 1;
            while (!Q.QueueEmpty()) {
                Q.DeQueue(u);
                qstr += QString::number(u) + QString::fromLocal8Bit(" 出队\n");
                int u1 = LocateVertex(u);
                for (int w = 0; w < vexnum; w++) {
                    if (!vis[w] && arcs[u1][w]) {
                        vis[w] = 1;
                        Q.EnQueue(vexs[w]);
                        qstr += QString::number(vexs[w]) + QString::fromLocal8Bit(" 入队\n");
                        qstr2 += QString::number(vexs[w]) + " ";
                    }
                }
            }
            //cout << "}";
        }
    }
    qstr2 += "\n" + qstr;
    return qstr2;
}
QString MGraph::DFS_recursive()
{
    QString qstr;
    for (int i = 0; i < vexnum; i++)
        vis[i] = 0;
    for (int v = 0; v < vexnum; v++)
        if (!vis[v]) {
            DFS_RecursiveTraverse(v, qstr);
        }
    return qstr;
}
void MGraph::DFS_RecursiveTraverse(VertexType v, QString &qstr)
{
    qstr += QString::number(vexs[v]) + " ";
    vis[v] = 1;
    for (int w = 0; w < vexnum; w++)
        if (!vis[w] && arcs[v][w])
            DFS_RecursiveTraverse(w, qstr);
}
QString MGraph::DFS_Nonrecursive()
{
    QString qstr, qstr2;
    for (int i = 0; i < vexnum; i++)
        vis[i] = 0;
    for (int v = 0; v < vexnum; v++)
        if (!vis[v])
            DFS_NonRecursiveTraverse(v, qstr, qstr2);
    return qstr2 + "\n" + qstr;
}
void MGraph::DFS_NonRecursiveTraverse(VertexType v, QString &qstr, QString &qstr2)
{
    SqStack S;
    vis[v] = 1;
    S.PushStack(vexs[v]);
    qstr += QString::number(vexs[v]) + QString::fromLocal8Bit(" 入栈\n");
    while (!S.StackEmpty()) {
        int e, u = 0;
        if (S.GetTop(e))
            u = LocateVertex(e);
        S.PopStack(e);
        qstr2 += QString::number(e) + " ";
        qstr += QString::number(e) + QString::fromLocal8Bit(" 出栈\n");
        for (int w = 0; w < vexnum; w++) {
            if (!vis[w] && arcs[u][w]) {
                vis[w] = 1;
                S.PushStack(vexs[w]);
                qstr += QString::number(vexs[w]) + QString::fromLocal8Bit(" 入栈\n");
            }
        }
    }
}
void MGraph::setVexnum(QString qstr)
{
    if (qstr == "2*2")
        vexnum = 2;
    else if (qstr == "3*3")
        vexnum = 3;
    else if (qstr == "4*4")
        vexnum = 4;
    else if (qstr == "5*5")
        vexnum = 5;
    else if (qstr == "6*6")
        vexnum = 6;
    else if (qstr == "7*7")
        vexnum = 7;
    else if (qstr == "8*8")
        vexnum = 8;
    else if (qstr == "9*9")
        vexnum = 9;
    else if (qstr == "10*10")
        vexnum = 10;
}
void MGraph::setGraphkind(QString qstr)
{
    if (qstr == QString::fromLocal8Bit("无向图"))
        Graphkind = 3;
    else if (qstr == QString::fromLocal8Bit("有向图"))
        Graphkind = 1;
}
void MGraph::generateMatrix()
{
    srand((int) time(nullptr)); // 产生随机种子  把0换成NULL也行
    for (int i = 0; i < (vexnum * vexnum - vexnum) / 2; i++) {
        r[i] = rand() % 2;
    }
}
int MGraph::getVexnum()
{
    return vexnum;
}
int MGraph::getGraphkind()
{
    return Graphkind;
}
int **MGraph::getMatrix()
{
    int **m;
    m = new int *[vexnum];
    for (int i = 0; i < vexnum; i++) {
        m[i] = new int[vexnum];
        for (int j = 0; j < vexnum; j++)
            m[i][j] = arcs[i][j];
    }
    return m;
}
