#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,M,V;
int a,b;
vector <int> map[1001];
bool visited[1001]={false,};
vector <int> result_bfs;
vector <int> result_dfs;

void dfs(int x){
    vector <int> v;
    visited[x]=true;
    result_dfs.push_back(x);

    for (int i=0;i<map[x].size();i++){
        if (!visited[map[x][i]]){
            dfs(map[x][i]);
        }
    }
}

void bfs(int i){
    queue <int> q;
    q.push(i);
    visited[i] = true;

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

    for (int i=0;i<M;i++){
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    dfs(V);
    for (int i=0;i<result_dfs.size();i++){
        cout << result_dfs[i] << " ";
    }
    cout << '\n';

    memset(visited, false, sizeof(visited));

    bfs(V);
    for (int j=0;j<result_bfs.size();j++){
        cout << result_bfs[j] << " ";
    }
    cout << '\n';

    return 0;
}
