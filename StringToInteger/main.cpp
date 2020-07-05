//
//  main.cpp
//  StringToInteger
//
//  Created by 彭豪辉 on 2020/7/5.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <climits>
#include <string>

using namespace::std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

int myAtoi(string str) {
    if (str.empty()) {
        return 0;
    }
    int i = 0, base = 0, len = (int)str.size(), sign = 1;
    while (i < len && str[i] == ' ') {
        i++;
    }
    
    if (i < len && (str[i] == '+' || str[i] == '-')) {
        sign = str[i++] == '+' ? 1 : -1;
    }
    
    while (i < len && str[i] >= '0' && str[i] <= '9') {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        base = base * 10 + (str[i++] - '0');
    }
    base *= sign;
    return base;
}
