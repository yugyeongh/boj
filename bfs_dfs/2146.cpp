/*
 * *** solution ***
 * 1. 가장 짧은 다리 -> bfs로 풀자
 * 2. 0은 바다, 1은 육지
 * 3. 가장 짧은 다리는 3임 2나 1은 안 됨
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
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

void bfs(int x,int y) {
    q.push({x,y});

    while (!q.empty()){
        int cnt=0;
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                int nx = a + dx[i];
                int ny = b + dy[i];

                if (nx<0 || nx>=N || ny<0 || ny>=N) continue;

                if (map[nx][ny]==0 && visited[nx][ny]==false){
                    pq.push({++cnt,{nx,ny}});
                    visited[nx][ny]=true;
                }
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

    for (int i=0;i<pq.size();i++){
        cout << pq.top().first << '\n';
        pq.pop();
    }

    cout << pq.top().first << '\n';

    return 0;
}
