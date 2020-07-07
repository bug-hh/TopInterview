//
//  main.cpp
//  MergeTwoSortedLists
//
//  Created by bughh on 2020/7/7.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <climits>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 具体思想就是新建一个链表，然后比较两个链表中的元素值，把较小的那个链到新链表中，由于两个输入链表的长度可能不同，
 所以最终会有一个链表先完成插入所有元素，则直接另一个未完成的链表直接链入新链表的末尾。
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    while (l1 && l2) {
        int v1 = l1->val;
        int v2 = l2->val;
        if (v1 < v2) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    temp->next = l1 ? l1 : l2;
    
    return dummy->next;
}
