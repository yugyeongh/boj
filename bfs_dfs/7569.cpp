// 3차원 자료구조 사용하기
// 흑흑

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,M,H;
int tomato;
vector <vector <vector<int>>> box;
bool visited[101][101][101]={false,};
queue <pair<int, pair<int,int>>> q;

int dx[6]={-1,1,0,0,0,0};
int dy[6]={0,0,0,0,-1,1};
int dz[6]={0,0,-1,1,0,0};

void bfs(int c, int a, int b){
    q.push({c,{a,b}});
    visited[c][a][b]=true;

    while (!q.empty()){
        int z = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for (int i=0;i<6;i++){
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx<0 || ny<0 || nz<0 || nx>=N || ny>=M || nz>=H) continue;
            if (box[nz][nx][ny]==0){
                q.push({nz,{nx,ny}});
                box[nz][nx][ny]= box[z][x][y]+1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> H;
    for (int k=0;k<H;k++){
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                cin >> tomato;
                box[k][i][j]=tomato;
            }
        }
    }

    for (int k=0;k<H;k++){
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (box[k][i][j]==1){
                    bfs(k,i,j);
                }
            }
        }
    }

    int max=0;
    for (int k=0;k<H;k++){
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (box[k][i][j]==1 && box[k][i][j]>max){
                    max = box[k][i][j];
                } else {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    return 0;
}