#include "graphics.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"
char photo[41]="图片\\a.jpg";//图片路径
//==========================================函数声明
int  shuru_ch(char *m);//输入字符串到ch[] 
int ismun(char a);//判断是否是数字 
int isop(char a);//判断是否是运算符 
void initgraph() ;//创建用户界面 
int check(char a[]);//字符串ch[]合法性检验 
double count(double x, double y, char a);//计算函数 
void qushu(char ch[],double *s,char *p);//取数函数 
//---------------------------------------
int main()
{
	int m,n;int i=0;
	char put[41];//将double型的运算结果转换为字符串装入put[41] 
	char ch[41];//存字符串 
	double s[41];//存浮点数 
	double x; 
        char p[41];//存运算符（+，-）
	RECT r={1,1,400,100};//RECT 参数名：定义一个rectangle(矩形)
	initgraph();//创建用户界面
	//--------------------------------------------------------- 
	here://goto标记 
	//--------------------------------------------------------- 
        for(;i<41;i++)//使后面put数组内容末尾有\0 
		put[i]='\0';
	//--------------------------------------------------------- 
	shuru_ch(ch);//输入字符串到ch[] 
        x=atof(ch);
	qushu(ch,s,p);//取数 
	for(m=0,n=0;s[m]!='\0';m++,n++)//计算 
        {
      	    x=count(x, s[m], p[n]);
        }
	sprintf(put,"%.2f",x);//将double型的运算结果转换为字符串装入put[41] 
        clearrectangle(0,0,400,100);//清屏 
   	drawtext(put,&r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形r上格式化输出运算结果 
   	goto here;//回到here处，用于实现多次计算 
	getch();
	closegraph();//关闭图形界面 
	int j=0;
	for(;s[j]!='\0';j++)
	printf("%f\n",s[j]);
	return 0;
}
 
//=============================================================================================
//时间：2019.5.18 
int shuru_ch(char *ch)//输入字符串 
{
	int i=0;
	char x[4][4]={{'7','8','9','+'},//将图形界面信息用二维数组表示
		        {'4','5','6','-'},
			{'1','2','3','*'},
			{'.','0','=','/'}};
									
	MOUSEMSG m;
	RECT r={1,1,400,100};//RECT 参数名：定义一个rectangle（矩形） 
	//---------------------------------------------------- -------------------------- 
	for(;i<41;i++)// 使后面ch数组内容末尾有\0 
		ch[i]='\0';
	//----------------------------------------------------- ---------------------------- 
	i=0;
	while(1)
	{
		m=GetMouseMsg();
		if(m.mkLButton&&m.uMsg==WM_LBUTTONDOWN)//判断鼠标左键是否按下
		{
			if(m.x>=200&&m.x<=300&&m.y>=400&&m.y<=500)//点击‘=’（输入完成，将字符串转至check函数验证合法性）
				{
					if(check(ch)==1)
						return 1;
					else
						{
							drawtext("输入错误，请重新输入！",&r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
							shuru_ch(ch); 
						 } 
				}
			else
				{
					ch[i]=x[(m.y)/100-1][(m.x)/100];//鼠标位置（x，y）信息经运算，将对应的二维数组x中的值赋值给ch
					i++;
				}
			
		clearrectangle(0,0,400,100);
		drawtext(ch,&r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在举行r内显示输入内容 
		}
	}
} 
//=============================================================================================
//时间：2019.5.18 
	void initgraph() 
	{
	int m=0,n=0;
	int x[]={0,100,200,300},y[]={100,200,300,400};//图片张贴作坐标信息
	IMAGE img;//创建图像对象img 
	initgraph(400,500,NULL);//创建画布
	for(;m<4;m++)//x轴 
	{
		for(n=0;n<4;n++)//y轴 
		{
			loadimage(&img,photo,100,100);//图片初始化，并限制其大小
			putimage(x[m],y[n],&img);//选择坐标，粘贴图片
			photo[5]=photo[5]+1;//改变图片路径
		}
	}
	}
//===========
//功能：判断数字，是数字返回1，否则返回0
//时间：2019.4.5
int ismun(char a)
{
    if(a>='0'&&a<='9')
        return 1;
    return 0;
}
//=======================================
//功能：判断运算符，是运算符返回1，否则返回0
//时间：2019.4.5
int isop(char a)
{
    if(a=='+'||a=='-'||a=='/'||a=='*')
        return 1;
    return 0;
}
//========================================
//功能：计算功能，返回运算结果
//时间：2019.4.5
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
//功能：合法性函数，判断字符串合法性，合法返回1，否则返回1
//时间：2019.4.5
int check(char *ch)//合法性
{
	int i;
    if(ismun(ch[0])==0||ismun(ch[strlen(ch)-1])==0)//判断第一个和最后一个是否为数字
        return 0;
    for(i=0;ch[i]!='\0';i++)
    {
        if((isop(ch[i])==1&&isop(ch[i+1])==1)||(ch[i]=='.'&&isop(ch[i+1]))||(isop(ch[i])&&ch[i+1]=='.'))//判断是否有连续运算符或.+和+.的情况
            return 0;
        if(isop(ch[i])==0&&ismun(ch[i])==0&&ch[i]!='.')//除开运算符、数字、小数点是否存在其它字符
            return 0;
    }
    int j;    //判断是否存在2..2或2.2.222.2.2的情况
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
    for(i=0;ch[i]!='\0';i++)//是否为纯数字
    {
        if(isop(ch[i])==1)
            return 1;
    }
    return 0;
}
//========================================================
//功能：将字符串中的运算符和数字分别存在p[]和s[]中；并运算‘*’‘/’
//时间：2019.4.5
void qushu(char *ch,double *s,char *p)
{
 
    double y;
    int m=0,n=0,i;
    for(i=0; ch[i]!='\0'; i++)
    {
    	
        if(ch[i]=='+'||ch[i]=='-')
        {
            *(p+n)=ch[i];//p[n]与*(p+n) 效果一样 
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