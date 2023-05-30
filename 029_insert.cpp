//
// Created by 23116 on 2023/05/11.
//
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
//排序的循环链表

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        //链表为空，直接插入
        if(head==nullptr){
            Node *node=new Node(insertVal);
            node->next=node;
            return node;
        }
        //链表长度为1，直接插入
        if(head->next==head){
            Node *node=new Node(insertVal);
            head->next=node;
            node->next=head;
            return head;
        }
        //链表长度大于1
        Node *pre=head;
        Node *cur=head->next;
        //遍历链表
        while(cur!=head){
            //若插入值在当前节点和下一个节点之间，插入
            if(pre->val<=insertVal&&insertVal<=cur->val){
                Node *node=new Node(insertVal);
                pre->next=node;
                node->next=cur;
                return head;
            }
            //若插入值大于当前节点的值且当前节点的值大于下一个节点的值，插入
            if(pre->val>cur->val&&insertVal>=pre->val){
                Node *node=new Node(insertVal);
                pre->next=node;
                node->next=cur;
                return head;
            }
            //若插入值小于当前节点的值且当前节点的值大于下一个节点的值，插入
            if(pre->val>cur->val&&insertVal<=cur->val){
                Node *node=new Node(insertVal);
                pre->next=node;
                node->next=cur;
                return head;
            }
            //遍历下一个节点
            pre=pre->next;
            cur=cur->next;
        }
        //若遍历完链表，插入值仍未插入，插入到链表尾部
        Node *node=new Node(insertVal);
        pre->next=node;
        node->next=cur;
        return head;
    }
};