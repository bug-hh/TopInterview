//
//  main.cpp
//  TwoSum
//
//  Created by bughh on 2020/6/30.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {3, 2, 4};
    vector<int> ret = twoSum(nums, 6);
    cout << ret[0] << "  " << ret[1] << endl;
    return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> ret;
    int len = (int)nums.size();
    for (int i = 0; i < len; i++) {
        int temp = target - nums[i];
        if (m.count(nums[i]) > 0) {
            ret.push_back(i);
            ret.push_back(m[nums[i]]);
            break;
        } else {
            m[temp] = i;
        }
    }
    return ret;
}
