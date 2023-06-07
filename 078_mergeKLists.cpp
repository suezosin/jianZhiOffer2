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
    //思路：合并k个链表，可以利用归并排序的思想
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        for(int i=1;i<lists.size();i++){
            lists[0] = merge(lists[0],lists[i]);
        }
        return lists[0];
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1!= nullptr&&l2!= nullptr){
            if(l1->val<l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1!=nullptr) cur->next = l1;
        if(l2!= nullptr) cur->next = l2;
        return dummy->next;
    }
};