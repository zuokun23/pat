//方法一：使用二分搜索（upper_bound）
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> seq;

int upper_bound(int l , int r , long long x){
	
	int mid;
	while(l < r){
		mid = l + (r - l)/2;
		if(seq[mid] > x)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}
int main(){
	
	int n , p , tmp;
	scanf("%d%d",&n,&p);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&tmp);
		seq.push_back(tmp);
	}

	sort(seq.begin() , seq.end());

	int maxL = 0 , pos; 
	for(int i = 0 ; i < n ; i++){
		
		pos = upper_bound(i+1 , n , (long long)seq[i]*p) - 1;//特意包含位置n,>m*p的第一个位置-1
		if(pos - i + 1 > maxL)
			maxL = pos - i + 1;
	}
	printf("%d",maxL);
	return 0;
}


//方法二 使用algorithm库中函数upper_bound()
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> seq;

int main(){
	
	int n , p , tmp;
	scanf("%d%d",&n,&p);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&tmp);
		seq.push_back(tmp);
	}
	sort(seq.begin() , seq.end());

	int maxL = 0 , pos; 
	for(int i = 0 ; i < n ; i++){
		pos = upper_bound(seq.begin()+i , seq.end() , (long long)seq[i]*p) - seq.begin();
		if(pos - i + 1 > maxL)
			maxL = pos - i;
	}
	printf("%d",maxL);
	return 0;
}

//方法三 使用two pointers滑动窗口
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
	
	int n , p;
	scanf("%d%d",&n,&p);

	vector<int> seq(n);//记住这种用法
	for(int i = 0 ; i < n ; i++)
		scanf("%d",&seq[i]);

	sort(seq.begin() , seq.end());
	int res = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = i + res; j < n ; j++){//优化：直接从i + res开始
			if(seq[j] <= (long long) seq[i]*p)
				res = j -i +1;
			else
				break;
		}
	}

	printf("%d",res);
	return 0;
}
//方法三 对照版
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
	
	int n , p;
	scanf("%d%d",&n,&p);

	vector<int> seq(n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d",&seq[i]);

	sort(seq.begin() , seq.end());
	int res = 1;//此处变了 默认本身为完美数串
	for(int i = 0 ; i < n ; i++){
		for(int j = i + res + 1; j < n ; j++){//变了
			if(seq[j] <= (long long) seq[i]*p)
				res = j - i + 1;//没变，因为都是[i , j)->[i,j]
			else
				break;
		}
	}

	printf("%d",res);
	return 0;
}
