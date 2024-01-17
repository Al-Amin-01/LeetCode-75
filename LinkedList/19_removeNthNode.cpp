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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *prvhead = head;
        int i = 1;
        while (i < left - 1)
        {
            prvhead = prvhead->next;
            i++;
        }

        ListNode *prv = NULL;
        ListNode *nxt;
        ListNode *node = prvhead->next;
        if (left == 1)
            node = head;
        if (!node)
            return head;
        ListNode *firstNode = node;
        int x = right - left + 1;
        while (x-- && node)
        {
            nxt = node->next;
            node->next = prv;
            prv = node;
            node = nxt;
        }
        if (left == 1)
        {
            firstNode->next = nxt;
            return prv;
        }
        prvhead->next = prv;
        firstNode->next = nxt;

        return head;
    }
};