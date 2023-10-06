#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACK_INCREASE_SIZE 10

typedef int SElementype;
typedef int Status;

#define OK 0
#define ERROR -1
#define OVERFLOW -2

typedef struct{
    SElementype *top;
    SElementype *base;
    int STACKSIZE;
}SqStack;
//栈里的top-1是栈顶元素
Status InitStack(SqStack &S){
    //构造一个空栈S
    S.base = (SElementype*)malloc(STACK_INIT_SIZE*sizeof(SElementype));
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.STACKSIZE = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack &S, SElementype &e){
    if(S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S,SElementype e){
    if(S.top - S.base >= S.STACKSIZE){
        S.base = (SElementype*)realloc(S.base, (S.STACKSIZE + STACK_INCREASE_SIZE) * sizeof(SElementype));
    }
    if(!S.base) exit(OVERFLOW);
    S.top = S.base + S.STACKSIZE;
    S.STACKSIZE += STACK_INCREASE_SIZE;
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElementype &e){
    if(S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

/*双栈处理：
    初始：t[0] = b[0] =base
          t[1] = b[1] = base + MaxSize - 1
    栈满条件：t[0] == t[1] 栈顶指针相遇
    栈空条件：t[0] = b[0] 或 t[1]=b[1] 
*/

