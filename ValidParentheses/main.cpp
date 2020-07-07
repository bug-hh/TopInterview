//
//  main.cpp
//  ValidParentheses
//
//  Created by bughh on 2020/7/7.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

bool isValid(string s) {
    if (s.empty()) {
        return true;
    }
    
    stack<char> st;
    int len = (int)s.size();
    int i = 0;
    for (i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                break;
            }
        } else if (c == '}') {
            if (!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                break;
            }
        } else if (c == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                break;
            }
        }
    }
    
    return st.empty() && i == len;
}
