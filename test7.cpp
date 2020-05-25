#include<stdio.h>
#include <iostream>
#include<malloc.h>
#include<cstring>
using namespace std;

const int MAX = 1000001;

void get_next(string t, int* next)
{
	int i = 0;//next�����±�
	int j = -1;//next[]��ֵ������Ϊ0~m-1
	next[0] = -1;
	while (i < t.length())
	{
		if (j == -1 || t[i] == t[j])
		{//��������ڻ��������ϣ��ɵõ�nextֵ
			++i; ++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
int KMP(string s, string t)//s������ʼλ��pos
{
	int j = 0;
	int length = t.length();
	//int *next = (int*)malloc((j-1)*sizeof(int));
	int next[MAX];
	get_next(t, next);
	for (int k = 0; k < t.length(); k++)
		cout << next[k] << ' ';
	cout << endl;
	int i = 0;//��������ʼλ��
	j = 0;//ģʽ�����±�
	while (i < s.length() && j < length)
	{
		if (j == -1 || s[i] == t[j])//���ǵ���һ������ȵ����
		{
			++i; ++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= length) return i - length;
	else return 0;
}
int main()
{
	string s;
	cin >> s;
	int N;//��ƥ�䴮�ĸ���
	cin >> N;
	string t[N];
	for (int i = 0; i < N; i++)
	{
		cin >> t[i];
	}
	int result[N];
	for (int i = 0; i < N; i++)
	{
		result[i] = KMP(s, t[i]);
	}
	for (int i = 0; i < N; i++)
	{
		if (result[i] == 0)
		{
			cout << "Not Found\n";
		}
		else
		{
			for (int j = result[i]; j < s.length(); j++)
			{
				cout << s[j];
			}
			cout << endl;
		}
	}
	return 0;
}
