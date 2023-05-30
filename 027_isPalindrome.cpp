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
 //回文链表
#include "iostream"
using namespace std;

 struct ListNode {
int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    //思路：先反转链表，然后比较两个链表
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
    bool isPalindrome(ListNode* head) {
        //快慢指针
        if(head==nullptr||head->next==nullptr){
            return true;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head; //没有哨兵节点，链表长度为2时答案是错的
        ListNode *fast = dummy;
        ListNode *slow = dummy;
//        ListNode *fast = head;
//        ListNode *slow = head;
        while(fast!= nullptr&&fast->next!= nullptr){
            slow=slow->next;
            fast=fast->next;
            if(fast->next!= nullptr){
                fast=fast->next;
            }
        }
        //反转后半部分链表

        ListNode *revLast = reverseList(slow->next);
        ListNode *p = head;
        while(p!= nullptr&&revLast!= nullptr){
            if(p->val!=revLast->val){
                return false;
            }
            p=p->next;
            revLast=revLast->next;
        }
        return true;
    }
};
int main(){
    //测试代码
    //输入： 1->2
    //输出： false
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(2);
    Solution s;
    cout<<s.isPalindrome(head)<<endl;
    return 0;
}