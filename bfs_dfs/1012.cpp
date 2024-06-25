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

void bfs(int x, int y){
    q.push({x,y});

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx<0 || nx>=M || ny<0 || ny>=N) continue;

            if (map[nx][ny]==1 && !visited[nx][ny]){
                visited[nx][ny]=true;
                q.push({nx, ny});
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
            map[a][b]=1;
        }

        int result=0;
        for (int i=0;i<M;i++){
            for (int j=0;j<N;j++){
                if (map[i][j]==1 && visited[i][j]==false) {
                    bfs(i,j);
                    result++;
                }
            }
        }
        cout << result <<'\n';
    }

    return 0;
}
