#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string map[26];
queue<pair<int,int>> q;
bool visited[26][26]={false,};
vector <int> result;

// 좌우상하
int dx[4]={1,-1,0,0,};
int dy[4]={0,0,1,-1};

void bfs(int x,int y){
    int land_size=1;
    q.push({x,y});
    visited[x][y]=true;

    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if (nx<0 || ny<0 || nx>N || ny>N) continue;

            if (!visited[nx][ny] && map[nx][ny]=='1'){
                q.push({nx,ny});
                visited[nx][ny]=true;
                land_size++;
            }
        }
    }
    result.push_back(land_size);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    // 문자열이기 때문에 줄 단위 입력받기
    for (int i=0;i<N;i++){
        cin >> map[i];
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (map[i][j]=='1' && !visited[i][j]) {
                bfs(i,j);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int i=0;i<result.size();i++){
        cout << result[i] << '\n';
    }

    return 0;
}