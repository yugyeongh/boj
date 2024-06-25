/*
 * *** solution ***
 * 1. 가장 짧은 다리 -> bfs로 풀자
 * 2. 0은 바다, 1은 육지
 * 3. 가장 짧은 다리는 3임 2나 1은 안 됨
 * 4. pq로 오름차순 정리해서 가장 짧은 다리 길이 구하려고 했는데 이전까지 만들어진 다리 길이에 1더하는거라 pq로 찾기 어려워서 자료구조를 배열로 사용해봄
 * 5. 상하좌우를 비교해서 가장 큰 값에 1을 더해 bridge[nx][ny]를 만들어야 함
 */

#include <iostream>
#include <queue>
using namespace std;

int N;
int map[101][101];
bool visited[101][101]={false,};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

queue<pair<int,int>> q;
int bridge[101][101]={0,};

void bfs(int x,int y) {
    q.push({x,y});
    int max = 0;

    while (!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();


        for (int i=0;i<4;i++){
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx<0 || nx>=N || ny<0 || ny>=N) continue;

            if (bridge[nx][ny]>max) max = bridge[nx][ny];

            if (map[nx][ny]==0 && visited[x][y]==false){
                bridge[x][y]=max+1;
                visited[x][y]=true;
            }

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (map[i][j]==1 && visited[i][j]==false) bfs(i,j);
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << bridge[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
