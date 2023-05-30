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
 //链表中的两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //思路：先反转两个链表，然后相加，再反转
        ListNode *p1=reverseList(l1);
        ListNode *p2=reverseList(l2);
        ListNode *dummy=new ListNode(0); //哨兵节点
        ListNode *p=dummy;
        int carry=0; //进位
        while(p1!=nullptr||p2!=nullptr){
            //若p1不为空，取p1的值，否则取0
            int x=p1==nullptr?0:p1->val;
            int y=p2==nullptr?0:p2->val;
//            ListNode *next = new ListNode((x+y+carry)%10);
            p->next = new ListNode((x+y+carry)%10);
            p = p->next;
            carry=(x+y+carry)/10;

            if(p1!= nullptr)
                p1 = p1->next;
            if(p2!= nullptr)
                p2 = p2->next;
            if(p1== nullptr&&p2== nullptr){ //若p1和p2都为空，且进位为0，结束循环
                if(carry>0){ //若进位不为0，再加一个节点
                    ListNode *next = new ListNode((x+y+carry)/10);
                    p->next = next;
                    p = p->next;
                }
            }
        }
        return reverseList(dummy->next);
    }
};