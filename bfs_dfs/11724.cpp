#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M,u,v;
vector <int> map[1001];
queue <int> q;
bool visited[1001]={false,};
int cnt=0;

void bfs(int a){
   q.push(a);
   visited[a]=true;

   while (!q.empty()){
       int x = q.front();
       q.pop();

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

    cin >> N >> M;
    for (int i=0;i<M;i++){
        cin >> u >> v;
        map[u].push_back(v); map[v].push_back(u);
    }

    for (int i=1;i<=N;i++){
        if (!visited[i]){
            bfs(i);
            cnt++;
        }

    }
    cout << cnt;

    return 0;
}