#ifndef SQQUEUE_H
#define SQQUEUE_H
#include "define.h"
class SqQueue
{
private:
    int Qsize;
    VertexType *base;
    int front;
    int rear;

public:
    SqQueue();
    ~SqQueue();
    int EnQueue(VertexType e);  //入队
    int DeQueue(VertexType &e); //出队
    int QueueEmpty();
    int QueueFull();
};
#endif // SQQUEUE_H
