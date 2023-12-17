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
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *traverse = head;
        int cnt = 0;
        while (traverse)
        {
            cnt++;
            traverse = traverse->next;
        }
        traverse = head;
        int n = cnt / 2;
        if (n == 0)
            return NULL;
        for (int i = 0; i < n - 1; i++)
        {
            head = head->next;
        }
        if (head->next)
            head->next = head->next->next;
        return traverse;
    }
};