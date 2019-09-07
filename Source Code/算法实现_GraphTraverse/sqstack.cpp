#include "sqstack.h"
SqStack::SqStack()
{
    base = new VertexType[MAX_VERTEX_NUM];
    Ssize = MAX_VERTEX_NUM;
    top = base;
}
SqStack::~SqStack()
{
    delete base;
    Ssize = 0;
}
bool SqStack::StackEmpty()
{
    if (top == base)
        return true;
    else
        return false;
}
bool SqStack::StackFull()
{
    if (top - base >= Ssize)
        return true;
    else
        return false;
}
void SqStack::PopStack(VertexType &e)
{
    e = *--top;
}
void SqStack::PushStack(VertexType &e)
{
    *top++ = e;
}
int SqStack::GetTop(VertexType &e)
{
    if (top == base)
        return ERROR;
    else
        e = *(top - 1);
    return OK;
}
