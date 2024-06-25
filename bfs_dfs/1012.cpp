/*
 * *** solution ***
 * 1. 1은 배추가 심어져 있는 땅
 * 2. 배추가 뭉덩이를 찾으면 됨
 *
 */

#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int T, M, N, K;
int a, b;

queue <pair<int,int>> q;
int map[51][51];
bool visited[51][51];

void bfs(int j, int i){
    q.push({j,i});
    visited[j][i]=true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nx<0 || nx>=N || ny<0 || ny>=M) continue;

            if (map[ny][nx]==1 && !visited[ny][nx]){
                visited[ny][nx]=true;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--){
        map[51][51]={0,};
        visited[51][51] = {false,};
        cin >> M >> N >> K;

        for (int i=0;i<K;i++){
            cin >> a >> b;
            map[b][a]=1;
        }

        int result=0;
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (map[j][i]==1 && !visited[j][i]) {
                    bfs(j,i);
                    result++;
                }
            }
        }
        cout << result <<'\n';
    }

    return 0;
}
