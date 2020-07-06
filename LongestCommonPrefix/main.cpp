//
//  main.cpp
//  LongestCommonPrefix
//
//  Created by bughh on 2020/7/6.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    string ret = "";
    int len1 = (int)strs.size();
    int len2 = (int)strs[0].size();
    for (int i = 0; i < len2; i++) {
        char c = strs[0][i];
        for (int j = 1; j < len1; j++) {
            if (i >= strs[j].size() || strs[j][i] != c) {
                return ret;
            }
        }
        ret.push_back(c);
    }
    return ret;
}
