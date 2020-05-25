#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;

typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;      /* �洢Ԫ�ص�����   */
    Position Front, Rear;   /* ���е�ͷ��βָ�� */
    int MaxSize;            /* �����������     */
};
typedef PtrToQNode Deque; 

Deque CreateDeque( int MaxSize )
{   /* ע�⣺Ϊ���ֿն��к������У���Ҫ�࿪��һ���ռ� */
    Deque D = (Deque)malloc(sizeof(struct QNode));
    MaxSize++;
    D->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    D->Front = D->Rear = 0;
    D->MaxSize = MaxSize;
    return D;
}
ElementType Pop(Deque D)
{
	if(D->Rear==D->Front)
		return ERROR;
	else
	{
		int a=D->Data[D->Front];
		D->Front=(D->Front+1)%D->MaxSize;
		return a;
	}
	
}
ElementType Eject(Deque D)
{
	if(D->Rear==D->Front)
		return ERROR;
	else
	{
		D->Rear = (D->Rear -1 +D->MaxSize)%D->MaxSize;
		int a=D->Data[D->Rear];
		return a;
	}
	
}
bool Push(ElementType X,Deque D)
{
	if((D->Rear+1)%(D->MaxSize)==D->Front)
	{
		return false; 
	}
	else
	{
		D->Front=(D->Front-1+D->MaxSize)%D->MaxSize;
		D->Data[D->Front]=X;
		return true;
	}
}
bool Inject(ElementType X, Deque D)
{
	if((D->Rear+1)%(D->MaxSize)==D->Front)
		return false;
	else
	{
		D->Data[D->Rear]=X;
		D->Rear=(D->Rear+1)%D->MaxSize;
		return true;
	}
}

int main()
{
	int n;
}












