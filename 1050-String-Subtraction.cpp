//1：set的简单使用
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

set<char> record;
char s1[10010];

int main(){
    
	int cnt = 0;
	char c;
	scanf("%c",&c);
	while(c != '\n'){
		s1[cnt++] = c;//%c是scanf唯一能获取空格的
		scanf("%c",&c);
	}//getchar();
	scanf("%c",&c);
	while(c != '\n'){
		record.insert(c);
		scanf("%c",&c);
	}
	//双指针
	int i = 0 , j = -1;
	while(i < cnt){
	
		if(record.find(s1[i]) == record.end())//没找到不用去除
			s1[++j] = s1[i];
		i++;
	}

	for(int k = 0 ; k <= j ; k++)
		printf("%c",s1[k]);
	printf("\n");
	return 0;
}
//2简化版
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

set<char> record;
char s1[10010];

int main(){
    
	int cnt = 0;
	char c;
	scanf("%c",&c);
	while(c != '\n'){
		s1[cnt++] = c;//%c是scanf唯一能获取空格的
		scanf("%c",&c);
	}//getchar();
	scanf("%c",&c);
	while(c != '\n'){
		record.insert(c);
		scanf("%c",&c);
	}
	
	for(int i = 0 ; i < cnt ; i++)
		if(record.find(s1[i]) == record.end())
			printf("%c",s1[i]);
	return 0;
}
