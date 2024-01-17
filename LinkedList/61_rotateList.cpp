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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
            return head;
        int n = 0;
        ListNode *tmp = head;
        ListNode *last = NULL;
        while (tmp)
        {
            n++;
            last = tmp;
            tmp = tmp->next;
        }
        tmp = head;
        k = k % n;
        if (k == 0)
            return head;
        for (int i = 1; i < n - k; i++)
        {
            tmp = tmp->next;
        }
        last->next = head;
        ListNode *ans = tmp->next;
        tmp->next = NULL;
        return ans;
    }
};