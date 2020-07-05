//
//  main.cpp
//  MedianOfTwoSortedArrays
//
//  Created by bughh on 2020/7/1.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
double findKth(vector<int> & nums1, int i, vector<int> & nums2, int j, int k);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double ret = findMedianSortedArrays(nums1, nums2);
    cout << ret << endl;
    return 0;
}


/*
 要在两个有序数组的「混合数组」中，找第 K 大的数，那么转换为在两个有序数组中，分别找出第 K/2 大的数 a,b, 然后求 （a + b）/ 2
 分别在两个有序数组中找 第 K/2 大的数，分三种情况：
 1、两个数组都存在 K/2 个数
    假设两个数组中第 K/2 大的数，值分别为 V1, V2
    淘汰值小的对应数组中的前 K/2 个数（例如 V1 < V2, 那么淘汰第一个数组中前 K/2 个数字）
 2、第一个数组中元素个数少于 K/2
    那么淘汰「第二个」数组中前 K/2 个数，因为混合数组中，第 K 数一定不会出现在「第二个数组的前 K/2 个数中」
 3、第二个数组中元素个数少于 K/2
    那么淘汰「第一个」数组中前 K/2 个数，因为混合数组中，第 K 数一定不会出现在「第一个数组的前 K/2 个数中」
 
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = (int)nums1.size(), n = (int)nums2.size();
    int k1 = (m + n + 1) / 2, k2 = (m + n + 2) / 2;
    return (findKth(nums1, 0, nums2, 0, k1) + findKth(nums1, 0, nums2, 0, k2)) / 2;
}

/*
 分别从 nums1 下标 i，nums2 下标 j 开始，找混合数组中，第 k 大的数
 */
double findKth(vector<int> & nums1, int i, vector<int> & nums2, int j, int k) {
    if (i >= nums1.size()) {
        return nums2[j + k - 1];
    }
    
    if (j >= nums2.size()) {
        return nums1[i + k - 1];
    }
    
    if (k == 1) {
        return nums1[i] < nums2[j] ? nums1[i] : nums2[j];
    }
    /*
     分别找出两个数组中，第 K/2 大的数
     */
    int v1 = (i + k / 2 - 1) >= nums1.size() ? INT_MAX : nums1[i + k / 2 - 1];
    int v2 = (j + k / 2 - 1) >= nums2.size() ? INT_MAX : nums2[j + k / 2 - 1];
    
    if (v1 < v2) {
        return findKth(nums1, i + k / 2, nums2, j, k - k/2);
    } else {
        return findKth(nums1, i, nums2, j + k / 2, k - k/2);
    }
}
