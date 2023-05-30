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
 //重排链表
 //思路：快慢指针，找到链表的中间节点，将链表分为两部分，后半部分反转，然后将两个链表合并
class Solution {
public:
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
    void reorderList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        while(fast != nullptr&& fast->next != nullptr){
            slow=slow->next;
            fast=fast->next;
            if(fast->next!= nullptr)
                fast=fast->next;
        }
        ListNode *last_rev = reverseList(slow->next);
        slow->next = nullptr;
        ListNode *first = head; //first指向前半部分链表的头节点,head不能改变
        while(first != nullptr && last_rev != nullptr){
            ListNode *first_next = first->next; //保存first的下一个节点
            ListNode *last_rev_next = last_rev->next; //保存last_rev的下一个节点
            first->next = last_rev; //将last_rev插入到first后面
            last_rev->next = first_next; //将first_next插入到last_rev后面
            first = first_next; //first指向下一个节点
            last_rev = last_rev_next; //last_rev指向下一个节点
            //图解：https://leetcode-cn.com/problems/reorder-list/solution/zhong-pai-lian-biao-by-leetcode-solution/
        }
    }
};