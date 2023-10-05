//���Ա�
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LIST_INIT_SIZE 100//���Ա�洢�ռ�ĳ�ʼ������ 
#define LISTINCREMENT 10//���Ա�洢�ռ�ķ�������
#define OK 1;
#define ERROR -1;

typedef struct{
	int *elem;
	int Length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L){
	//����һ���յ����Ա�
	L.elem = (int*)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!L.elem) exit(-1);
	L.Length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

int ListInsert_Sq(SqList &L,int i, int e){
	//��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e
	//i�ĺϷ�ֵΪ��1��ListLength_Sq(L)+1��
	int *newbase = NULL;//������ռ����ʧ��ʱ����ԭ�ռ��ַ��ʧ�����ڴ�й©
	if(i<1 || i>L.Length+1) return ERROR;
	if(L.Length>=L.listsize){
		//��ǰ����ռ����������ӷ���
		newbase = (int*)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase) exit(-1);//����ʧ��
		L.elem = newbase;
		L.listsize += LISTINCREMENT;//���Ӵ洢����
	}
	int *q = &(L.elem[i-1]);
	
	for(int* p = &(L.elem[L.Length-1]);p>=q;--p)  *(p+1) = *(p);
	//����Ԫ�ؼ�֮���Ԫ������
	*q = e;
	++L.Length;
	return OK;
}

int ListDelete_Sq(SqList &L,int i, int &e){
	//��˳�����Ա���ɾ����i��Ԫ�أ�����e������ֵ
	//i�ĺϷ�ֵΪ[1, ListLength_Sq(L)]
	if((i<1)||(i>L.Length)) return ERROR;
	int *p = &(L.elem[i-1]);
	e = *p;
	int* q = L.elem+L.Length - 1;//��βԪ�ص�λ��
	for(++p;p<=q;++p)  *(p-1) = *p;//Ԫ������
	--L.Length;
	return OK;
}

int Compare(int a,int b){
	return(a>b ?1 :1);
}

int main(){
	
}
