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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        unordered_map<int, ListNode *> presum;
        ListNode *temp = head;
        int psum = 0;
        presum[0] = dummy;
        while (temp)
        {
            psum += temp->val;

            if (presum.count(psum))
            {
                ListNode *d = presum[psum];
                ListNode *mov = d->next;
                int pmov = psum + (mov ? mov->val : 0);
                while (pmov != psum)
                {
                    presum.erase(pmov);
                    mov = mov->next;
                    pmov = pmov + (mov ? mov->val : 0);
                }
                d->next = temp->next;
            }
            else
            {
                presum[psum] = temp;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};