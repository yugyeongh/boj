/*
 * 입력: 수열의 길이 N, 부분합 S, 수열
 * 출력: S의 최소 길이 (불가능하다면 0 출력)
 *
 * 풀이1
 * 1. 어떤 자료구조를 이용할까? - 벡터 (bc, 부분합의 시작 인덱스를 기억하고 불가능하면 바로 현재부터 다시 인덱스를 기억하면 됨)
 * 2. v[i] 자체를 넣지 않고 v[i]=v[i]+v[i-1]을 저장할까? 5 6 9 14 24 31 35 44 46 54
 * 3. v[start]-v[end]가 (1) <S면 end++, (2) > S면 start++, (3) 같으면 result 업데이트하고 start++
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    int temp;
    vector <int> v(N);
    cin >> v[0];
    for (int i=1;i<N;i++){
        cin >> temp;
        v[i] = v[i-1]+temp;
    }

    int start=0, end=0, result=0x7FFFFFF;
    while (start <= end){
        if (end == N) break;

        if (v[end]-v[start] < S){
            end++;
        } else if (v[end]-v[start] > S){
            start++;
        } else if (v[end]-v[start] == S){
            result = min(result, end-start);
            start++;
        }
    }

    if (result == 0x7FFFFFF) cout << 0 << '\n';
    else cout << result << '\n';

    return 0;
}
