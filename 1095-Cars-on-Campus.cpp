#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 10010;
struct Car{//每条记录

	char id[8];
	int time;//s为单位
	char status[4];
}all[maxn] , valid[maxn];
int num = 0;//有效记录条数

int timeToInt(int hh , int mm , int ss){//转换为以s为单位
	return hh*3600+mm*60+ss;
}
map<string , int> parkTime;//车牌号->总停留时间

bool cmp1(Car a , Car b){
	if(strcmp(a.id , b.id)) return strcmp(a.id , b.id) < 0 ;//按车牌排序来消除invaild
	else	return a.time < b.time;
}
bool cmp2(Car a , Car b){
	return a.time < b.time;
}
int main(){
	
	int n , k , hh , mm , ss;
	//读取记录
	scanf("%d%d",&n,&k);
	for(int i = 0 ; i < n ; i++){
		scanf("%s %d:%d:%d %s",all[i].id,&hh,&mm,&ss,all[i].status);
		all[i].time = timeToInt(hh , mm ,ss);
	}
	sort(all , all+n , cmp1);
	//把invalid记录消除,顺便记录下最长时间
	int maxTime = -1;
	for(int i = 0 ; i < n-1 ; i++){
		if(!strcmp(all[i].id , all[i+1].id) &&//i和i+1是同一辆车
			!strcmp(all[i].status , "in") &&//i是in记录
			!strcmp(all[i+1].status , "out")){//i+1是out记录
			valid[num++] = all[i];
			valid[num++] = all[i+1];
		
			int inTime = all[i+1].time - all[i].time;//此次停留时间
		
			/*if(parkTime.find(all[i].id) == parkTime.end()) 
				parkTime.insert(make_pair(all[i].id , 0));*/
			parkTime[all[i].id] += inTime;
			maxTime = max(maxTime , parkTime[all[i].id]);
		}
	}
	
	//把有效记录按时间大小排序
	sort(valid , valid+num , cmp2);
	//查询
	int numCar = 0 , now = 0;//车数,now为valid的索引
	for(int i = 0 ; i < k ; i++){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int time = timeToInt(hh , mm , ss);
		while(now < num && valid[now].time <= time){
			if(!strcmp(valid[now].status , "in")) numCar++;
			else	numCar--;
			now++;
		}
		printf("%d\n",numCar);
	}

	//输出
	for(auto it = parkTime.begin() ; it != parkTime.end() ; it++){
		if(it->second == maxTime)
			printf("%s ",it->first.c_str());
	}
	printf("%02d:%02d:%02d\n",maxTime/3600,(maxTime%3600)/60,maxTime%60);
	return 0;
}
