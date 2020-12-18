/*
*面试题 02.01. 移除重复节点
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public://O(N2)
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode *h=head;
        while(h!=nullptr){
            ListNode *p=h;
            while(p->next!=nullptr){
                if(p->next->val==h->val)
                    p->next=p->next->next;
                else
                p=p->next;
            }
            h=h->next;
        }
        return head;
    }
};
class Solution {
public://hash 
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head==nullptr)
        return head;
        unordered_set<int> occurred = {head->val};
        ListNode *p=head;
        while(p->next!=nullptr){
            if(occurred.count(p->next->val)){
                p->next=p->next->next;
            }
            else{
                occurred.insert(p->next->val);
                p=p->next;
            }
        }
        return head;
    }
};