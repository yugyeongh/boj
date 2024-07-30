#include <iostream>
#include <queue>
using namespace std;

int N, temp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    priority_queue <pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;

    for (int i=0;i<N;i++){
        cin >> temp;
        pq.push({i,temp});
    }

    int idx = pq.top().first;
    int a = pq.top().second;
    pq.pop();
    while (!pq.empty()){
        if (a < pq.top().second){
            cout << pq.top().second << " ";
            a = pq.top().second;
            break;
        } else {
            cout << "-1 ";
        }
    }



    cout << '\n';

    return 0;
}
