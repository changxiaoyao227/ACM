/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;ListNode *p=head;
        while(p!=nullptr)
        {
            length++;
            p=p->next;
        }//length
        ListNode *h=new ListNode;
        h->next=head;//delete head in case
        p=h;
        int pre=length-n+1;
        while(--pre)
        p=p->next;
        p->next=p->next->next;
        return h->next;
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode *> s;//ListNode *
        ListNode *h=new ListNode;
        h->next=head;
        ListNode *p=new ListNode;
        p=h;
        while(p!=nullptr)
        {
            s.push(p);
            p=p->next;
        }
        while(n--)
        s.pop();
        ListNode* pre=s.top();//*
        pre->next=pre->next->next;
        return h->next;
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int& n) {
      if(!head) return head;/* 递归的边界 */
      head->next=removeNthFromEnd(head->next,n);/* 递归, 注意n是引用 */
      return --n?head:head->next;/* 注意, 由于递归, 执行此语句时相当于是从后往前的遍历, 当--n==0时就是要删除的节点 */ /*--n==0 return head->next; 跳过这个head(结点)!*/
    }//评论区很强的一位大哥写的 
};

class Solution {
public://fast and slow point
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *h=new ListNode,*slow,*fast;
      h->next=head;slow=fast=h;
      while(n--)
      fast=fast->next;
      while(fast->next!=nullptr){
        fast=fast->next;
        slow=slow->next; 
      }
      slow->next=slow->next->next;
      return h->next;
    }
};