// 시간초과
// 소요 시간: 40분
//
// 입력
// - 첫째줄: 전체 용액의 수 N (3<=N<=5000)
// - 둘째줄: 용액의 특성값 (-10^9 ~ 10^9)
// 출력: 특성값을 0에 가깝게 만드는 세 용액의 특성값 출력 (오름차순으로)
//
// 풀이
// - 주어진 용액의 특성값을 정렬하고 투포인터를 사용해 구하자! -> 사용했었으나 잘 안풀려서 3중 for문 씀
// - 3개의 용액이니 3개의 지점을 가리켜야함
// - 0에 가까운 합을 어떻게 찾아낼까 -> 절대값
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define INF 987654321
using namespace std;

int N;
int zero=INF;
vector <int> v;
vector <int> answer;

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


    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            for (int k=j+1;k<N;k++){
                int sum = v[i] + v[j] + v[k];

                if (abs(sum) <= abs(zero)){
                    answer.clear();
                    answer.push_back(v[i]);
                    answer.push_back(v[j]);
                    answer.push_back(v[k]);
                    zero = sum;
                }
            }
        }
    }

    for (int i=0;i<3;i++){
        cout << answer[i] << " ";
    }

    return 0;
}
