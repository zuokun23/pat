#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 110;
int n;
int origin[MAXN] , tmp[MAXN] , target[MAXN];

bool isSame(int A[] , int B[]){

	for(int i = 0 ; i < n ;i++)
		if(A[i] != B[i]) return false;
	return true;
}

void showArray(int A[]){
	
	for(int i = 0 ; i < n ; i++){
		printf("%d",A[i]);
		if(i < n-1) printf(" ");
	}
	printf("\n");
}

bool insertSort(){
	bool flag = false;
	for(int i = 1; i < n ;i++){
		if(i != 1 && isSame(tmp,target)){//判断放前面是为了得到下一个
			flag = true;//小心初始序列等于目标序列不算
		}
		int t = tmp[i] , j = i - 1;
		while(j >= 0 && tmp[j] > t){
			tmp[j+1] = tmp[j];
			j--;
		}
		tmp[j+1] = t;
		if(flag == true)
			return true;
	}
	return false;
}

void mergeSort(){
	
	bool flag = false;
	for(int step = 2 ; step/2 <= n ; step = step*2){//左边长度<=2
		if(step != 2 && isSame(tmp,target))//小心初始序列等于目标序列不算
			flag = true;

		for(int i = 0 ; i < n ; i+=step){//i表示左边第一个
			sort(tmp + i , tmp + min(n,i+step));//第二个参数要在右边最后一个元素的下一位
		}
		if(flag == true){
			showArray(tmp);
			return;
		}
	}
}
int main(){

	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
	
		scanf("%d",&origin[i]);
		tmp[i] = origin[i];
	}
	for(int i = 0 ; i < n ; i++)
		scanf("%d",&target[i]);

	if(insertSort()){
		printf("Insertion Sort\n");
		showArray(tmp);
	}else{
		printf("Merge Sort\n");
		for(int i = 0 ; i < n ; i++){
			tmp[i] = origin[i];
		}
		mergeSort();
	}

	return 0;
}
