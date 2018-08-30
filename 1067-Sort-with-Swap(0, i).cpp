//版本1 pat上运行超时
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int pos[maxn];//存放索引，交换数值和交换索引是一样的作用

int main(){
	
	int n , ans = 0;//ans表示总交换次数
	scanf("%d",&n);
	int num , left = n-1;//因为确定1..n-1中值位置后就不动了，而0的位置每次都要动
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&num);
		pos[num] = i;
		if(num == i && num != 0)
			left--;
	}
	while(left > 0){
		if(pos[0] == 0){//随机选一个与0交换位置
			for(int k = 1 ; k < n ; k++){
				if(pos[k] != k){
					swap(pos[0],pos[k]);
					ans++;
					break;
				}
			}
		}
		while(pos[0] != 0){
			swap(pos[0] , pos[pos[0]]);
			ans++;
			left--;
		}
	}
	printf("%d\n",ans);
	return 0;
}

//版本2 改进pat运行不超时
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int pos[maxn];//存放索引，交换数值和交换索引是一样的作用

int main(){
	
	int n , ans = 0;//ans表示总交换次数
	scanf("%d",&n);
	int num , left = n-1;//因为确定1..n-1中值位置后就不动了，而0的位置每次都要动
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&num);
		pos[num] = i;
		if(num == i && num != 0)
			left--;
	}
	int k = 1;//用k来保存除0外不在本位最小的数
	while(left > 0){
		if(pos[0] == 0){//随机选一个与0交换位置
			while(k < n){
				if(pos[k] != k){
					swap(pos[0],pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while(pos[0] != 0){
			swap(pos[0] , pos[pos[0]]);
			ans++;
			left--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
