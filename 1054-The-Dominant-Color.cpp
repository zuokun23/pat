//map的简单使用
#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

map<int , int> record;
int m , n;
int main(){
    
	scanf("%d%d",&m,&n);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			int tmp;
			scanf("%d",&tmp);
			record[tmp]++;
		}
	}

	int max = 0 , ret;
	for(auto i = record.begin() ; i != record.end() ; i++){
		if(i->second > max){
			max = i->second;
			ret = i->first;
		}
	}

	printf("%d\n",ret);
	return 0;
}
