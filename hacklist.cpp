#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#define limit 1500 

typedef struct requirement{
	char name[5];
	int bytes;
}List;	//ÿ������Ļ����ṹ 

int num = 0, founded = 0;	//�Ѽ�¼�ĸ������Ѿ����ֵĺڿ͸���
char hacklist[26*26*26*26*4] = {}; 	//�ڿ����� 

void add(List list[], char _name[], int _byte);	//���һ���µ������� 
int search(List list[], char name[]);	//Ѱ���Ƿ��Ѿ����ڣ�������λ�ã����򷵻�-1 
void output(void);	//����ڿ����� 

/*------------------------------------------------*/ 

int main(void)
{
	freopen("Request.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	//�����ļ�������ļ��ض���	
		
	List *list = (List*)malloc(sizeof(List)*26*26*26*26);
	char temp_name[5];
	int temp;
	//Ϊ���������߷���ռ䣬������ʱ������ݵ� 
	
	while(scanf("%s %*s %d", temp_name, &temp) != EOF){
		int pos =search(list, temp_name);	//�������������� 
		
		if( pos!= -1){	//�����Ѿ������, �õ���λ�� 
			int pre = list[pos].bytes;
			list[pos].bytes+=temp;	//����ԭʼ���ݣ�׼��������ݴ�С 
			
			if(pre < limit && list[pos].bytes >= limit){	// ���������С�Ѿ���������Χ 
				strcat(hacklist, temp_name);
				founded++;
			}
			
		}	 
		else{	//����δ����� 
			add(list, temp_name, temp);
			
			if( temp >= limit ){	// ���������С�Ѿ���������Χ
				strcat(hacklist, temp_name);
				founded++;
			}
		}
	}
	
	//����Ҫ����� 
	printf("%d\n", founded);
	output();
	
	
	free(list);
	return 0;
}

/*------------------------------------------------*/ 

void add(List list[],char _name[], int _bytes)
{
	strcpy(list[num].name, _name);
	list[num].bytes = _bytes;
	num++;
}

/*------------------------------------------------*/ 

int search(List list[], char name[5])
{
	int found = 0, i;
	
	for(i=0; i<num; i++)
		if(!strcmp(list[i].name, name)){
			found = 1;
			break;
		}
		
	return (found)? i:-1;
}

/*------------------------------------------------*/ 

void output(void)
{
	for(int j=0; j<founded*4; j++){
		printf("%c", hacklist[j]);
		if((j+1)%4==0)
			putchar('\n');
	}
}
