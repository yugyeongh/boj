/*
 * *** solution ***
 * 1. 숫자를 어떤 기준으로 지울까나
 * 2. 오름차순 정렬해서 작은 순대로 자르는게 좋을듯
 * 3. 숫자, 숫자 위치 기준으로 정렬하자
 * 4. 마지막 테케 출력이 다르네
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,K;
string num;
vector <pair<int,int>> v;
priority_queue <int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    cin >> num;

    for (int i=0;i<num.size();i++){
        v.push_back({num[i], i});
    }

    sort(v.begin(), v.end());

    for (int i=K;i<v.size();i++){
        int j = v[i].second;
        pq.push(j);
    }

    while (!pq.empty()){
        int t = pq.top();
        pq.pop();
        cout << num[t];
    }


    return 0;
}
