#include<iostream>
#include<string>
#include<algorithm>
 
using namespace std;
 
int main(){
     
    int n;
    scanf("%d\n",&n);\\\\\\\\\\\特别注意要加\n没加就错了
    string ans;
    for(int i = 0 ; i < n ; i++){
     
        string s;
        getline(cin , s);
        int len = s.length();
        reverse(s.begin() , s.end());
        if(i == 0)
            ans = s;
        else{
            int ansLen = ans.length();
            int minLen = min(ansLen , len);
            for(int j = 0 ; j < minLen ; j++){
                if(ans[j] != s[j]){
                    ans = ans.substr(0 , j);
                    break;
                }
            }
        }
    }
 
    reverse(ans.begin() , ans.end());
    if(ans.length() == 0)
        ans = "nai";
    cout << ans;
    return 0;
}
