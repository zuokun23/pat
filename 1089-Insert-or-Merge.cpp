//法一：用数组
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

法二：用vector，并且对mergeSort加入了自己的见解
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 110;
int n;

void showArray(vector<int> &A){
	
	for(int i = 0 ; i < n ; i++){
		printf("%d",A[i]);
		if(i != n-1)
			printf(" ");
	}
}

bool insertSort(vector<int> &A , vector<int> &B){
	
	bool flag = false;
	for(int i = 1 ; i < n ; i++){
		int t = A[i] , j = i-1;
		if(i != 1 && A == B)//经过一趟后查看
			flag = true;
		while(j >= 0 && A[j] > t){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = t;
		if(flag == true)
			return true;
	}
	return false;
}

void mergeSort(vector<int> &A ,vector<int> &B){
	bool flag = false;
	for(int i = 2 ; i/2 < n ; i*=2){//不用等于代表右边至少一个
		if(i != 2 && A==B)
			flag = true;
		for(int j = 0 ; j + i/2 < n ; j += i){//j+i/2代表的是右边第一个元素，表示右边至少存在一个元素
			sort(A.begin() + j, A.begin() + min(n,j+i));
		}
		if(flag == true){
			showArray(A);
			return;
		}
	}
}
int main(){

	scanf("%d",&n);
	vector<int> origin(n),tmp(n),target(n);
	for(int i = 0 ; i < n ; i++){
	
		scanf("%d",&origin[i]);
		tmp[i] = origin[i];
	}
	for(int i = 0 ; i < n ; i++)
		scanf("%d",&target[i]);

	if(insertSort(tmp , target)){
		printf("Insertion Sort\n");
		showArray(tmp);
	}else{
		printf("Merge Sort\n");
		tmp = origin;
		mergeSort(tmp,target);
	}

	return 0;
}
