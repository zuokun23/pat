//字符串处理，技巧
#include <iostream>

using namespace std;

int main(){

    int a,b;
    cin >> a >> b;
    string s = to_string(a+b);
    int len = s.length();
    for(int i = 0 ; i < len ; i++){
        cout<<s[i];
        if(s[i] == '-') continue;
        if( (i+1)%3 == len%3 && i != len-1) printf(",");//编号为i+1(从1开始)的字符 与 编号为len的字符地位相同
    }
}

//死板的数据处理
#include<cstdio>
#include<stack>
using namespace std;

int main(){

    int a,b,res;
    stack<int> s;

    scanf("%d %d",&a,&b);
    res = a + b;

    if(res == 0)
        printf("0");
    else{

        if(res < 0){
            printf("-");
            res = 0-res;
        }
        while (res > 0) {
            s.push(res % 1000);
            res /= 1000;
        }
        int len = s.size();
        while (!s.empty()) {
            if(s.size() == len)
                printf("%d",s.top());
            else
                printf("%03d",s.top());
            if(s.size() > 1)
                printf(",");
            s.pop();
        }
    }
    return 0;
}
