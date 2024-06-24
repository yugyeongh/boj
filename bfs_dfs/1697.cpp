/*
 * *** logic ***
 * 1. 걸을 때 1초 후에 -1 or +1
 * 2. 순간이동할 때 1초 후에 2*x
 *
 * *** Input ***
 * 1. 수빈 위치 N, 동생 위치 K
 *
 * *** Output ***
 * 1. 수빈이가 동생을 찾는 가장 빠른 시간
 *
 * *** Solution ***
 * 1. bfs를 사용하자 최단 거리를 찾아야 하기 때문
 *
 */

#include <iostream>
#include <queue>
using namespace std;

bool visited[100001] = {false};
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    q.push(N);

    int seg=1, cnt, ans=0;
    bool flag = false;
    while (!q.empty()){
        cnt = 0;
        for (int i=0;i<seg;i++){
            int x = q.front();
            q.pop();

            if (x==K) {
                cout << ans << '\n';
                return 0;
            }
            visited[x] = true;

            if (x+1 <= 100000 && !visited[x+1]){
                q.push(x+1);
                cnt++;
                flag = true;
            }

            if (x-1 >=0  && !visited[x-1]){
                q.push(x-1);
                cnt++;
                flag = true;
            }

            if (2*x <= 100000 && !visited[2*x]){
                q.push(2*x);
                cnt++;
                flag = true;
            }
        }
        seg = cnt; // 이게 포인트라고 조심스레 생각합니다
        if (flag) ans++;

    }
    cout << ans << '\n';
    return 0;
}
