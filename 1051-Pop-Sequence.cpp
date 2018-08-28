#include<cstdio>
#include<stack>

using namespace std;
const int maxn = 1010;
stack<int> st;
int m , n , t;
int arr[maxn];//用来存取sequence

//核心思想：根据每一个arr[i]的值来判断进栈次数（要求不超过最大容量），然后执行一次出栈（要求出栈值==arr[i]）
int main(){
	
	scanf("%d%d%d",&m,&n,&t);
	for(int i = 0 ; i < t ; i++){
		while(!st.empty()){//清空栈
			st.pop();
		}
		for(int j = 1 ; j <= n ; j++)
			scanf("%d",&arr[j]);

		int pos = 1;//要入栈的数
		bool flag = true;
		for(int j = 1 ; j <= n ; j++){
			//入栈
			for(int k = pos ; k <= arr[j] ; k++){
				if(st.size() >= m){
					flag = false;
					break;
				}
				st.push(pos);
				pos++;
			}
			if(flag == false)
				break;
			//出栈
			int t = st.top();
			st.pop();
			if(t != arr[j])
				flag = false;
		}
		if(flag == false)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
