#include<stdio.h>
#include<stdlib.h>

#define OK 1;
#define ERROR -1;

typedef int ElemType;
typedef int Status;

typedef struct Node{
    ElemType data;
    struct Node*next;
}SLNode, *LinkStack;

Status PushLStack(LinkStack &LS, ElemType e){
    LinkStack p = (LinkStack)malloc(sizeof(SLNode));
    p->data = e;
    p->next = LS;
    LS = p;
    return OK;  //把链栈的栈顶当作了链表头
}
    
Status PopLStack(LinkStack &LS, ElemType &e){
    if(!LS) return ERROR;
    LinkStack p = LS;
    LS = LS->next;
    e = p->data;
    free(p);
    return OK;
}

