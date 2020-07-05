//
//  main.cpp
//  ContainerWithMostWater
//
//  Created by 彭豪辉 on 2020/7/5.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

int maxArea(vector<int>& height) {
    int i = 0, j = (int)height.size() - 1;
    int ret = 0;
    while (i < j) {
        ret = max(ret, min(height[i], height[j]) * (j - i));
        height[i] < height[j] ? i++ : j--;
    }
    return ret;
}
