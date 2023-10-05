#include"Cauculator.h"

int main(){
    HeadList HL;
    printMenu();
    InitList_HL(HL);
	int ch;
	printMenu();
	while (1) {
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%d", &ch);
		clearCache();
		if (ch == 0)
			break;
		switch (ch) {
			case 1:
				printMenu();
				break;
			case 2:
				printf("是否要继续输入：");
                int i;
                scanf("%d",&i);
                while(i){
                    LinkList L;
                    InitList(L);
                    CreateList(HL,L);
                    printf("是否要继续输入：");
                    scanf("%d",&i);
                }
				printf("输入完成！\n");
                for(int d = 1;d <=HeadListLength;d++){
                    printf("第%d个多项式：\n",d);
                    PrintList(HL.elem[d]);
                }
				clearCache();
				break;
			case 3:
				for(int d = 1;d <=HeadListLength;d++){
                    printf("第%d个多项式：\n",d);
                    PrintList(HL.elem[d]);
                }
				clearCache();
				break;
			case 4:
				AddPolynomial(HL);
				clearCache();
				break;
			case 5:
				MinusPolynomial(HL);
				clearCache();
				break;
			case 6:
				EvaluateList(HL);
				clearCache();
				break;
			case 7:
				DestroyPol(HL);
				clearCache();
				break;
			case 8:
				ClearList(HL);
				clearCache();
				break;
			case 9:
				AmendPol(HL);
				clearCache();
				break;
			case 10:
				DifList(HL);
				clearCache();
				break;	
			case 11:
				LinkList p;
				InitList(p);
				IndefIntegList(HL,p);
				PrintIntegList(p);
				clearCache();
				break;	
			case 12:
				LinkList p1;
				InitList(p1);
				IndefIntegList(HL, p1);
				DefIntegList(HL, p1);
				clearCache();
				break;
			case 13:
				MultiPolynomial(HL);
				clearCache();
				break;		
			default:
				break;
		}
	}
}

