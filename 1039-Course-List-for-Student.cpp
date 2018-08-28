//hash + vector省时间 + 省空间
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
const int n = 40010;
const int m = 26*26*26*10 + 1;//由姓名散列而成 
vector<int> selectCourse[m];

int getID(char name[]){//hash函数，将字符串name转化为数字
	int id = 0;
	for(int i = 0 ; i < 3 ; i++){
		id = id*26 + (name[i] - 'A');
	}
	id = id*10 + (name[3] - '0');
	return id;
}
int main(){
	//hash + vector省空间 省时间
	char name[5];
	int n , k;
	scanf("%d%d",&n,&k);//人数和课程数
	for(int i = 0 ; i < k ; i++){
		int course , x;
		scanf("%d%d",&course,&x);
		for(int j = 0 ; j < x ; j++){
			scanf("%s",name);
			int id = getID(name);
			selectCourse[id].push_back(course);
		}
	}

	for(int i = 0 ; i < n ; i++){
		scanf("%s" , name);
		int id = getID(name);
		//排序
		sort(selectCourse[id].begin() , selectCourse[id].end());//从小到大
		printf("%s %d",name,selectCourse[id].size());
		for(int j = 0 ; j < selectCourse[id].size() ; j++){
			printf(" %d",selectCourse[id][j]);
		}
		printf("\n");
	}
	return 0;
}



//运行超时,pat 23/25
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
const int maxn = 40010;
//本想写个学生的结构体，但没必要
map<string , vector<int>> record;
int n , k;

int main(){
	
	scanf("%d%d",&n,&k);
	for(int i = 0 ; i < k ; i++){
		int id , num;
		string name;
		scanf("%d%d",&id,&num);
		for(int j=0 ; j <num ; j++){
			cin >> name;
			/*if(record.find(name) != record.end())
				record.find(name)->second.push_back(id);
			else{
				record.insert(make_pair(name , vector<int>()));
				record.find(name)->second.push_back(id);				
			}*/
			record[name].push_back(id);
		}
	}
	//记得排序
	for(auto it = record.begin() ; it != record.end() ; it++)
		sort(it->second.begin() , it->second.end());
	//输出
	for(int i = 0 ; i < n ; i++){
		string name;
		cin >> name;
		cout << name << " ";
		int size = record[name].size(); 
		printf("%d",size);
		for(int i = 0 ; i < size ; i++){
			printf(" %d",record[name][i]);
		}
		printf("\n");
	}
	return 0;
}

