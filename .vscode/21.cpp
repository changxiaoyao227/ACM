/*
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3=new ListNode;ListNode *r;
        r=l3;
       while(l1&&l2){
           if(l1->val<l2->val){//把while放到外面去
               r->next=l1;
               r=r->next;
               l1=l1->next;
           }
          else{
                r->next=l2;
               r=r->next;
               l2=l2->next;
          }
       }
       r->next=l1==nullptr?l2:l1;//nice
       return le
};