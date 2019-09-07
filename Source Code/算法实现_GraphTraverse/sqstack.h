#ifndef SQSTACK_H
#define SQSTACK_H
#include "define.h"
class SqStack
{
private:
    int *top;
    int *base;
    int Ssize;

public:
    SqStack();
    ~SqStack();
    bool StackEmpty();
    bool StackFull();
    void PopStack(VertexType &e);  //��ջ
    void PushStack(VertexType &e); //��ջ
    int GetTop(VertexType &e);
};
#endif // SQSTACK_H
