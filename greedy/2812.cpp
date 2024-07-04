/*
 * *** solution ***
 * 1. 숫자를 어떤 기준으로 지울까나
 * 2. 오름차순 정렬해서 작은 순대로 자르는게 좋을듯
 * 3. 숫자, 숫자 위치 기준으로 정렬하자
 * 4. 마지막 테케 출력이 다르네
 * 5. deque 사용하기
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,K;
char num[500001];
vector <pair<int,int>> v;
priority_queue <int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    cin >> num;

    deque <int> dq;
    for (int i=0;i<N;i++){
        while (K>0 && !dq.empty() && dq.back()<num[i]){
            dq.pop_back();
            K--;
        }
        dq.push_back(num[i]);
    }

    for (int i=0;i<dq.size()-K;i++){
        cout << (char)dq[i];
    }

    return 0;
}
