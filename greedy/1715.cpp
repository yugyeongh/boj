/*
 * *** solution ***
 * 1. 그냥 오름차순 정렬해서 더하면 되는거 아님? -> 아니었다고 한다..
 * 2. pq 사용해서 현재 남아있는 가장 작은 두 수만 더하면 될 듯
 */

#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue <int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int t;
    for (int i=0;i<N;i++){
        cin >> t;
        pq.push(t);
    }

    int sum=0;
    while (pq.size()>1){ // !pq.empty()로 작성했다가 변경
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum += (a+b);
        pq.push(a+b);
    }

    cout << sum;

    return 0;
}