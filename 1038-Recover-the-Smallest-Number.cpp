#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<string> num;
int n;

bool cmp(string a , string b){
	return a+b < b+a;
}
int main(){
	
	cin >> n;
	string str;
	for(int i = 0 ; i < n ; i++){
		cin >> str;
		num.push_back(str);
	}
	sort(num.begin() , num.end() , cmp);
	
	string ans;
	for(int i = 0 ; i < n ; i++)
		ans += num[i];
	//s = stoi(s);注意字符串长度太大，会造成中断
	while(ans.size() != 0 && ans[0] == '0')
		ans.erase(ans.begin());
	if(ans.size() == 0)
		cout << 0;
	else
		cout << ans;
	return 0;
}
