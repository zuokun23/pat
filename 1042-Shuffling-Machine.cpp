#include<cstdio>

using namespace std;

const int N = 54;
int start[N+1] , end[N+1] , order[N+1];
char mp[5] = {'S' , 'H' , 'C' , 'D' , 'J'};

int main(){
    
    int k;
    scanf("%d",&k);
	//初始化
	for(int i = 1 ; i <= 54 ; i++)
		scanf("%d",&order[i]);
	for(int i = 1 ; i <= 54 ; i++)
		start[i] = i;
	//算法
	for(int step = 1 ; step <= k ; step++){
		
		for(int i = 1 ; i <= 54 ; i++)
			end[order[i]] = start[i];
		for(int i = 1 ; i <= 54 ; i++)
			start[i] = end[i];
	}
	//输出
	for(int i = 1 ; i <= 54 ;i++){
		
		char c = mp[(start[i] - 1)/13];
		int t = (start[i] - 1)%13 + 1;
		printf("%c%d" , c , t);
		if(i != 54) printf(" ");
	}
	return 0;
}
