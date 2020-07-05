//
//  main.cpp
//  ReverseInteger
//
//  Created by bughh on 2020/7/1.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <climits>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

int reverse(int x) {
    int res = 0;
    while (x != 0) {
        if (abs(res) > INT_MAX / 10) {
            return 0;
        }
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

