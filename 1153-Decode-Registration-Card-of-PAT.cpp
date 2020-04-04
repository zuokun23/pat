#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

struct stu{
	string id;
	int sco;
};
struct site{
	string siteId;
	int cnt;
};
bool cmp1(const stu &a , const stu &b){
	return a.sco == b.sco ? a.id < b.id : a.sco > b.sco;
}
bool cmp2(const site &a , const site &b){
	return a.cnt == b.cnt ? a.siteId < b.siteId : a.cnt > b.cnt;
}

int main(){
	
	int n , m;
	scanf("%d%d",&n,&m);
	vector<stu> v(n);
	for(int i = 0 ; i < n ; i++){
		cin >> v[i].id >> v[i].sco;
	}
	for(int i = 1 ; i <= m ; i++){
		int num;
		scanf("%d",&num);
		if(num == 1){
			
			//string level;
			//cin >> level;
			//printf("Case %d: %d %s\n",i,num,level.c_str());
			
			char level;
			scanf(" %c",&level);//注意这里多一个空格，千万不能丢
			printf("Case %d: %d %c\n",i,num,level);
			vector<stu> ans;
			for(int j = 0 ; j < n ; j++){
				if(v[j].id[0] == level)
					ans.push_back(v[j]);
			}
			sort(ans.begin() , ans.end() , cmp1);
			if(ans.size() != 0){
				for(int j = 0 ; j < ans.size() ; j++){
					printf("%s %d\n",ans[j].id.c_str(),ans[j].sco);
				}
			}else{
				printf("NA\n");
			}
		}else if(num == 2){
			int cnt = 0 , sum = 0;
			string siteId;
			cin >> siteId;
			printf("Case %d: %d %s\n",i,num,siteId.c_str());
			for(int j = 0 ; j < n ; j++){
				if(siteId == v[j].id.substr(1 , 3)){
					cnt++;
					sum += v[j].sco;
				}
			}
			if(cnt == 0){
				printf("NA\n");
			}else{
				printf("%d %d\n",cnt,sum);
			}
		}else if(num == 3){
			string date;
			cin >> date;
			unordered_map<string , int> m;
			vector<site> ans; 
			printf("Case %d: %d %s\n",i,num,date.c_str());
			for(int j = 0 ; j < n ; j++){
				if(date == v[j].id.substr(4 , 6)){
					string tt = v[j].id.substr(1 , 3);
					m[tt]++;
				}
			}
			for(auto it = m.begin() ; it != m.end() ; it++){
				ans.push_back({it->first , it->second});
			}
			sort(ans.begin() , ans.end() , cmp2);
			if(ans.size() == 0){
				printf("NA\n");
			}else{
				for(int j = 0 ; j < ans.size() ; j++){
					printf("%s %d\n",ans[j].siteId.c_str(),ans[j].cnt);
				}
			}
		}
	}
	return 0;
}
