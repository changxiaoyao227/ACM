/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public://
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* p;
        ListNode* pre=NULL;
        while(fast!=NULL&&fast->next!=NULL){
            p=slow;
            slow=slow->next;
            fast=fast->next->next;
            p->next=pre;
            pre=p;
        }
        if(fast)
            slow=slow->next;
        while(p){
            if(p->val!=slow->val)
                return false;
            p=p->next;
            slow=slow->next;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        ListNode *cur = nullptr;

        while(fast != nullptr && fast->next != nullptr)
        {
            cur = slow;
        
            slow = slow->next;
            fast = fast->next->next;

            cur->next = prev; //改变当前节点指向方向
            prev = cur; //移到下一个节点
        }

        //链表为奇数长时,此时slow在中间节点,fast->next==nullptr,应跳过此节点
        if(fast != nullptr) slow = slow->next;

        //链表为奇数长时,show为中间靠右节点
        while(prev != nullptr && slow != nullptr){
            if(prev->val != slow->val) return false;

            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};