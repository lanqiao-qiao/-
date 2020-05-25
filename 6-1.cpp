#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
//typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) 
	{
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) 
	{
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) 
	{
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}
List MakeEmpty()
{
	List nnew;
	nnew=(List)malloc(sizeof(struct LNode));
	nnew->Last=-1;
	return nnew;
}
bool Insert( List L, ElementType X, Position P )
{
	if(L->Last==MAXSIZE-1)
	{
		printf("FULL");
		return false;
	}
	if(P<0||P>L->Last+1)//����һλ 
	{
		printf("ILLEGAL POSITION");
		return false;
	}
	for(int i=L->Last+1;i>P;i--)
		L->Data[i]=L->Data[i-1];
	L->Data[P]=X;
	L->Last++;
	return true;
}
Position Find( List L, ElementType X )
{
	for(int i=0;i<=L->Last;i++)
	{
		if(X==L->Data[i])
			return i;
	}
	return ERROR;
}
bool Delete( List L, Position P )
{
	if(P<0||P>L->Last)
	{
		printf("POSITION %d EMPTY",P);
		return false;
	}
	for(int i=P;i<L->Last;i++)
		L->Data[i]=L->Data[i+1];
	L->Last--;
	return true;
}



















