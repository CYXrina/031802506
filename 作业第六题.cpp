#include<stdio.h>
#include<string.h>
int num[10] = {};
void count(char c) 	{num[c-48]++;}		//����ÿ�����ֵĳ��ִ��� 
void print(int k, int time);		//��Ҫ���ӡ 

int main()
{
	int k;
	char str[1000];
	scanf("%s", str);
	k = strlen(str);
	for(int i = 0; i < k; i++)
		count(str[i]);
	for(int max = 0, number; ; max = 0)
	{
		for(int i = 9; i >= 0; i--)	 
		{
			if(num[i]>max)
			{
				max = num[i];
				number = i;
			}
		}
		
		if(max > 0)	
		{print(number, max);
			num[number] = 0;}	//��ӡ����� 
		else 		break;
	}
	
	return 0;
} 

void print(int k, int time)
{
	for(int i = 1; i <= time; i++)
		printf("%d", k);
}

