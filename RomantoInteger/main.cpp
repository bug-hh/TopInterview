//
//  main.cpp
//  RomantoInteger
//
//  Created by 彭豪辉 on 2020/7/5.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

/*
 而这道题好就好在没有让我们来验证输入字符串是不是罗马数字，这样省掉不少功夫。需要用到 HashMap 数据结构，来将罗马数字的字母转化为对应的整数值，因为输入的一定是罗马数字，那么只要考虑两种情况即可：
 第一，如果当前数字是最后一个数字，或者之后的数字比它小或等于它的话，则加上当前数字。
 第二，其他情况则减去这个数字。
 */
int romanToInt(string s) {
    unordered_map<char, int> m {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int len = (int)s.size();
    int ret = 0;
    for (int i = 0; i < len; i++) {
        if (i == len - 1 || m[s[i+1]] <= m[s[i]]) {
            ret += m[s[i]];
        } else {
            ret -= m[s[i]];
        }
    }
    return ret;
}
