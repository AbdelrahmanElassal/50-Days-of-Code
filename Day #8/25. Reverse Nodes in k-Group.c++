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
        ListNode *dummy = new ListNode(0, head);
        ListNode *firstbeforreverse = dummy;
        ListNode *move = dummy;
        ListNode *prev = NULL;
        ListNode *curr = NULL;
        ListNode *temp = NULL;
        int count;
        while (true)
        {
            count = k;
            while (move && count)
            {
                count--;
                move = move->next;
            }
            if (!move)
                break;
            count = k;
            prev = firstbeforreverse;
            curr = prev->next;
            move = curr;
            while (count)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                count--;
            }
            move->next = curr;
            firstbeforreverse->next = prev;
            firstbeforreverse = move;
        }
        return dummy->next;
    }
};