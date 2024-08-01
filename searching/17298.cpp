#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000001
using namespace std;

int N;
int arr[MAX]={0,};
int nge[MAX]={0,};
stack <int> s;

// 스택에 뭘 넣을지 1. 자기보다 큰 수를 넣을지 2. 큰 수의 인덱스를 넣을지 고민해야 하는데
// 보통 인덱스를 넣음
// 지기보다 큰 수가 없을 때까지 작은 수를 다 빼고 큰 수만 바라보게 함
// 앞서 들어온 수가 작으면 뒤에 있는 수를 삭제해야함
// 쏙속 이해됨
// 6549 비슷한 문제임

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    for (int i=0;i<N;i++) {
        while (!s.empty() && arr[s.top()]<arr[i]) {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        nge[s.top()] = -1;
        s.pop();
    }

    for (int i=0;i<N;i++){
        cout << nge[i] << " ";
    }

    return 0;
}
