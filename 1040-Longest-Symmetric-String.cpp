#include<iostream>

using namespace std;

const int maxn = 1010;
//状态 dp[i][j]表示i..j是否为回文串，有true/false两种值
int dp[maxn][maxn];//实际是个上三角

int main(){

    string s;
    getline(cin , s);
    int n = s.size() , ans = 1;
    fill(dp[0] , dp[0] + maxn*maxn , 0);
    //边界
    for(int i = 0 ; i < n ; i++){
        dp[i][i] = 1;
        if(i != n-1 && s[i] == s[i+1]){
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
    //状态转移方程
    for(int L = 3 ; L <= n ; L++){//画个图片一目了然
        for(int i = 0 ; i + L -1 < n ; i++){
            int j = i + L - 1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1){
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    cout << ans;
    return 0;
}
