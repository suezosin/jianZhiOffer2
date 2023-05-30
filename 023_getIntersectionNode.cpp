//
// Created by 23116 on 2023/05/11.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //两个链表的第一个重合节点
class Solution {
public:
    //思路：快慢指针,当成两个环，一个环是headA，一个环是headB，如果有重合节点，那么两个环一定会相遇
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1=headA;
        ListNode *p2=headB;
        while(p1!=p2){
            if(p1==nullptr&&p2==nullptr){//没有交点时，返回空指针
                return nullptr;
            }
            p1=p1==nullptr?headB:p1->next;
            p2=p2==nullptr?headA:p2->next;
        }
        return p1;
    }
};