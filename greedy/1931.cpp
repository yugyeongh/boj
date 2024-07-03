/*
 * *** solution ***
 * 1. 가장 먼저 떠오른 생각은 pq 활용하기
 */
#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> a >> b;
        pq.push({b,a});
    }

    int end = pq.top().first;
    pq.pop();
    int cnt=1;
    for (int i=1;i<N;i++){
        if (end <= pq.top().second){
            cnt++;
            end = pq.top().first;

        }
        pq.pop();
    }

    cout << cnt;

    return 0;
}