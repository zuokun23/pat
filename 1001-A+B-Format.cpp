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
