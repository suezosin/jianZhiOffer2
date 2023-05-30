//
// Created by 23116 on 2023/05/11.
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
 //反转链表
class Solution {
public:
    //思路：前中后指针，前指针指向前一个节点，中指针指向当前节点，后指针指向后一个节点
    ListNode* reverseList(ListNode* head) {
        //若链表为空或者只有一个节点，直接返回
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode *pre=nullptr;
        ListNode *cur=head;
//        ListNode *next=head->next;
        //反转链表
        while(cur!= nullptr){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};