// ---> SOLUTION 
// --->O(N) TIME
// --->O(1) Space

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = NULL;
        while (current)
        {
            ListNode *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *temp = head;
        int size = 0;
        while (temp)
        {
            temp = temp->next;
            size++;
        }
        size /= 2;
        int s = size;
        temp = head;
        while (size)
        {
            temp = temp->next;
            size--;
        }
        temp = reverseList(temp);
        while (s && temp && head)
        {
            if (head->val != temp->val)
                return false;
            temp = temp->next;
            head = head->next;
        }

        return true;
    }
};