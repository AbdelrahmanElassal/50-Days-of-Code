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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *temp = list1;
        ListNode *pre = NULL;
        ListNode *post = NULL;
        while (temp)
        {
            if (--a == 0)
                pre = temp;
            temp = temp->next;
            if (--b == 0)
            {
                post = temp->next;
                break;
            }
        }
        pre->next = list2;
        temp = list2;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = post;

        return list1;
    }
};