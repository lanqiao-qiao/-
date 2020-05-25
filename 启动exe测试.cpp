#include <iostream>
#include <windows.h>
#include <shellapi.h> 
#include <fstream>
using namespace std;
int num_city;//��������
int dis[25][25];
int spe[25][25];
double Time[25][25];

void init_map()
{
	for(int i=1;i<=num_city;i++)
	{
		for(int j=1;j<=num_city;j++)
		{
			if(i==j)
			{
				dis[i][j]=spe[i][j]=Time[i][j]=0;
			}
			else
				dis[i][j]=spe[i][j]=Time[i][j]=9999;
		}
	}
}
void getdata()
{
	ifstream in("D:\\map.txt",ios::in);
	if(!in)
	{
		cout<<"��ȡĬ������ʧ��"<<endl;
		exit(1);
	}
	in>>num_city;
	init_map();
	int a,b,c,d;
	for(int i=1;i<=num_city;i++)
	{
		in>>a>>b>>c>>d;
		dis[a][b]=dis[b][a]=c;
		spe[a][b]=spe[b][a]=d;
		Time[a][b]=Time[b][a]=double(c)/double(d);
	}
}

void out_data()
{
	for(int i=1;i<=num_city;i++)
	{
		for(int j=1;j<=num_city;j++)
		{
			cout<<i<<' '<<j<<' '<<dis[i][j]<<' '<<spe[i][j]<<' '<<Time[i][j]<<endl;
		}
	}
}
void open_exe()
{
	Sleep(2000);
	ShellExecute(NULL, "open", "D:/lan_qiao/pixiv/35291141_p0.jpg",NULL, NULL,SW_SHOW );
}
void init()
{
	cout<<"ѡ�����ݻ�ȡ��ʽ��"<<endl;
	cout<<"1.���ı�����Ĭ����Ϣ"<<endl;
	cout<<"2.�Լ���������"<<endl;
	cout<<"3.�������ɵ�ͼ"<<endl;
	int i;
	cin>>i;
	if(i==1)
	{
		getdata();
		out_data();
	}
	if(i==3)
	{
		open_exe();
	}
}

int main()
{
	init();
}
