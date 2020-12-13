class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p,*r,*t;
        p=NULL;r=head;
        while(r){
            t=r->next;
            r->next=p;
            p=r;
            r=t;
        }
        return p;
    }
};
//https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/submissions/