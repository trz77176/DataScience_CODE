#include<stdio.h>
#include<malloc.h>
typedef int ElementType;
typedef struct Node{
	ElementType data;//������
	struct Node*next;//ָ����
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
	//LΪ��ͷ���ĵ������ͷָ��
	LinkList p = L->next;
	int j = 1;
	while(p&&j<i){
		p = p->next;
		++j;
	}
	if(!p || j>i) return 0;//������
	e = p->data;
	return 1;
}

LinkList InsertElement(LinkList&L,int i,ElementType e){
	//��һ��������������м����
	//�ڶ��������������ͷ����
    //�����������������β����
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

//������ĺϲ�
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc){
	//��֪A��B��ֵ�ǵݼ���������
	//�鲢��Lc����Lc��Ԫ���԰�ֵ�ǵݼ���������
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

//������ľ͵�����
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

//ѭ������βָ��ָ��head��ͷ�ڵ������Ԫ�ڵ㣩


//�ָ������ѭ������  ��ĸ ���ֺ������ַ�


