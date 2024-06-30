#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector <int> map[101];
bool visited[101]={false,};
int cnt=0;

void dfs(int x){
    visited[x]=true;

    for (int i=0;i<map[x].size();i++){
        if (!visited[map[x][i]]){
            dfs(map[x][i]);
            cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> M;

    int a,b;
    for (int i=0;i<M;i++){
        cin >> a >> b;
        map[a].push_back(b); map[b].push_back(a);
    }

    dfs(1);
    cout << cnt;

    return 0;
}