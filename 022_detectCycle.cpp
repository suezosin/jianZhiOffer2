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
class Solution {
public:
    //思路：快慢指针
    //查找链表中的环的入口，如果有环的话，返回入口节点，否则返回空，即返回链表的尾节点
    ListNode *getNodeInLoop(ListNode *head){
        //返回环中的节点
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return fast;
            }
        }
        return nullptr;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *nodeInLoop=getNodeInLoop(head);
        if(nodeInLoop==nullptr){//无环
            return nullptr;
        }
        //有环,计算环中节点的个数
        int cnt=1;
        ListNode *p=nodeInLoop;
        while(p->next!=nodeInLoop){
            p=p->next;
            ++cnt;
        }
        //快慢指针，快指针先走cnt步
        ListNode *fast=head;
        ListNode *slow=head;
        for(int i=0;i<cnt;++i){
            fast=fast->next;
        }
        //快慢指针同时走，直到相遇
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};