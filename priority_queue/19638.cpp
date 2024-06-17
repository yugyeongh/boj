/*
 * *** logic ***
 * 1. 뿅망치 맞으면 h/2가 됨
 * 2. h==1, 뿅망치 영향x
 *
 * *** Input ***
 * 1. 인구수 N, 센티의 키 H, 뿅망치 횟수 T
 * 2. 각 거인의 키 H
 *
 * *** Output ***
 * 1. all H < Hcenti, print yes and 최소 뿅망치 횟수
 * 2. T<0, print no and taller one
 *
 * *** Constraint ***
 * 1. integer range - 1 ≤ N, T ≤ 10^5, 1 ≤ Hcenti, H ≤ 2 * 10^9
 * 2. T를 최소한으로 사용하기
 * 3. Hcenti == H -> No로 출력
 * 4. 나머지는 버리기
 *
 * *** Solution - using pq  ***
 * 1. descending sort
 *
 * *** submit1 - 바로 틀렸습니다 나옴 ***
 * 1. 테케는 다 통과인데 왜 틀릴까
 * 2. 진정한 맞왜틀
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Hcenti, T;
    cin >> N >> Hcenti >> T;

    priority_queue <int, vector<int>, less<int>> pq;
    int cnt=0;

    for (int i=0;i<N;i++) {
        int H;
        cin >> H;
//        while (cnt<T) {
//            if (H==1) break;
//            if (H < Hcenti) break;
//            if (H >= Hcenti) H = H/2; cnt++;
//        }
        pq.push(H);
    }

    for (int i=0;i<T;i++) {
        int h = pq.top();

        while (cnt<T) {
            if (h==1) break;
            if (h < Hcenti) break;
            if (h >= Hcenti) h = h/2; cnt++;
        }
    }


    for (int i=0;i<N;i++){
        if (Hcenti <= pq.top()){
            cout << "NO" << '\n';
            cout << pq.top();
            return 0;
        } else {
            pq.pop();
        }
    }

    if (pq.empty()) {
        cout << "YES" << '\n';
        cout << cnt;
        return 0;
    }

}