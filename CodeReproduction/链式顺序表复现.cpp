#include<stdio.h>
#include<malloc.h>
typedef int ElementType;
typedef struct Node{
	ElementType data;//数据域
	struct Node*next;//指针域
}LNode, *LinkList;

LinkList InitList(){
	LinkList L = (LinkList) malloc(sizeof(LNode));
	L->next = NULL;
	return L;
}

void CreateListHead(LinkList &L, int n){
	L = InitList();
	for(int i = n;i>=1; i++){
		LinkList s = (LinkList) malloc(sizeof(LNode));
		scanf("%d",&s->data);
		s->next = L->next;
		L->next = s;
	}
}

void CreatListRear(LinkList &L, int n){
	L = InitList();
	LinkList p = L;
	
}

int GetElement(LinkList L,int i, ElementType &e){
	//L为带头结点的单链表的头指针
	LinkList p = L->next;
	int j = 1;
	while(p&&j<i){
		p = p->next;
		++j;
	}
	if(!p || j>i) return 0;//不存在
	e = p->data;
	return 1;
}

LinkList InsertElement(LinkList&L,int i,ElementType e){
	//第一种情况：在链表中间插入
	//第二种情况：在链表头插入
    //第三种情况：在链表尾插入
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    LinkList p = L;
    int j = 0;
    for(j=0;j<i-1;p=p->next,j++);
    if(!p||j>i-1)
       return L;
    s->next = p->next;
    p -> next = s;
    return L;
}

LinkList DeleteElement(LinkList &L, int i){
	LinkList p = L;
	int j =0;
	while(p->next && j<i-1){
		p = p->next; ++j;
	}
	if(!(p->next) || j>i-1){
		return L;
	}
	LinkList q = p->next;
	p->next = q->next;
	free(q);
	return L;
}

//单链表的合并
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc){
	//已知A和B按值非递减有序排列
	//归并成Lc，且Lc中元素仍按值非递减有序排列
	LinkList pa = La->next, pb = Lb->next;
	LinkList pc = Lc = La;
	while(pa&&pb){
		if(pa->data >= pb->data){
			pc->next = pa, pc = pa, pa = pa->next;
		}
		else{
			pc->next = pb, pc = pb, pb = pb->next;
		}
	}
	pc->next = pa?pa:pb;
	free(Lb);
}

//单链表的就地逆置
void Converse_L(LinkList &L){
	LinkList p = L->next,q;
	L->next = NULL;
	while(p!=NULL){
		q = p;
		p = p->next;
		q->next = L->next;
		L->next =q;
	}
}

//循环链表尾指针指向head（头节点而非首元节点）


//分割成三个循环链表  字母 数字和其他字符


