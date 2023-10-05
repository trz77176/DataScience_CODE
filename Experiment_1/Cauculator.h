


#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>

#define INITSIZE 100
#define LISTINCREASE 10

#define Status int
#define OK 0
#define OVERFLOW -2
#define ERROR -1

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char SElemType;

typedef struct {
SElemType *base;
SElemType *top;
int stacksize; 
} SqStack;

typedef struct{
    float factor;
    int index;
}Elementtype;

int HeadListLength = 0;

typedef struct Node{
    Elementtype data;
    int Length;
    struct Node* next;
}LNode, *LinkList;

typedef struct{
    LinkList *elem;
    int length;
    int listsize;
}HeadList;

Status InitStack (SqStack &S) {
S.base=(SElemType *)malloc(STACK_INIT_SIZE *sizeof(SElemType));
if(!S.base) exit(OVERFLOW);
S.top=S.base;
S.stacksize=STACK_INIT_SIZE ;
return OK; 
} 

Status GetTop (SqStack S, SElemType &e){
// 若栈不空，则用e返回S的栈顶元素，并返回OK�? 否则返回ERROR
if(S.top == S.base) return ERROR;
e=*(S.top-1);
return OK;
}

Status Push (SqStack &S, SElemType e){
 // 插入元素e为新的栈顶元�?
 if(S.top-S.base>=S.stacksize) {
 S.base=(SElemType *)realloc(S.base , 
 (S.stacksize+STACKINCREMENT)*sizeof(SElemType));
 if (! S.base) exit(OVERFLOW);
 S.top=S.base+ S.stacksize;
 S.stacksize += STACKINCREMENT;
 } 
 *S.top++=e; 
 return OK;
}

 Status Pop (SqStack &S, SElemType &e){
 // 若栈不空，则删除S的栈顶元素，用e返回其值， 并返回OK；否则返回ERROR
 if(S.top == S.base) return ERROR;
 e =*--S.top;
 return OK;
 }

/*Status EvaluateExpression(SqStack OPTR,SqStack OPND){
    //OPTR和OPND分别为运算符栈和操作数栈，OP为运算符集合
    InitStack(OPTR); 
    Push(OPTR,'#');
    InitStack(OPND); 
    char c=getchar();
    SElemType e;
    while(c!='#'||GetTop(OPTR, e)!='#'){
        if(!In(c,OP)){
            Push(OPND,c); 
            c=getchar();
            }//不是运算符则进栈
        else
            switch(Precede(GetTop(OPTR),c){
                case '<': //栈顶元素优先权低
                    Push(OPTR,c);
                    c=getchar();
                    break;
                case '=': //脱括号并接收下一字符
                    Pop(OPTR,x); c=getchar();
                    break; 
                case '>': //退栈并将运算结果入�?
                    Pop(OPTR,theta); 
                    Pop(OPND,b); 
                    Pop((PND, a); 
                    Push(OPND,Operate(a,theta,b));
                    break; 
                }//switch
            }//while
    return GetTop(OPND);
}

*/
Status InitList_HL(HeadList &L){
    L.elem = (LinkList*)malloc(INITSIZE * sizeof(LinkList));
    if(!L.elem){
        printf("内存申请失败�?");
        return ERROR;
    }
    L.length = 0;
    L.listsize = INITSIZE;
    return OK;
}

Status InitList(LinkList &L){
    L =  (LinkList)malloc(sizeof(LNode));
     if(!L){
        printf("内存申请失败�?");
        return ERROR;
    }
    else{
        L->next = NULL;
        return OK;
    }
}

LinkList GetElemFromPol(LinkList L, int e){
    LinkList p = L->next;
    while(p){
        if(e == p->data.index){
            return p;
        }
        else{
            p = p->next;
        }
    }
    return 0;
}
Status CreateList(HeadList &HL,LinkList &L){
    HeadListLength++;
    HL.elem[HeadListLength] = L;
    int a,b,count=0;
    scanf("%d%d",&a,&b);
    LinkList q = L->next, m,n;
    while(a||b){
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if(!a) continue;
        p->data.factor = a,p->data.index = b;
        if((GetElemFromPol(L, b)) && count){
            free(p);
            scanf("%d%d",&a, &b);
            continue;
        }
        count++;
        if(count == 1){
            L->next = p;
            p->next =NULL;
            scanf("%d%d",&a,&b);
            continue;
        }
        else{
            n = L;
            m = L->next;
            while(m){
                if(m->data.index > p->data.index){
                    n=m;
                    m= m->next;
                    continue;
                }
                break;
            }
            n->next = p, p->next = m;
            scanf("%d%d",&a,&b);
        }
    }
    L->Length = count;
    return OK;
}

