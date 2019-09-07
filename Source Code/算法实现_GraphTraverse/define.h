#ifndef DEFINE_H
#define DEFINE_H
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX_NUM 20
typedef int VertexType;
extern int vis[MAX_VERTEX_NUM];
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
enum {
    DG,  //有向图
    DN,  //有向网（带权）
    UDG, //无向图
    UDN, //无向网（带权）
};
#endif // DEFINE_H
