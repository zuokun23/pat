//考察双指针+map
//
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<string , int> record;//word及其出现次数
vector<string> ans;

bool isLegal(char c){//字符是否是alphanumerical
	
	if(c >= 'a' && c <= 'z')
		return true;
	else if(c >= 'A' && c <='Z')
		return true;
	else if(c >= '0' && c <= '9')
		return true;
	return false;
}
string transForm(string a){//大写->小写

	for(int i = 0 ; i < a.size() ; i ++)
		if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i] - 'A' + 'a';
	return a;
}

int main(){

	string s;
	getline(cin , s);
	int i = -1 , j = 0;//[i..j)表示一个word
	while(j < s.size()){
		
		while(j < s.size() && !isLegal(s[j]))	j++;//防止越界
		if(j >= s.size())
			break;//找完了
		i = j;
		while(j < s.size() && isLegal(s[j]))	j++;//防止越界
		//找到[i..j)
		string tmp = s.substr(i , j-i);//j-i为长度
		tmp = transForm(tmp);
		record[tmp]++;//特殊用法
	}

	int max = 0;
	for(auto it = record.begin() ; it != record.end() ; it++){
		if(it->second > max){
			max = it->second;
			ans.clear();
			ans.push_back(it->first);
		}else if(it->second == max){
			ans.push_back(it->first);
		}
	}
	
	if(ans.size() == 1)
		cout << ans[0] << " " << record[ans[0]]; 
	else{
		sort(ans.begin() , ans.end());
		cout << ans[0] << " " << record[ans[0]]; 
	}
	return 0;
}
