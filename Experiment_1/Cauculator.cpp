#include"Cauculator.h"

int main(){
    HeadList HL;
    printMenu();
    InitList_HL(HL);
	int ch;
	printMenu();
	while (1) {
		scanf("%d", &ch);
		clearCache();
		if (ch == 0)
			break;
		switch (ch) {
			case 1:
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
				printMenu();
				break;
			case 2:
				for(int d = 1;d <=HeadListLength;d++){
                    printf("第%d个多项式：\n",d);
                    PrintList(HL.elem[d]);
                }
				clearCache();
				printMenu();
				break;
			case 3:
				AddPolynomial(HL);
				clearCache();
				printMenu();
				break;
			case 4:
				MinusPolynomial(HL);
				clearCache();
				printMenu();
				break;
			case 5:
				EvaluateList(HL);
				clearCache();
				printMenu();
				break;
			case 6:
				DestroyPol(HL);
				clearCache();
				printMenu();
				break;
			case 7:
				ClearList(HL);
				clearCache();
				printMenu();
				break;
			case 8:
				AmendPol(HL);
				clearCache();
				printMenu();
				break;
			case 9:
				DifList(HL);
				clearCache();
				printMenu();
				break;	
			case 10:
				LinkList p;
				IndefIntegList(HL,p);
				clearCache();
				printMenu();
				break;	
			case 11:
				LinkList p1;
				DefIntegList(HL, p1);
				clearCache();
				printMenu();
				break;
			case 12:
				MultiPolynomial(HL);
				clearCache();
				printMenu();
				break;		
			default:
				break;
		}
	}
}

