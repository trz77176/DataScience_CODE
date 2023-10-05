//线性表
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LIST_INIT_SIZE 100//线性表存储空间的初始分配量 
#define LISTINCREMENT 10//线性表存储空间的分配增量
#define OK 1;
#define ERROR -1;

typedef struct{
	int *elem;
	int Length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L){
	//构造一个空的线性表
	L.elem = (int*)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!L.elem) exit(-1);
	L.Length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

int ListInsert_Sq(SqList &L,int i, int e){
	//在顺序线性表L的第i个元素之前插入新的元素e
	//i的合法值为【1，ListLength_Sq(L)+1】
	int *newbase = NULL;//避免因空间分配失败时，将原空间地址丢失导致内存泄漏
	if(i<1 || i>L.Length+1) return ERROR;
	if(L.Length>=L.listsize){
		//当前储存空间已满，增加分配
		newbase = (int*)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase) exit(-1);//分配失败
		L.elem = newbase;
		L.listsize += LISTINCREMENT;//增加存储容量
	}
	int *q = &(L.elem[i-1]);
	
	for(int* p = &(L.elem[L.Length-1]);p>=q;--p)  *(p+1) = *(p);
	//插入元素及之后的元素右移
	*q = e;
	++L.Length;
	return OK;
}

int ListDelete_Sq(SqList &L,int i, int &e){
	//在顺序线性表中删除第i个元素，并用e返回其值
	//i的合法值为[1, ListLength_Sq(L)]
	if((i<1)||(i>L.Length)) return ERROR;
	int *p = &(L.elem[i-1]);
	e = *p;
	int* q = L.elem+L.Length - 1;//表尾元素的位置
	for(++p;p<=q;++p)  *(p-1) = *p;//元素左移
	--L.Length;
	return OK;
}

int Compare(int a,int b){
	return(a>b ?1 :1);
}

int main(){
	
}
