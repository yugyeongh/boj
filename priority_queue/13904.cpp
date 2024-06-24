/*
 * *** logic ***
 * 1.
 *
 * *** Input ***
 * 1.
 *
 * *** Output ***
 * 1.
 *
 * *** Constraint ***
 * 1.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    if (a.second > b.second) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int arr[1001];
    cin >> N;

    memset(arr, 0, sizeof(arr));
    vector <pair<int,int>> v(N);

    for (int i=0;i<N;i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    for (int i=0;i<N;i++) {
        for (int j=v[i].first;j>0;j--){
            if (arr[j]==0) {
                arr[j]=v[i].second;
                break;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= 1000; i++)
        res += arr[i];
    cout << res;

    return 0;
}
