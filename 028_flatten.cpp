//
// Created by 23116 on 2023/05/11.
//
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
//展平多级双向链表
//思路：所有节点出现在同一层，即所有节点的child都为空
class Solution {
public:
    Node* flatten(Node* head) {
        Node *dummy=new Node(0);
        dummy->next=head;
        while(head!=nullptr){ //遍历链表
            if(head->child== nullptr){
                head = head->next; //若当前节点的child为空，直接遍历下一个节点
            }
            else{ //若当前节点的child不为空，将child插入到当前节点和下一个节点之间
                Node *tmp=head->next; //保存下一个节点
                Node *child=head->child; //保存child
                head->next=child; //将child插入到当前节点和下一个节点之间
                child->prev=head; //将child的前驱指向当前节点
                head->child= nullptr; //将当前节点的child置空
                while(child->next!= nullptr){ //遍历child，找到child的最后一个节点
                    child=child->next;
                } //将child的最后一个节点的next指向下一个节点
                child->next=tmp; //将下一个节点的prev指向child的最后一个节点
                if(tmp!= nullptr){ //若下一个节点不为空，将下一个节点的prev指向child的最后一个节点
                    tmp->prev=child; //将下一个节点的prev指向child的最后一个节点
                }
                head=head->next; //遍历下一个节点
            }
        }
        return dummy->next;
    }
};