void PrintList(LinkList L){
    printf("项数�?%d\n", L->Length);
    LinkList p = L->next;
    printf("%.2f*x^(%d)",p->data.factor,p->data.index);
    p = p->next;
    while(p){
        printf("+%.2f*x^(%d)",p->data.factor,p->data.index);
        p = p->next;
    }
    printf("\n打印完成!\n");
}

Status AddPolynomial(HeadList HL){
    int i,j;
    printf("请选择要操作的多项式：");
    scanf("%d%d",&i,&j);
    LinkList p = HL.elem[i]->next, q = HL.elem[j]->next;
    LinkList Ladd = (LinkList)malloc(sizeof(LNode));
    LinkList Ladd1 = Ladd;
    int count=0;
    while(p&&q){
        if(p->data.index > q->data.index){
            Ladd->next = p, Ladd = p, p = p->next;
        }
        else if(p->data.index < q->data.index){
            Ladd->next = q, Ladd = q, q = q->next;
        }
        else{
             Ladd->next = p, Ladd = p, p = p->next;
             Ladd->data.factor += q->data.factor;
             q = q->next;
             count++;
        }
    }
    Ladd1->Length = HL.elem[i]->Length +HL.elem[j]->Length - count;
    Ladd->next = p? p: q;
    PrintList(Ladd1);
    return OK;
}

Status MinusPolynomial(HeadList HL){
    int i, j, count = 0;
    printf("请选择要操作的多项式：");
    scanf("%d%d",&i,&j);
    LinkList p = HL.elem[i]->next, q = HL.elem[j]->next;
    LinkList Lminus = (LinkList)malloc(sizeof(LNode));
    if(!Lminus){
        return ERROR;
    }
    LinkList Lminus1 = Lminus;
    while(p&&q){
        if(p->data.index > q->data.index){
            Lminus->next = p, Lminus = p, p = p->next;
        }
        else if(p->data.index < q->data.index){
            LinkList q1 = (LinkList)malloc(sizeof(LNode));
            q1->data.factor = -q->data.factor, q1->data.index = q->data.index;
            Lminus->next = q1, Lminus = q1, q = q->next;
        }
        else{
            if(!(p->data.factor - q->data.factor)){
                p = p->next, q = q->next;
                continue;
            }
            else{
             Lminus->next = p, Lminus = p, p = p->next;
             Lminus->data.factor -= q->data.factor;
             q = q->next;
             count++;
            }
        }
    }
    Lminus1->Length = HL.elem[i]->Length +HL.elem[j]->Length - count;
    if(p){
        LinkList p1 = (LinkList)malloc(sizeof(LNode));
            p1->data.factor = p->data.factor, p1->data.index = p->data.index;
            Lminus->next = p1, Lminus = p1, p = p->next;
    }
    else if(q){
        while(q){
            LinkList q1 = (LinkList)malloc(sizeof(LNode));
            q1->data.factor = -q->data.factor, q1->data.index = q->data.index;
            Lminus->next = q1, Lminus = q1, q = q->next;
        }
    }
    Lminus->next = NULL;
    PrintList(Lminus1);
    return OK;
}

Status QuickSortList(LinkList &L){
    LinkList p = L->next, q, max;
    Elementtype tempdata;
    while(p->next){
        max = p;
        q = p->next;
        while(q){
            if(p->data.index < q->data.index){
                max = q;
            }
            q = q->next;
        }
        if(max != p){
        tempdata = max->data;
        max -> data = p->data;
        p->data = tempdata;
        }
        p = p->next;
    }
    return OK;
}

