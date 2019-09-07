#ifndef MGRAPH_H
#define MGRAPH_H
#include "define.h"
#include <QComboBox>
#include <QString>
class MGraph
{
private:
    VertexType vexs[MAX_VERTEX_NUM]; //�����
    int vexnum;                      //ͼ�Ķ�������
    int Graphkind;
    int r[100];

public:
    MGraph();
    AdjMatrix arcs;                 //�ڽӾ���
    int LocateVertex(VertexType v); //��λ�ڵ��λ��
    QString CreateGraph();          //����ͼ������
    QString CreateDG();             //��������ͼ
    QString CreateUDG();            //��������ͼ
    QString DisplayALGraph();       //��ʾ�ڽ�����
    QString BFSTraverse(); //������ȱ���
    QString DFS_recursive();
    void DFS_RecursiveTraverse(VertexType v, QString &qstr); //������ȵݹ����
    QString DFS_Nonrecursive();
    void DFS_NonRecursiveTraverse(VertexType v, QString &qstr, QString &qstr2); //������ȷǵݹ����
    void setVexnum(QString qstr);    //����ͼ�Ľڵ���Ŀ
    void setGraphkind(QString qstr); //����ͼ������
    void generateMatrix();           //�������01����Ϊ����ֵ
    int **getMatrix();               //�õ���ǰ�ڽӾ���
    int getVexnum();                 //�õ���ǰͼ�Ľڵ���
    int getGraphkind();              //�õ�ͼ������
};
#endif // MGRAPH_H
