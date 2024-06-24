#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 26

int N, cnt;
string map[MAX];
queue<pair<int,int>> q;
bool v[MAX][MAX]={false,};
vector <int> result;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x,int y){
    cnt=0;
    q.push({x,y});
    v[x][y] = true;
    cnt++;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i=0;i<4;i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (0<=nx && 0<=ny && nx<N && ny<N && v[nx][ny]==false && map[nx][ny]=='1') {
                q.push({nx, ny});
                v[nx][ny]= true;
                cnt++;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i=0;i<N;i++){
        cin >> map[i];
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (map[i][j]=='1' && v[i][j]==false) {
                bfs(i,j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(),result.end());

    cout << result.size() << "\n";
    for (int i=0;i<result.size();i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
