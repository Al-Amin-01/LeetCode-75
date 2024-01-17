#include <bits/stdc++.h>
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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *tmp = head;
        if (!head)
            return head;
        ListNode *ans = new ListNode();
        ListNode *p = ans;
        while (tmp)
        {
            int x = tmp->val;
            bool f = 0;
            ListNode *node = tmp;
            while (tmp->next && tmp->next->val == x)
            {
                tmp = tmp->next;
                f = 1;
            }
            if (f == 0)
            {
                ans->next = node;
                ans = ans->next;
            }
            tmp = tmp->next;
        }
        ans->next = NULL;
        return p->next;
    }
};