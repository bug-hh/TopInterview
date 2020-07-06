//
//  main.cpp
//  ThreeSum
//
//  Created by bughh on 2020/7/6.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    int len = (int)nums.size();
    if (nums.empty() || nums.front() > 0 || nums.back() < 0) {
        return {};
    }
    for (int i = 0; i < len - 2; i++) {
        if (nums[i] > 0) {
            break;
        }
        
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }
        
        int target = -nums[i], left = i + 1, right = len - 1;
        while (left < right) {
            int s = nums[left] + nums[right];
            if (s == target) {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                ret.push_back(temp);
                while (left < len - 1 && nums[left + 1] == nums[left]) {
                    left++;
                }
                
                while (right > 0 && nums[right - 1] == nums[right]) {
                    right--;
                }
                left++;
                right--;
            } else if (s < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return ret;
}
