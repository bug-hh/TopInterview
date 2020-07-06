//
//  main.cpp
//  Letter Combinations of a Phone Number
//
//  Created by bughh on 2020/7/6.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(string & s, string & source, vector<string> &ret, int start, int len);

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "abc";
    vector<string> v;
    v.push_back(s);
    s.pop_back();
    cout << s << endl;
    cout << v[0] << endl;
    return 0;
}

vector<string> letterCombinations(string digits) {
    string map[10] {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> ret;
    
    return ret;
}

void dfs(string & s, string & source, vector<string> & ret, int start, int len) {
    if (start >= len) {
        ret.push_back(s);
        return;
    }
    for (start = 0; start < len; start++) {
        s.push_back(source[start]);
        dfs(s, source, ret, start + 1, len);
        s.pop_back();
    }
}
