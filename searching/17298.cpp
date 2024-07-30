#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector <int> v(N);

    for (int i=0;i<N;i++){
        cin >> v[i];
    }

    int size = v.size()-1;
    for (int i=0;i<N;i++){
        int flag = false;
        int cur = v[i];

        for (int j=i;j<N;j++){
            if (cur < v[j+1]){
                cout << v[j+1] << " ";
                flag = true;
                break;
            }
        }

        if (i == size || !flag){
            cout << "-1 ";
        }
    }
    cout << '\n';

    return 0;
}
