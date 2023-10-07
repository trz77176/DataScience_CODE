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

Status DestroyStack(SqStack &s){
    ClearStack(s);
    free(s.base);
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
    //realloc用法：先判断当前的指针是否有足够的连续空间，如果有，扩大mem_address指向的地址，并且将mem_address返回，如果空间不够，先按照newsize指定的大小分配空间，将原有数据从头到尾拷贝到新分配的内存区域，而后释放原来mem_address所指内存区域（注意：原来指针是自动释放，不需要使用free），同时返回新分配的内存区域的首地址。
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

Status StackEmpty(SqStack s){
    if(s.top == s.base){
        return OK;
    }
    return ERROR;
}

Status ClearStack(SqStack &S){
    S.top = S.base;
}
/*双栈处理：
    初始：t[0] = b[0] =base
          t[1] = b[1] = base + MaxSize - 1
    栈满条件：t[0] == t[1] 栈顶指针相遇
    栈空条件：t[0] = b[0] 或 t[1]=b[1] 
*/

//栈的应用
//1.数制转换  N = (N div d) * d + N mod d

void conversion(){
    SqStack s;
    InitStack(s);
    SElementype N,e;
    scanf("%d",&N);
    while(N){
        Push(s,N%8);
        N = N/8;
    }
    while(!StackEmpty(s)){
        Pop(s,e);
        printf("%d",e);
    }
}

//2.括号匹配的检验 & 行编辑程序
void lineedit(){
    SqStack s;
    InitStack(s);
    int ch = getchar();
    while(ch != EOF){
        switch(ch){
            case '#':Pop(s,ch); break;
            case '@':ClearStack(s); break;
            default: Push(s,ch); break;
        }
        ch = getchar();
    }
    //将栈内字符传送到数据区
    ClearStack(s);
    if(ch!=EOF){
        ch = getchar();
    }
    DestroyStack(s);
}

//3.迷宫问题求解

//4.表达式求值
//（1）中缀表达式求值
//（2）后缀表达式求值（逆波兰式）
//（3）前缀表达式求值（波兰式）

//栈与递归
int Fact(int n){
    if(!n){
        return 1;
    }
    else return (n * Fact(n-1));
}

//练习题：搜索无头结点的单链表最后一个结点
typedef int ElementType;
typedef struct Node{
	ElementType data;//数据域
	struct Node*next;//指针域
}LNode, *LinkList;

void Print(LinkList L){
    if(L->next == NULL){
        printf("%d", L->data);
    }
    else Print(L->next);
}