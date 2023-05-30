//
// Created by 23116 on 2023/05/05.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        ListNode* fast=&dummy;
        ListNode* slow=&dummy;
        dummy.next=head;
        //fast先走n步
        for(int i=0;i<n;++i){
            fast=fast->next;
        }
        //fast和slow同时走，直到fast走到链表的末尾
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        //删除倒数第n个节点
        slow->next=slow->next->next;
        return dummy.next;
    }
};