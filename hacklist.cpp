#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#define limit 1500 

typedef struct requirement{
	char name[5];
	int bytes;
}List;	//每个请求的基本结构 

int num = 0, founded = 0;	//已记录的个数和已经发现的黑客个数
char hacklist[26*26*26*26*4] = {}; 	//黑客名单 

void add(List list[], char _name[], int _byte);	//添加一个新的请求者 
int search(List list[], char name[]);	//寻找是否已经存在，返回其位置，否则返回-1 
void output(void);	//输出黑客名单 

/*------------------------------------------------*/ 

int main(void)
{
	freopen("Request.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	//输入文件和输出文件重定向	
		
	List *list = (List*)malloc(sizeof(List)*26*26*26*26);
	char temp_name[5];
	int temp;
	//为所有请求者分配空间，设置临时存放数据点 
	
	while(scanf("%s %*s %d", temp_name, &temp) != EOF){
		int pos =search(list, temp_name);	//遍历已请求名单 
		
		if( pos!= -1){	//发现已经保存过, 得到其位置 
			int pre = list[pos].bytes;
			list[pos].bytes+=temp;	//保存原始数据，准备检查数据大小 
			
			if(pre < limit && list[pos].bytes >= limit){	// 发现请求大小已经超过合理范围 
				strcat(hacklist, temp_name);
				founded++;
			}
			
		}	 
		else{	//发现未保存过 
			add(list, temp_name, temp);
			
			if( temp >= limit ){	// 发现请求大小已经超过合理范围
				strcat(hacklist, temp_name);
				founded++;
			}
		}
	}
	
	//按照要求输出 
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
