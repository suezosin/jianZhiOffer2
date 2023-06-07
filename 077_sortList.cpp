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
    //思路：利用归并排序的思想，将链表分为两部分，然后对两部分分别排序，最后将两部分合并
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = sortList(slow->next);
        slow->next = nullptr;
        ListNode* left = sortList(head);
        return merge(left, right);
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(left!=nullptr&&right!=nullptr){
            if(left->val<right->val){
                cur->next = left;
                left = left->next;
            }
            else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if(left!=nullptr) cur->next = left;
        if(right!=nullptr) cur->next = right;
        return dummy->next;
    }
};