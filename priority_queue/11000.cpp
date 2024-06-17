#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int  N;
    cin >> N;

    vector <pair<int,int>> v(N);
    priority_queue <int, vector<int>, greater<int>> pq;

    for (int i=0;i<N;i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    pq.push(v[0].second);
    for (int i=1;i<N;i++){
        if (pq.top() <= v[i].first){
            pq.pop();
            pq.push(v[i].second);
        } else {
            pq.push(v[i].second);
        }
    }

    cout << pq.size() << '\n';
    return 0;
}
