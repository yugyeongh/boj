/*
 * *** logic ***
 * 1. x == 자연수 -> 배열에 x 값 추가
 * 2. x == 0 -> 배열에서 가장 큰 값 출력 및 pop
 *
 * *** Input ***
 * 1. 연산의 개수 n
 * 2. 연산에 대한 정수 x
 *
 * *** Output ***
 * 1. 0의 개수만큼 답 출력
 * 2. array.isEmpty() -> 0 출력
 *
 * *** Constraint ***
 * 1. x는 자연수
 * 2. x < 2^31
 *
 * *** Solution ***
 * 1. using pq, compared elements with less<int>
 *
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, less<int> > pq;

    while (n--){
        int x;
        cin >> x;

        if (x==0){
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}
