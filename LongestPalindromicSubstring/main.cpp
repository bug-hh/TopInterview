//
//  main.cpp
//  LongestPalindromicSubstring
//
//  Created by bughh on 2020/7/1.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void searchString(string & s, int i, int j, int & start, int & maxLen);
string longestPalindrome(string s);

int main(int argc, const char * argv[]) {
    // insert code here...
    string ret = longestPalindrome("cbbd");
    cout << ret << endl;
    return 0;
}

string longestPalindrome(string s) {
    int len = (int)s.size();
    if (len < 2) {
        return s;
    }
    int start = 0, maxLen = 0;
    for (int i = 0; i < len - 1; i++) {
        searchString(s, i, i, start, maxLen);
        searchString(s, i, i + 1, start, maxLen);
    }
    return s.substr(start, maxLen);
    
}

void searchString(string & s, int i, int j, int & start, int & maxLen) {
    int len = (int)s.size();
    while (i >= 0 && j < len && s[i] == s[j]) {
        i--;
        j++;
    }
    
    if (j - i - 1 > maxLen) {
        maxLen = j - i - 1;
        start = i + 1;
    }
}
