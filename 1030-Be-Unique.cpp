//hash表简单应用
#include<cstdio>

using namespace std;

int hashTable[10010] = {0};
int a[100010]; 
int main(){

	int n;
	scanf("%d" , &n);
	for(int i = 0 ; i < n ;i++){
		int t;
		scanf("%d", &t);
		hashTable[t]++;
		a[i] = t;
	}

	for(int i = 0 ; i < n ; i++){
		int t = a[i];
		if(hashTable[t] == 1){
			printf("%d\n",t);
			return 0;
		}
	}
	printf("None\n");
	return 0 ;
}
