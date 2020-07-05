//
//  main.cpp
//  KthLargestElementinanArray
//
//  Created by bughh on 2020/6/30.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> & nums, int left, int right);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1;
    // 要写成 left <= right, 而不是 left < right, 因为可能数组只有一个元素
    while (left <= right) {
        int pivt = partition(nums, left, right);
        if (pivt == k - 1) {
            return nums[pivt];
        } else if (pivt > k - 1) {
            right = pivt - 1;
        } else {
            left = pivt + 1;
        }
    }
    return -1;
}

int partition(vector<int> & nums, int left, int right) {
    int begin = left, end = right;
    int p = nums[begin++];
    while (begin <= end) {
        // 将「大于 p」的数放到 p 左边，「小于 p」的数放 p 右边
        if (nums[begin] < p && nums[end] > p) {
            int temp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = temp;
            begin++;
            end--;
        }
        
        if (nums[begin] >= p) {
            begin++;
        }
        if (nums[end] <= p) {
            end--;
        }
    }
    int temp = nums[left];
    nums[left] = nums[end];
    nums[end] = temp;
    return end;
}
