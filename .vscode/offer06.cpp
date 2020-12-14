class Solution {
public:
    vector<int> v;
    vector<int> reversePrint(ListNode* head) {
        if(head==nullptr)
        return v;
       //     return {};
       // vector<int> v=reversePrint(head->next);
       v=reversePrint(head->next);
        v.push_back(head->val);
        return v;
    }
};
/*
剑指 Offer 06. 从尾到头打印链表
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
*/