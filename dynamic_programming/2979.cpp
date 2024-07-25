/*
 * *** solution ***
 * 1. 주차 대란
 * 2. 1차원 배열 사용하자
 */

#include <iostream>
using namespace std;

int A, B, C;
int s,e;
int arr[101]={0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> C;

    for (int i=0;i<3;i++){
        cin >> s >> e;
        for (int j=s;j<e;j++){
            arr[j]++;
        }
    }

    int result=0;
    for (int i=0;i<100;i++){
        if (arr[i]==1) result = result + A;
        else if (arr[i]==2) result = result + B*2;
        else if (arr[i]==3) result = result + C*3;
    }

    cout << result << '\n';

    return 0;
}
