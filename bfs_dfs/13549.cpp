/*
 * *** logic ***
 * 1. 걷기는 +1초 후에 1 or -1
 * 2. 순간이동은 0초 후에 2*x
 *
 * *** Input ***
 * 1. 수빈 위치 N, 동생 위치 K
 *
 * *** Output ***
 * 1. 수빈이가 동생을 찾는 가장 빠른 시간
 *
 * *** Constraint ***
 * 1. 0 ≤ N, K ≤ 100,000
 *
 * *** Solution ***
 * 1. 오 pq를 사용한다니
 *
 */

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool v[100001] = {false,};
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>>pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    pq.push({0,N});

    while (!pq.empty()) {
        int time = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        v[x] = true;

        if (x==K) {
            cout << time << '\n';
            break;
        }

        if(x-1>=0 && !v[x-1])
            pq.push(make_pair(time+1,x-1));
        if(x+1<=100000 && !v[x+1])
            pq.push(make_pair(time+1,x+1));
        if(x*2<=100000 && !v[x*2])
            pq.push(make_pair(time,x*2));
    }

    return 0;
}
