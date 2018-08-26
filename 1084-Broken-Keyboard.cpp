#include<iostream>
#include<cstring>
#include<string>
#include<set>

using namespace std;

int main(){
    
	//hash(set一样)
	set<char> record;
	string s1 , s2;
	cin >> s1 >> s2;
	for(int i = 0 ; i < s2.size() ; i++){
		if(s2[i] >= 'a' && s2[i] <= 'z' )//大小写不敏感，都作为大写存储
			record.insert(char(s2[i] - 'a' + 'A'));
		else
			record.insert(s2[i]);
	}
	for(int i = 0 ; i < s1.size() ; i++){
		char c = s1[i];
		if(c >= 'a' && c <= 'z')
			c = char(c - 'a' + 'A');
		if(record.find(c) == record.end()){
			cout << c;
			record.insert(c);//保证只输出一次
		}
	}
	return 0;
}	
