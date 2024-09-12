/*
 * 입력: 수열의 길이 N, 부분합 S, 수열
 * 출력: S의 최소 길이 (불가능하다면 0 출력)
 *
 * 풀이1
 * 1. 어떤 자료구조를 이용할까? - 벡터 (bc, 부분합의 시작 인덱스를 기억하고 불가능하면 바로 현재부터 다시 인덱스를 기억하면 됨)
 * 2. v[i] 자체를 넣지 않고 v[i]=v[i]+v[i-1]을 저장할까? 5 6 9 14 24 31 35 44 46 54
 * 3. v[start]-v[end]가 (1) <S면 end++, (2) > S면 start++, (3) 같으면 result 업데이트하고 start++
 *
 * 풀이2 - 71프로에서 틀...
 * 1. 숫자 있는 그대로 배열에 저장하기
 * 2. sum >= S면 가장 짧은 길이 저장&&sum-=arr[start]&&start++, end==N면 break, 그 외면 sum+=arr[end]&&end++
 */


#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    int arr[N];
    for (int i=0;i<N;i++){
        cin >> arr[i];
    }

    int start=0, end=0, sum=0, result=0x7FFFFFF;
    while (start <= end){
        if (end == N) break;
        else if (sum >= S){
            result = min(result, end - start);
            sum -= arr[start++];
        } else {
            sum += arr[end++];
        }
    }

    if (result == 0x7FFFFFF) cout << 0 << '\n';
    else cout << result << '\n';

    return 0;
}
