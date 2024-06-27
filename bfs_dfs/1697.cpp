#include <iostream>
#include <queue>
using namespace std;

int N, K;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
bool visited[100001]={false,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    pq.push({0,N});

    while (!pq.empty()){
        int time = pq.top().first;
        int n = pq.top().second;
        pq.pop();

        visited[n]=true;

        if (n==K) {
            cout << time << '\n';
            break;
        }

        if (n-1>=0 && !visited[n-1]){
            pq.push({time+1, n-1});
        }
        if (n+1<=100000 && !visited[n+1]){
            pq.push({time+1, n+1});
        }
        if (2*n<=100000 && !visited[n*2]){
            pq.push({time+1, 2*n});
        }
    }


    return 0;
}