#include <iostream>
using namespace std;
struct node
{
	int p;
	int num;
};//��������һ���ṹ�����飬pΪ0��ʾ�����������ɳ©��1��ɳ©�� 
struct node a[1050];//num��ֵ�����ɳ©���ϱ�һ�з��ŵĸ�����Ҳ��ɳ©������ 
void init()//���ڽṹ������ĳ�ʼ�� 
{
	int sum=0;//������¼ɳ©�������� 
	int n;
	for(int i=0;i<1000;i++)//��ʵ�ò�����ô�࣬�����±���break��ֹ 
	{//���������¼��������ÿ���Ǽ������� 
		n=i*2+1;//��n��ʾ��������������ӵ���5������ 
		if(n==1)
			sum+=n;//��һ��(һ�����ŵ�ֻ��һ�����������) 
		else
			sum+=2*n;//�������Ǽ����� 
		if(sum>1000)//��������1000ֹͣѭ������ֹ���鱬�� 
			break;
		a[sum].p=1;//���������� 
		a[sum].num=n;//��¼��������� 
		//cout<<sum<<endl;
	}
}
char str;//�洢���� 
void print(int x)//��ӡɳ©�ĺ��� 
{
	int c=a[x].num;//��ȡ���� 
	int c1=c;//��ʾ��ǰ��ӡ������ 
	int k=0;//��ʾ��ǰ��ӡ�ո��� 
	for(int i=0;i<c/2+1;i++)//�ȴ�ӡ�ϰ벿�֣�����1���� 
	{
		for(int j=0;j<k;j++)
		{
			cout<<" ";
		}//�ȴ�ӡ�ո� 
		for(int j=0;j<c1;j++)
		{
			cout<<str;
		}//��ӡ���� 
		cout<<endl;
		k+=1;//ÿ�οո��һ�� 
		c1-=2;//���������� 
	}
	c1=3;//���ã�Ϊ��ӡ�±ߵ���׼�� 
	k=c/2-1;//����ͬ�� 
	for(int i=0;i<c/2;i++)
	{
		for(int j=0;j<k;j++)
		{
			cout<<" ";
		}
		for(int j=0;j<c1;j++)
		{
			cout<<str;
		}
		cout<<endl;
		k-=1;
		c1+=2;//����ͬ�� 
	}
}
int main()
{
	init();//���� 
	int n,j;
	cin>>n>>str;//���� 
	for(int i=n;i>=0;i--)
	{
		if(a[i].p==1)
		{
			j=i;
			break;	
		}
	}//��ȡ��ӽ���ɳ©�� 
	print(j);
	cout<<n-j<<endl;//��� 
}
