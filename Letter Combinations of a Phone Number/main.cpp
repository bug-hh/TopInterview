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

void dfs(string & s, string & digits, vector<string> & ret, int level, string *map);
vector<string> letterCombinations(string digits);

int main(int argc, const char * argv[]) {
    // insert code here...
    string digits = "";
    vector<string> ret = letterCombinations(digits);
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
    return 0;
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
        return {};
    }
    
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
    string s = "";
    dfs(s, digits, ret, 0, map);
    return ret;
}

void dfs(string & s, string & digits, vector<string> & ret, int level, string *map) {
    if (level == digits.size()) {
        ret.push_back(s);
        return;
    }
    string temp = map[digits[level] - '0'];
    int len = (int)temp.size();
    for (int i = 0; i < len; i++) {
        s.push_back(temp[i]);
        dfs(s, digits, ret, level + 1, map);
        s.pop_back();
    }
}
