/*
 * *** logic ***
 * 1. 걷기는 +1초 후에 1 or -1
 * 2. 순간이동은 0초 후에 2*x
 *
 * *** Input ***
 * 1. 수빈 위치 N, 동생 위치 K
 *
 * *** Output ***
 * 1. 수빈이가 동생을 찾는 가장 빠른 시간
 *
 * *** Constraint ***
 * 1. 0 ≤ N, K ≤ 100,000
 *
 * *** Solution ***
 * 1. 흠
 *
 */

#include <iostream>
#include <queue>
using namespace std;

bool v[100001] = {false,};
queue <int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    q.push(N);

    int seg=1, cnt, ans=0;
    while (!q.empty()) {
        bool flag=false;
        cnt=0;

        for (int i=0;i<seg;i++){
            int x = q.front();
            q.pop();

            if (x==K) {
                cout << ans << '\n';
                return 0;
            }
            v[x] = true;

            if (x-1>=0 && !v[x-1]) {
                q.push(x-1);
                cnt++;
                flag = true;
            }

            if (x+1<=100000 && !v[x+1]) {
                q.push(x+1);
                cnt++;
                flag = true;
            }

            if (2*x<=100000 && !v[2*x]) {
                q.push(2*x);
                cnt++;
            }
        }
        seg = cnt;
        if (flag) ans++;
    }
    cout << ans << '\n';
    return 0;
}
