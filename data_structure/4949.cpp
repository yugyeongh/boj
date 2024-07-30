#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        string input;
        getline(cin, input);

        if (input == ".") break;

        stack<char> str;
        bool flag=0;

        for (int i=0;i<input.length();i++){
            char c = input[i];

            if ((c=='(') || (c=='[')) str.push(c);
            else if (c==')') {
                 if (!str.empty() && str.top()=='(') str.pop();
                 else {
                     flag=1;
                     break;
                 }
            } else if (c==']'){
                if (!str.empty() && str.top()=='[') str.pop();
                else {
                    flag=1;
                    break;
                }
            }
        }

        if (flag==0 && str.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}
