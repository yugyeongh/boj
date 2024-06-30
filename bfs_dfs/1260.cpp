#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,V;
int a,b;
vector <int> map[1001];
bool visited[1001]={false,};
vector <int> result_bfs;
vector <int> result_dfs;

void dfs(int x){
    visited[x]=true;
    result_dfs.push_back(x);

    for (int i=0;i<map[x].size();i++){
        if (!visited[map[x][i]]){
            dfs(map[x][i]);
        }
    }
}

void bfs(int x){
    queue <int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty()){
        int x = q.front();
        q.pop();
        result_bfs.push_back(x);

        for (int i=0;i<map[x].size();i++){
            if (!visited[map[x][i]]){
                q.push(map[x][i]);
                visited[map[x][i]]=true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> V;

    // 정점 번호 저장할 때 0부터 하면 틀렸습니다 나옴
    for (int i=1;i<=M;i++){
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    // 정점 번호가 작은 것부터 방문하기 때문에 오름차순 정렬
    for (int i=1;i<=N;i++){
        sort(map[i].begin(), map[i].end());
    }


    dfs(V);
    memset(visited, false, sizeof(visited));
    bfs(V);

    for (int i=0;i<result_dfs.size();i++){
        cout << result_dfs[i] << " ";
    }
    cout << '\n';

    for (int j=0;j<result_bfs.size();j++){
        cout << result_bfs[j] << " ";
    }

    return 0;
}
