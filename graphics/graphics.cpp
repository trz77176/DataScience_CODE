#include "graphics.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"
char photo[41]="ͼƬ\\a.jpg";//ͼƬ·��
//==========================================��������
int  shuru_ch(char *m);//�����ַ�����ch[] 
int ismun(char a);//�ж��Ƿ������� 
int isop(char a);//�ж��Ƿ�������� 
void initgraph() ;//�����û����� 
int check(char a[]);//�ַ���ch[]�Ϸ��Լ��� 
double count(double x, double y, char a);//���㺯�� 
void qushu(char ch[],double *s,char *p);//ȡ������ 
//---------------------------------------
int main()
{
	int m,n;int i=0;
	char put[41];//��double�͵�������ת��Ϊ�ַ���װ��put[41] 
	char ch[41];//���ַ��� 
	double s[41];//�渡���� 
	double x; 
        char p[41];//���������+��-��
	RECT r={1,1,400,100};//RECT ������������һ��rectangle(����)
	initgraph();//�����û�����
	//--------------------------------------------------------- 
	here://goto��� 
	//--------------------------------------------------------- 
        for(;i<41;i++)//ʹ����put��������ĩβ��\0 
		put[i]='\0';
	//--------------------------------------------------------- 
	shuru_ch(ch);//�����ַ�����ch[] 
        x=atof(ch);
	qushu(ch,s,p);//ȡ�� 
	for(m=0,n=0;s[m]!='\0';m++,n++)//���� 
        {
      	    x=count(x, s[m], p[n]);
        }
	sprintf(put,"%.2f",x);//��double�͵�������ת��Ϊ�ַ���װ��put[41] 
        clearrectangle(0,0,400,100);//���� 
   	drawtext(put,&r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ���r�ϸ�ʽ����������� 
   	goto here;//�ص�here��������ʵ�ֶ�μ��� 
	getch();
	closegraph();//�ر�ͼ�ν��� 
	int j=0;
	for(;s[j]!='\0';j++)
	printf("%f\n",s[j]);
	return 0;
}
 
//=============================================================================================
//ʱ�䣺2019.5.18 
int shuru_ch(char *ch)//�����ַ��� 
{
	int i=0;
	char x[4][4]={{'7','8','9','+'},//��ͼ�ν�����Ϣ�ö�ά�����ʾ
		        {'4','5','6','-'},
			{'1','2','3','*'},
			{'.','0','=','/'}};
									
	MOUSEMSG m;
	RECT r={1,1,400,100};//RECT ������������һ��rectangle�����Σ� 
	//---------------------------------------------------- -------------------------- 
	for(;i<41;i++)// ʹ����ch��������ĩβ��\0 
		ch[i]='\0';
	//----------------------------------------------------- ---------------------------- 
	i=0;
	while(1)
	{
		m=GetMouseMsg();
		if(m.mkLButton&&m.uMsg==WM_LBUTTONDOWN)//�ж��������Ƿ���
		{
			if(m.x>=200&&m.x<=300&&m.y>=400&&m.y<=500)//�����=����������ɣ����ַ���ת��check������֤�Ϸ��ԣ�
				{
					if(check(ch)==1)
						return 1;
					else
						{
							drawtext("����������������룡",&r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
							shuru_ch(ch); 
						 } 
				}
			else
				{
					ch[i]=x[(m.y)/100-1][(m.x)/100];//���λ�ã�x��y����Ϣ�����㣬����Ӧ�Ķ�ά����x�е�ֵ��ֵ��ch
					i++;
				}
			
		clearrectangle(0,0,400,100);
		drawtext(ch,&r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ���r����ʾ�������� 
		}
	}
} 
//=============================================================================================
//ʱ�䣺2019.5.18 
	void initgraph() 
	{
	int m=0,n=0;
	int x[]={0,100,200,300},y[]={100,200,300,400};//ͼƬ������������Ϣ
	IMAGE img;//����ͼ�����img 
	initgraph(400,500,NULL);//��������
	for(;m<4;m++)//x�� 
	{
		for(n=0;n<4;n++)//y�� 
		{
			loadimage(&img,photo,100,100);//ͼƬ��ʼ�������������С
			putimage(x[m],y[n],&img);//ѡ�����꣬ճ��ͼƬ
			photo[5]=photo[5]+1;//�ı�ͼƬ·��
		}
	}
	}
//===========
//���ܣ��ж����֣������ַ���1�����򷵻�0
//ʱ�䣺2019.4.5
int ismun(char a)
{
    if(a>='0'&&a<='9')
        return 1;
    return 0;
}
//=======================================
//���ܣ��ж�������������������1�����򷵻�0
//ʱ�䣺2019.4.5
int isop(char a)
{
    if(a=='+'||a=='-'||a=='/'||a=='*')
        return 1;
    return 0;
}
//========================================
//���ܣ����㹦�ܣ�����������
//ʱ�䣺2019.4.5
double count(double x, double y, char a)
{
    double t;
    switch(a)
    {
        case '+':t=x+y;break;
        case '-':t=x-y;break;
        case '*':t=x*y;break;
        case '/':t=x/y;break;
    }
    return t;
}
//=======================================
//���ܣ��Ϸ��Ժ������ж��ַ����Ϸ��ԣ��Ϸ�����1�����򷵻�1
//ʱ�䣺2019.4.5
int check(char *ch)//�Ϸ���
{
	int i;
    if(ismun(ch[0])==0||ismun(ch[strlen(ch)-1])==0)//�жϵ�һ�������һ���Ƿ�Ϊ����
        return 0;
    for(i=0;ch[i]!='\0';i++)
    {
        if((isop(ch[i])==1&&isop(ch[i+1])==1)||(ch[i]=='.'&&isop(ch[i+1]))||(isop(ch[i])&&ch[i+1]=='.'))//�ж��Ƿ��������������.+��+.�����
            return 0;
        if(isop(ch[i])==0&&ismun(ch[i])==0&&ch[i]!='.')//��������������֡�С�����Ƿ���������ַ�
            return 0;
    }
    int j;    //�ж��Ƿ����2..2��2.2.222.2.2�����
    for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='.')
            for(j=i+1;;j++)
            {
                if(isop(ch[j])==1||ch[j]=='\0')
                    break;
                if(ch[j]=='.')
                    return 0;
            }
    }
    for(i=0;ch[i]!='\0';i++)//�Ƿ�Ϊ������
    {
        if(isop(ch[i])==1)
            return 1;
    }
    return 0;
}
//========================================================
//���ܣ����ַ����е�����������ֱַ����p[]��s[]�У������㡮*����/��
//ʱ�䣺2019.4.5
void qushu(char *ch,double *s,char *p)
{
 
    double y;
    int m=0,n=0,i;
    for(i=0; ch[i]!='\0'; i++)
    {
    	
        if(ch[i]=='+'||ch[i]=='-')
        {
            *(p+n)=ch[i];//p[n]��*(p+n) Ч��һ�� 
            *(s+m)=atof(ch+i+1);
            m++;
            n++;
        }
        if(ch[i]=='/')
        {
            y=atof(ch+i+1);
            *(s+m-1)=count(*(s+m-1),y,ch[i]);
        }
        if(ch[i]=='*')
        {
            y=atof(ch+i+1);
            *(s+m-1)=count(*(s+m-1),y,ch[i]);
        }
    }
    s[m]='\0';
    p[n]='\0';
}