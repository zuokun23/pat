//AC代码
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct person {
    int arrive, start, time;
    bool vip;
}tempperson;
struct tablenode {
    int end = 8 * 3600, num;
    bool vip;
};
bool cmp1(person a, person b) {
    return a.arrive < b.arrive;
}
bool cmp2(person a, person b) {
    return a.start < b.start;
}
vector<person> player;
vector<tablenode> table;
void alloctable(int personid, int tableid) {
    if(player[personid].arrive <= table[tableid].end)
        player[personid].start = table[tableid].end;
    else
        player[personid].start = player[personid].arrive;
    table[tableid].end = player[personid].start + player[personid].time;
    table[tableid].num++;
}
int findnextvip(int vipid) {
    vipid++;
    while(vipid < player.size() && player[vipid].vip == false) vipid++;
    return vipid;
}
int main() {
    int n, k, m, viptable;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int h, m, s, temptime, flag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &temptime, &flag);
        tempperson.arrive = h * 3600 + m * 60 + s;
        tempperson.start = 21 * 3600;
        if(tempperson.arrive >= 21 * 3600) continue;
        tempperson.time = temptime <= 120 ? temptime * 60 : 7200;
        tempperson.vip = ((flag == 1) ? true : false);
        player.push_back(tempperson);
    }
    scanf("%d%d", &k, &m);
    table.resize(k + 1);
    for(int i = 0; i < m; i++) {
        scanf("%d", &viptable);
        table[viptable].vip = true;
    }
    sort(player.begin(), player.end(), cmp1);
    int i = 0, vipid = -1;
    vipid = findnextvip(vipid);
    while(i < player.size()) {
        int index = -1, minendtime = 999999999;
        for(int j = 1; j <= k; j++) {
            if(table[j].end < minendtime) {
                minendtime = table[j].end;
                index = j;
            }
        }
        if(table[index].end >= 21 * 3600) break;
        if(player[i].vip == true && i < vipid) {
            i++;
            continue;
        }
        if(table[index].vip == true) {
            if(player[i].vip == true) {
                alloctable(i, index);
                if(vipid == i) vipid = findnextvip(vipid);
                i++;
            } else {
                if(vipid < player.size() && player[vipid].arrive <= table[index].end) {
                    alloctable(vipid, index);
                    vipid = findnextvip(vipid);
                } else {
                    alloctable(i, index);
                    i++;
                }
            }
        } else {
            if(player[i].vip == false) {
                alloctable(i, index);
                i++;
            } else {
                int vipindex = -1, minvipendtime = 999999999;
                for(int j = 1; j <= k; j++) {
                    if(table[j].vip == true && table[j].end < minvipendtime) {
                        minvipendtime = table[j].end;
                        vipindex = j;
                    }
                }
                if(vipindex != -1 && player[i].arrive >= table[vipindex].end) {
                    alloctable(i, vipindex);
                    if(vipid == i) vipid = findnextvip(vipid);
                    i++;
                } else {
                    alloctable(i, index);
                    if(vipid == i) vipid = findnextvip(vipid);
                    i++;
                }
            }
        }
    }
    sort(player.begin(), player.end(), cmp2);
    for(i = 0; i < player.size() && player[i].start < 21 * 3600; i++) {
        printf("%02d:%02d:%02d ", player[i].arrive / 3600, player[i].arrive % 3600 / 60, player[i].arrive % 60);
        printf("%02d:%02d:%02d ", player[i].start / 3600, player[i].start % 3600 / 60, player[i].start % 60);
        printf("%.0f\n", round((player[i].start - player[i].arrive) / 60.0));
    }
    for(int i = 1; i <= k; i++) {
        if(i != 1) printf(" ");
        printf("%d", table[i].num);
    }
    return 0;
}


//有两个测试用例没过
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

const int maxn = 10010;
const int maxk = 110;
struct Player{
	int arriTime , serveTime , playTime;
	bool tag;
}player[maxn];
vector<int> q;//队列--由于可以从中间删除，不用queue
struct Table{
	int endTime;//每个桌子当前对打完的时间
	bool isVIP;//当前桌子是否是VIP桌
	int cnt;
}table[maxk];

int convertInt(int h , int m , int s){
	return h*3600 + m*60 + s;//时间单位为s
}
bool cmp1(Player a , Player b){
	return a.arriTime < b.arriTime;
}
bool cmp2(Player a , Player b){
	return a.serveTime < b.serveTime;
}
/*vs2010中cmath库中无round函数，自己写个
double round(double r)
{
	return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}
*/
int main(){
	int n , hh , mm , ss , m , k , playTime;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		player[i].arriTime = convertInt(hh , mm , ss);
		scanf("%d%d",&playTime,&player[i].tag);
		player[i].playTime = playTime > 120 ? 120*60 : playTime*60;
	}
	sort(player , player+n ,cmp1);//排好队
	scanf("%d%d",&k,&m);
	for(int i = 0 ; i < k ; i++){
		table[i].isVIP = false;
		table[i].cnt = 0;
		table[i].endTime = convertInt(8 , 0 ,0);//注意此处很重要
	}
	for(int i = 0 ; i < m ; i++){
		int tmp;
		scanf("%d",&tmp);
		table[tmp-1].isVIP = true;
	}

	q.resize(n);//队列中排队情况
	for(int i = 0 ; i < n ; i++)
		q[i] = i;
	int inIndex;//当前入队的player索引
	for(int i = 0 ; i < n ; i++){//遍历n次
		//找到一张先空的桌子idx
		int idx = -1 , minEndTime = 1 << 30;
		for(int j = 0 ; j < k ; j++){
			if(table[j].endTime < minEndTime){
				minEndTime = table[j].endTime;
				idx = j;
			}
		}
		//找到了要从队列中选出的player
		inIndex = 0;//这是q的索引
		if(table[idx].isVIP == true){
			for(int j = 0 ; j < q.size() ;j++){
				if(player[q[j]].tag == true && player[q[j]].arriTime <= table[idx].endTime){
					inIndex = j;
					break;
				}
			}
		}
		player[q[inIndex]].serveTime = max(player[q[inIndex]].arriTime , table[idx].endTime);
		table[idx].endTime = player[q[inIndex]].serveTime + player[q[inIndex]].playTime;
		if(player[q[inIndex]].serveTime < convertInt(21,0,0))//
			table[idx].cnt++;

		q.erase(q.begin() + inIndex);//现在还在排队的人
	}

	sort(player , player+n , cmp2);
	for(int i = 0 ; i < n; i++){
		if(player[i].serveTime < convertInt(21,0,0)){
			Player &p = player[i];
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",p.arriTime/3600,(p.arriTime%3600)/60 , p.arriTime%60,p.serveTime/3600,(p.serveTime%3600)/60 , p.serveTime%60 , (int)round(1.0*(p.serveTime - p.arriTime)/60) );
		}
	}
	for(int i = 0 ; i < k ; i++){
		printf("%d",table[i].cnt);
		if(i != k-1)
			printf(" ");
	}
	printf("\n");
	return 0;
}
