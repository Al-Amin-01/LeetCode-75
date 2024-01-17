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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *tmp = head;
        for (int i = 0; i < k; i++)
        {
            if (!tmp)
                return head;
            tmp = tmp->next;
        }

        tmp = head;
        ListNode *prv = NULL;
        ListNode *nxt;

        for (int i = 0; i < k; i++)
        {
            nxt = tmp->next;
            tmp->next = prv;
            prv = tmp;
            tmp = nxt;
        }

        head->next = reverseKGroup(tmp, k);
        return prv;
    }
};