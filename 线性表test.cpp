#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode 
{
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList( List L ); /* ����ʵ�֣�ϸ�ڲ��� */
List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
}
List ReadInput()
{
	List s;
	s=(List)malloc(sizeof(LNode));
	int n;
	scanf("%d",&n);
	s->Last=n-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s->Data[i]);
	}
	return s;
} 
List Delete( List L, ElementType minD, ElementType maxD )
{
	int i,p=0;
	for(int i=0;i<=L->Last;i++)
	{
		if(L->Data[i]>minD&&L->Data[i]<maxD)
			p++;
		else
			L->Data[i-p]=L->Data[i];
	}
	L->Last-=p;
	return L;
} 
void PrintList( List L )
{
	for(int i=0;i<=L->Last;i++)
		printf("%d ",L->Data[i]);
}
