//
// 입력
// - 용액의 수 N (2 ~ 100,000)
// - 용액의 특성값
// 출력
// - 0에 가까운 값을 만드는 두 용액의 특성값
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,a;
vector<int> v;
vector<int> answer(2);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i=0;i<N;i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int s=0,e=N-1;
    long long zero=2000000000L;
    while (s < e){ // s<=e으로 조건을 했을 땐 틀림
        long long sum = (long long)v[s] + (long long)v[e];

        if (abs(sum) < zero){
            zero = abs(sum);
            answer.clear();
            answer.push_back(v[s]);
            answer.push_back(v[e]);
        }

        if (sum<0) s++;
        else e--;

    }

    for (int i=0;i<2;i++){
        cout << answer[i] << " ";
    }

    return 0;
}