Status MultiPolynomial(HeadList HL){
    int i,j;
    int count = 0;
    printf("请输入需要操作的多项式：");
    scanf("%d%d",&i,&j);
    LinkList p = HL.elem[i]->next, q = HL.elem[j]->next;
    LinkList Lmulti = (LinkList)malloc(sizeof(LNode));
    if(!Lmulti){
        return ERROR;
    }
    LinkList Lmulti1 = Lmulti;
    while(p){
        while(q){
            if(!count){
                count++;
                LinkList q1 = (LinkList)malloc(sizeof(LNode));
                q1->data.factor = p->data.factor * q->data.factor;
                q1->data.index = p->data.index + q->data.index;
                Lmulti->next = q1;
                Lmulti = q1;
                Lmulti->next = NULL;
                q = q->next;
            }
            else if(!GetElemFromPol(Lmulti1, p->data.index + q->data.index)){
                count++;
                LinkList q1 = (LinkList)malloc(sizeof(LNode));
                q1->data.factor = p->data.factor * q->data.factor;
                q1->data.index = p->data.index + q->data.index;
                Lmulti->next = q1;
                Lmulti = q1;
                Lmulti->next = NULL;
                q = q->next;
            }
            else{
                LinkList temp = GetElemFromPol(Lmulti1, p->data.index + q->data.index);
                temp->data.factor += p->data.factor * q->data.factor;
                q = q->next;
                if(temp->data.factor == 0){
                    LinkList s = Lmulti1, r;
                    while(s!=temp){
                        r = s;
                        s = s->next;
                    }
                    LinkList del = temp;
                    r -> next = s -> next;
                    free(del);
                    q = q->next;
                    continue;
                }
            }
        }
        p = p->next;
        q = q = HL.elem[j]->next;
    }
    Lmulti1->Length = count;
    QuickSortList(Lmulti1);
    PrintList(Lmulti1);
    return OK;
}

Status EvaluateList(HeadList HL){
    int i;
    float eval, sum = 0;
    printf("请选择要操作的多项式：");
    scanf("%d",&i);
    printf("请输入要带的值：");
    scanf("%2f",&eval);
    LinkList p = HL.elem[i]->next;
    while(p){
        sum += p->data.factor * pow(eval, p->data.index);
        p = p->next; 
    }
    printf("多项式带值结果为�?%4f", sum);
    return OK;
}

Status DestroyPol(HeadList &HL){
    printf("请选择要销毁的多项式：");
    int i,j;
    scanf("%d",&i);
    if(!i){
        return ERROR;
    }
    for(j = i;j <= HeadListLength;j++){
        HL.elem[j] = HL.elem[j+1];
    }
    HeadListLength --;
    printf("销毁后的多项式：\n");
    for(int d = 1;d <=HeadListLength;d++){
        PrintList(HL.elem[d]);
    }
    return OK;
}

Status ClearList(HeadList &HL){
    printf("请选择要清空的多项式：");
    int i;
    scanf("%d",&i);
    HL.elem[i]->next = NULL;
    HL.elem[i]->Length = 0;
    return OK;
}

Status InsertNode(LinkList &L){
    printf("请输入要插入项的系数及指数：");
    float factor;
    int index;
    scanf("%f%d",&factor, &index);
    LinkList p = L, q = p->next;
    LinkList s = (LinkList) malloc(sizeof(LNode));
    s->data.factor = factor, s->data.index = index;
    if(q->data.index == index) return ERROR;
    L->Length++;
    while(q->data.index > index){
        p = p->next;
        q = q->next;
    }
    p->next = s;
    s->next = q;
    return OK;
}

