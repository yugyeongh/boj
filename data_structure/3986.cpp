#include <iostream>
#include <stack>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int ans=0;
    while (N--){
        stack <char> s;
        string word;
        cin >> word;

        for (int i=0;i<word.length();i++){
            if (s.empty()){
                s.push(word[i]);
            } else {
                if (s.top() == word[i]) s.pop();
                else s.push(word[i]);
            }
        }

        if (s.empty()) ans++;
    }
    cout << ans;
    return 0;
}
