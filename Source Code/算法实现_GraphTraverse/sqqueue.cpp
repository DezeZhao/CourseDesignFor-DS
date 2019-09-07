#include "sqqueue.h"
SqQueue::SqQueue()
{
    base = new VertexType[MAX_VERTEX_NUM];
    Qsize = MAX_VERTEX_NUM;
    front = rear = 0;
}
SqQueue::~SqQueue()
{
    delete base;
}
int SqQueue::EnQueue(VertexType e)
{
    if (QueueFull()) {
        return ERROR;
    }
    base[rear] = e;
    rear = (rear + 1) % (Qsize + 1);
    return OK;
}
int SqQueue::DeQueue(VertexType &e)
{
    if (QueueEmpty()) {
        return ERROR;
    }
    e = base[front];
    front = (front + 1) % (Qsize + 1);
    return OK;
}
int SqQueue::QueueEmpty()
{
    if (front == rear)
        return TRUE;
    return FALSE;
}
int SqQueue::QueueFull()
{
    if ((rear + 1) % (Qsize + 1) == front)
        return TRUE;
    return FALSE;
}
