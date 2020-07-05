//
//  main.cpp
//  LongestSubstringWithoutRepeatingCharacters
//
//  Created by bughh on 2020/6/30.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s);

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}

int lengthOfLongestSubstring(string s) {
    int m[256];
    memset(m, -1, 256 * sizeof(int));
    int left = -1;
    int ret = 0, temp = 0;
    int len = (int)s.size();
    for (int i = 0 ;i < len; i++) {
        if (m[s[i]] >= 0 && m[s[i]] > left) {
            left = m[s[i]];
        }
        m[s[i]] = i;
        temp = i - left;
        ret = temp > ret ? temp : ret;
    }
    
    return ret;
}
