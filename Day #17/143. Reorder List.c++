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
    void reorderList(ListNode *head)
    {
        if (!head->next)
            return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *dummy = reverse(slow);
        fast = head;
        ListNode *tempf = NULL;
        ListNode *tempd = NULL;
        while (dummy->next && fast->next)
        {
            tempf = fast->next;
            fast->next = dummy;
            tempd = dummy->next;
            dummy->next = tempf;
            dummy = tempd;
            fast = tempf;
        }
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *current = head;
        while (current)
        {
            ListNode *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
};