Status DeleteNode(LinkList &L){
    printf("此多项式的数据为：\n");
    PrintList(L);
    printf("请选择删除项的指数�?");
    int ch;
    scanf("%d",&ch);
    if(!GetElemFromPol(L,ch)) return ERROR;
    LinkList p = L;
    LinkList q = p->next;
    L->Length--;
    for(int i = 1; q->data.index != ch; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return OK;
}

Status AmendNode(LinkList &L){
    printf("此多项式的数据为：\n");
    PrintList(L);
    printf("请选择修改项的指数�?");
    int ch;
    scanf("%d",&ch);
    if(!GetElemFromPol(L,ch)) return ERROR;
    LinkList p = L->next;
    for(int i = 1; p->data.index != ch; i++){
        p = p->next;
    }
    printf("请选择修改后的系数与指数：");
    float factor;
    int index;
    scanf("%f%d",&factor, &index);
    p->data.factor = factor, p->data.index = index;
    QuickSortList(L);
    return OK;
}

Status AmendPol(HeadList HL){
    int ch;
    printf("请选择要进行的操作(1.插入新项 2.删除�? 3.修改�?):");
    scanf("%d",&ch);
    printf("请选择要修改的多项式：");
    int i;
    scanf("%d",&i);
    switch(ch){
        case 1:
            InsertNode(HL.elem[i]);
            printf("修改后的多项式为：\n");
            PrintList(HL.elem[i]);
            break;
        case 2:
            DeleteNode(HL.elem[i]);
            printf("修改后的多项式为：\n");
            PrintList(HL.elem[i]);
            break;
        case 3:
            AmendNode(HL.elem[i]);
            printf("修改后的多项式为：\n");
            PrintList(HL.elem[i]);
            break;
        default:
            return ERROR;

    }
    return OK;
}

Status DifList(HeadList HL){
    int i, count = 0;
     printf("请选择要操作的多项式：");
    scanf("%d",&i);
    LinkList p;
    InitList(p);
    LinkList s = HL.elem[i]->next, p1 = p;
    while(s){
        if(!s->data.index){
            p->next = NULL;
            break;
        }
        else{
        count++;
        p->next= s;
        p->next->data.factor *= p->next->data.index;
        p->next->data.index --;
        p = p->next;
        s = s->next;
        }
    }
    p1->Length = count;
    PrintList(p1);
    return OK;
}

Status PrintIntegList(LinkList p1){
    printf("项数�?%d\n", p1->Length);
    LinkList p2 = p1->next;
    if(!p2->data.index){
            printf("%.2f*lnx", p2->data.factor);
            p2 = p2->next;
        }
        else{
        printf("%.2f*x^(%d) ",p2->data.factor,p2->data.index);
        p2 = p2->next;
        }
    while(p2){
        if(!p2->data.index){
            printf("+%.2f*lnx", p2->data.factor);
            p2 = p2->next;
        }
        else{
        printf("+%.2f*x^(%d) ",p2->data.factor,p2->data.index);
        p2 = p2->next;
        }
    }
    printf("+C\n\n计算完成!\n");
    return OK;
}

Status IndefIntegList(HeadList HL, LinkList &p1){
    int i, count = 0;
     printf("请选择要操作的多项式：");
    scanf("%d",&i);
    LinkList p ;
    InitList(p);
    LinkList s = HL.elem[i]->next;
    p1 = p;
    while(s){
        if(!(s->data.index+1)){
            p->next = s;
            p->next->data.index++;
            p = p->next;
            s = s->next;
        }
        else{
        count++;
        p->next= s;
        p->next->data.factor /= (p->next->data.index+1);
        p->next->data.index ++;
        p = p->next;
        s = s->next;
        }
    }
    p1->Length = count;
    return OK;
}


Status DefIntegList(HeadList HL, LinkList &p1){
    float up, down, sum = 0;
    printf("请选择要带入的上下界：");
    scanf("%f%f",&up,&down);
    LinkList p2 = p1->next;
    while(p2){
         if(!p2->data.index){
            sum += p2->data.factor * log(up);
            sum -= p2->data.factor * log(down);
            p2 = p2->next;
        }
        else{
        sum += p2->data.factor * pow(up, p2->data.index);
        sum -= p2->data.factor * pow(down, p2->data.index);
        p2 = p2->next;
        }
    }
    printf("定积分结果为:%.4f\n计算完成!\n", sum);
    return OK;
}

/*Status Four_rule_operation(HeadList HL){

}*/
void printMenu() {
	printf("\n**********************************\n");
	printf("\t多项式器功能菜单\t\n");
	printf("**********************************\n");
	printf("0、退出\n");
    printf("**********************************\n");
    printf(" *基础功能:\t\n");
    printf("1、打印菜单\n");
	printf("2、输入多项式\n");
    printf("3、输出多项式：\n");
	printf("4、多项式加法\n");
	printf("5、多项式减法\n");
	printf("6、多项式求值\n");
    printf("7、销毁多项式\n");
    printf("8、清空多项式\n");
    printf("9、修改多项式\n");
    printf("**********************************\n");
    printf("*拓展功能:\t\n");
	printf("10、多项式微分\n");
	printf("11、多项式不定积分\n");
	printf("12、多项式定积分\n");
    printf("13、多项式乘法\n");
	printf("**********************************\n\n");
}
void clearCache(void) {
	while (getchar() != '\n')
		;
}