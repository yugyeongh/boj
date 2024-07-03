/*
 * *** solution ***
 * 1. 다른 지원자에 비해 성적, 면접이 모두 떨어지면 선발x
 * 2. pq 사용하기
 */

#include <iostream>
#include <queue>
using namespace std;

int T, N;
int a, b;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--){
        cin >> N;
        for (int i=0;i<N;i++){
            cin >> a >> b;
            pq.push({a,b});
        }

        int interview = pq.top().second;
        pq.pop();
        int cnt=1;
        while (!pq.empty()){
            if (interview > pq.top().second){
                cnt++;
                interview = pq.top().second;
            }
            pq.pop();
        }
        cout << cnt << '\n';
    }

    return 0;
}
