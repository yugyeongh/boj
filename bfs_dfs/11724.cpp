#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M,u,v;
vector <int> map[1001];
queue <int> q;
bool visited[1001]={false,};
int cnt=0;

void dfs(int a){
    visited[a]=true;

    for (int i=0;i<map[a].size();i++){
        if (!visited[map[a][i]]){
            dfs(map[a][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i=0;i<M;i++){
        cin >> u >> v;
        map[u].push_back(v); map[v].push_back(u); // 방향 없는 그래프니까,, 양방향이잖아..ㅠ
    }

    for (int i=1;i<=N;i++){
        if (!visited[i]){
            dfs(i);
            cnt++;
        }

    }
    cout << cnt;

    return 0;
}