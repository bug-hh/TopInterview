//
//  main.cpp
//  Remove Nth Node From End of List
//
//  Created by bughh on 2020/7/7.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 这道题让我们移除链表倒数第N个节点，限定n一定是有效的，即n不会大于链表中的元素总数。还有题目要求一次遍历解决问题，那么就得想些比较巧妙的方法了。比如首先要考虑的时，如何找到倒数第N个节点，
 由于只允许一次遍历，所以不能用一次完整的遍历来统计链表中元素的个数，而是遍历到对应位置就应该移除了。那么就需要用两个指针来帮助解题，pre 和 cur 指针。首先 cur 指针先向前走N步，
 如果此时 cur 指向空，说明N为链表的长度，则需要移除的为首元素，那么此时返回 head->next 即可，如果 cur 存在，再继续往下走，此时 pre 指针也跟着走，直到 cur 为最后一个元素时停止，
 此时 pre 指向要移除元素的前一个元素，再修改指针跳过需要移除的元素即可，
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) {
        return head;
    }
    ListNode *cur = head, *pre = head;
    for (int i = 0; i < n; i++) {
        cur = cur ? cur->next : nullptr;
    }
    // 表明 n 是链表长度，那么倒数第 n 个，就是顺数第一个，删除顺数第一个节点就行
    if (!cur) {
        return head->next;
    }
    while (cur && cur->next) {
        pre = pre->next;
        cur = cur->next;
    }
    
    pre->next = pre->next ? pre->next->next : nullptr;
    
    return head;
}
