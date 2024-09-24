/*
 * 입력: 영단어 개수 N '\n' 서로 다른 영단어
 * 출력: 접두사가 같은 단어 두 개 (단, 앞쪽에 있는 단어 우선 출력 || 같은 단어는 x)
 * 알고리즘: 문자열, 자료구조
 */

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N, max_length=0, max_prefix_order = 1e9;
string max_prefix;
string arr[20010];
map <string, vector<int>> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i=0;i<N;i++){
        cin >> arr[i];

        string temp="";
        for (int j=0;j<arr[i].size();j++){
            temp += arr[i][j];
            m[temp].push_back(i);

            if (m[temp].size()>1 &&  max_length<temp.length()){
                max_length = temp.length();
            }
        }

        for(const auto& [key, value] : m){
            if(value.size()>=2 && key.length()==max_length){
                if(value[0] < max_prefix_order){
                    max_prefix_order = value[0];
                    max_prefix = key;
                }
            }
        }
    }

    cout << arr[m[max_prefix][0]] << "\n";
    cout << arr[m[max_prefix][1]];

    return 0;
}
