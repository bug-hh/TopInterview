//
//  main.cpp
//  AddTwoNumbers
//
//  Created by bughh on 2020/6/30.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    int carry = 0;
    while (l1 || l2) {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        
        int s = v1 + v2 + carry;
        carry = s / 10;
        cur->next = new ListNode(s % 10);
        cur = cur->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    
    if (carry) {
        cur->next = new ListNode(carry);
        cur = cur->next;
    }
    return dummy->next;
}
