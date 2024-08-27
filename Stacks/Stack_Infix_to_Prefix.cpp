#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            res += s[i];
        }
        else if (s[i] == ')') {
            st.push(s[i]);
        }
        else if (s[i] == '(') {
            while (!st.empty() && st.top() != ')') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else {  // Handle operators
            while (!st.empty() && prec(st.top()) > prec(s[i])) {
                res += st.top();
                st.pop();
            }
            if (st.empty() || s[i] != '^' || st.top() != '^') {
                st.push(s[i]);
            }
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string expression = "(a-b/c)*(a/k-l)";
    cout << "Prefix: " << infixToPrefix(expression) << endl;
    return 0;
}
