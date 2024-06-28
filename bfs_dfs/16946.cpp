#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M;
string map[1001];
bool visited[1001][1001]={false,};
queue <pair<int,int>> q;
int result[1001][1001];
vector <pair<int,int>> wall;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void bfs(int x, int y){
    int empty=1;
    q.push({x,y});

    if (map[x][y]=='1' && !visited[x][y]) wall.push_back({x,y});
    visited[x][y]=true;

    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if (nx<0 || ny<0 || nx>=N || ny>=M) continue;

            if (map[nx][ny]=='1' && !visited[nx][ny]){
                wall.push_back({nx,ny});
            } else if (map[nx][ny]=='0' && !visited[nx][ny]){
                q.push({nx,ny});
                empty++;
            }
            visited[nx][ny]=true;
        }
        for (int i=0;i<wall.size();i++){
            cout << wall[i].first << " " << wall[i].second << '\n';
        }
        cout << '\n';
    }
    for (int i=0;i<wall.size();i++){
        int a = wall[i].first;
        int b = wall[i].second;

        result[a][b] +=  empty;
//        cout << a << " " << b << '\n';
//        cout << empty << '\n';
//        cout << result[a][b] << '\n';
//        visited[a][b]=false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i=0;i<N;i++){
        cin >> map[i];
    }

    memset(result, 0, sizeof(result));

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (map[i][j]=='1' && !visited[i][j]){
                bfs(i,j);
            }
        }
    }

    for (int i=0;i<wall.size();i++){
        cout << wall[i].first << " " << wall[i].second << '\n';
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cout << result[i][j]%10;
        }
        cout << '\n';
    }

    return 0;
}