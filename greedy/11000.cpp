#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int S,T;

    cin >> N;
    for (int i=0;i<N;i++){
        cin >> S >> T;
        pq.push({S,T});
    }


    int cnt=1;
    int end = pq.top().second;
    pq.pop();
    while (!pq.empty()){
        if (end <= pq.top().first){
            cnt++;
            end = pq.top().second;
        }
        pq.pop();
    }

    cout << cnt << '\n';

    return 0;
}
