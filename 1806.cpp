/*
 * 입력: 수열의 길이 N, 부분합 S \n 수열
 * 출력: 부분합의 최소 길이
 * 풀이: 투포인터
 */

#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int N, S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    int arr[N];


    for (int i=0;i<N;i++){
        cin >> arr[i];
    }

    int s=0, e=0, sum=0, result=MAX;
    while (s <= e){
        if (sum >= S){
            if (sum == S) result = min(result, e-s);
            s++;
            sum -= arr[s];
        } else if (sum < S){
            e++;
            sum += arr[e];
        }
    }

    if (result==MAX) cout << 0 << '\n';
    else cout << result << '\n';

    return 0;
}
