//堆排序
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map> 

using namespace std;

const int MAXN = 110;
int n;

void showArray(vector<int> &A){
	
	for(int i = 1 ; i <= n ; i++){
		printf("%d",A[i]);
		if(i != n)
			printf(" ");
	}
}

bool insertSort(vector<int> &A , vector<int> &B){
	
	bool flag = false;
	for(int i = 2 ; i <= n ; i++){
		int t = A[i] , j = i-1;
		if(i != 2 && A == B)//经过一趟后查看
			flag = true;
		while(j >= 1 && A[j] > t){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = t;
		if(flag == true)
			return true;
	}
	return false;
}

void shiftDown(int l ,int h,vector<int> &A){//low high
	
	int i = l , j = 2*i;
	while(j <= h){//左孩子存在
		
		if(j+1 <= h && A[j+1] > A[j])//选出最大的一个孩子
			j++;
		if(A[j] > A[i]){
			swap(A[j],A[i]);
			i = j;
			j = 2*i;//左孩子
		}else
			break;//不往下走了
	}
}
void heapSort(vector<int> &A ,vector<int> &B){
	
	bool flag = false;
	for(int i = n/2 ; i >=1 ; i--)
		shiftDown(i,n,A);
	
	for(int i = n ; i >= 2; i--){//堆排序
		if(i != n && A == B)
			flag = true;
		swap(A[i],A[1]);
		shiftDown(1,i-1,A);//第i位及以后都已经排好
		if(flag == true){
			showArray(A);
			return;
		}
	}

}

int main(){
	//索引从1开始
	scanf("%d",&n);
	vector<int> origin(n+1),tmp(n+1),target(n+1);
	for(int i = 1 ; i <= n ; i++){
	
		scanf("%d",&origin[i]);
		tmp[i] = origin[i];
	}
	for(int i = 1 ; i <= n ; i++)
		scanf("%d",&target[i]);

	if(insertSort(tmp , target)){
		printf("Insertion Sort\n");
		showArray(tmp);
	}else{
		printf("Heap Sort\n");
		tmp = origin;
		heapSort(tmp,target);
	}

	return 0;
}
