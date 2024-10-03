// 시간초과
// 소요 시간: 40분
//
// 입력
// - 첫째줄: 전체 용액의 수 N (3<=N<=5000)
// - 둘째줄: 용액의 특성값 (-10^9 ~ 10^9)
// 출력: 특성값을 0에 가깝게 만드는 세 용액의 특성값 출력 (오름차순으로)
//
// 풀이
// - 주어진 용액의 특성값을 정렬하고 투포인터를 사용해 구하자!
// - 3개의 용액이니 3개의 지점을 가리켜야함
// - if sum<0, second를 오른쪽으로 옮겨 큰 수를 가리키도록 하고
// - if sum>0, third를 왼쪽으로 옮겨 작은 수를 가리키도록 함
// - 0에 가까운 합을 어떻게 찾아낼까 -> 절대값
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define INF 987654321
using namespace std;

int N;
vector <int> v;
vector <int> answer(3);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int a;
    for (int i=0;i<N;i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    long long zero=3000000000L;
    long long sum=0;
    for (int first=0;first<N-2;first++){
        int second = first+1;
        int third = N-1;

        while (second < third){
            sum = (long long)v[first] + (long long)v[second] + (long long)v[third];

            if (abs(sum) < zero){
                zero = abs(sum);
                answer.clear();
                answer.push_back(v[first]);
                answer.push_back(v[second]);
                answer.push_back(v[third]);
            }

            if (sum < 0) second++;
            else third--;
        }
    }

    for (int i=0;i<3;i++){
        cout << answer[i] << " ";
    }

    return 0;
}
