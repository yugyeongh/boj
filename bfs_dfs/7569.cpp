// 3차원 자료구조 사용하기
// 흑흑
// 인덱스가 제일 헷갈린다🫥

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M,N,H; // 가로, 세로, 높이
int box[101][101][101];
int day[101][101][101]={-1,};
queue <pair<pair<int,int>, int>> q;

int dx[6]={-1,1,0,0,0,0};
int dy[6]={0,0,0,0,-1,1};
int dz[6]={0,0,-1,1,0,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> H; // 가로, 세로, 높이

    for (int k=0;k<H;k++){
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                cin >> box[i][j][k];
                day[i][j][k]=-1;
                if (box[i][j][k]==1){
                    q.push({{i,j},k});
                    day[i][j][k]=0;
                }
            }
        }
    }

    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();

        for (int i=0;i<6;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nz = z+dz[i];

            if (nx<0 || ny <0 || nz<0 || nx>=N || ny>=M || nz>=H) continue;
            if (box[nx][ny][nz]==0 && day[nx][ny][nz]==-1){ // 안 익은 토마토 && 방문 x
                q.push({{nx,ny},nz});
                day[nx][ny][nz] = day[x][y][z]+1;
            }
        }
    }

    int ans=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            for (int k=0;k<H;k++){
                if (box[i][j][k]==0 && day[i][j][k]==-1){ // 안 익은 토마토 && 방문x
                    ans=-1;
                    break;
                }
                if (ans<day[i][j][k]) ans=day[i][j][k];
            }
            if (ans==-1) break;
        }
        if (ans==-1) break;
    }

    cout << ans;

    return 0;
}