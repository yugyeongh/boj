/*
 * *** solution ***
 * 1. 문자열 뒤에 A 추가
 * 2. 문자열 뒤집고 뒤에 B 추가
 * 3. T에서 하나씩 줄여나가자
 * -> 그리디인 이유: 이전 결정과 뒤의 결정은 독립적이기 때문에 그리디다!? 무조건 답이 된다는 보장이 있어서 그리디다!
 * 그리디 알고리즘 | 매 단계마다 최적의 선택을 하면 최종적으로 최적에 도달할 수 있는 것
 */

#include <iostream>
#include <algorithm>
using namespace std;

string S,T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> T;

    int result = 0;
    while (1){
        if (S.size()==T.size()) {
            if (S == T) result = 1;
            break;
        }

        if (T[T.size()-1]=='A') T.pop_back();
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    cout << result;

    return 0;
}