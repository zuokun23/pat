#include<iostream>
#include<cstring>
#include<string>

using namespace std;

//中心思想是找到E
int main(){
    
	string s;
	cin >> s;//pat用gets通不过
	if(s[0] == '-')
		cout << "-";
	
	int pos;
	for(int i = 1 ; i < s.size() ; i++)
		if(s[i] == 'E'){
			pos = i;
			break;
		}
	int exp = stoi(s.substr(pos + 2 , s.size() - pos - 2));//指数
	if(s[pos+1] == '-'){
		
		cout << "0.";
		for(int i = 0 ; i < exp - 1 ; i++)	cout<<"0";
		for(int i = 1 ; i < pos ; i++)
			if(s[i] != '.')
				cout << s[i];
		cout << endl;
	}else{
			if(exp >= pos - 3){//pos与.之间字符个数
				for(int i = 1 ; i < pos ; i++)
					if(s[i] != '.')
						cout << s[i];
				for(int i = 0 ; i < exp - pos + 3 ; i++)
					cout << "0";
			}else{
				int i;
				for(i= 1 ; i <= 2+exp ; i++)
					if(s[i] != '.')
						cout << s[i];
				cout << ".";
				for( ; i < pos ; i++)
					cout << s[i];
			}
			cout <<endl;
	}

	return 0;
}	
