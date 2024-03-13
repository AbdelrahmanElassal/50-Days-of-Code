class Lnode
{
public:
    int val;
    Lnode *next;
    Lnode()
    {
        this->val = 0;
        this->next = NULL;
    }
    Lnode(int v)
    {
        this->val = v;
        this->next = NULL;
    }
    Lnode(int v, Lnode *next)
    {
        this->val = v;
        this->next = next;
    }
};
class MyLinkedList
{
    Lnode *head;

public:
    MyLinkedList()
    {
        this->head = NULL;
    }

    int get(int index)
    {
        if (!this->head)
            return -1;

        Lnode *temp = head;
        while (temp && (index--) > 0)
        {
            temp = temp->next;
        }

        return temp ? temp->val : -1;
    }

    void addAtHead(int val)
    {
        Lnode *temp = new Lnode(val, this->head);
        this->head = temp;
    }

    void addAtTail(int val)
    {
        Lnode *temp = new Lnode(val, NULL);
        if (!this->head)
        {
            this->head = temp;
        }
        else
        {
            Lnode *curr = head;
            while (curr->next)
                curr = curr->next;
            curr->next = temp;
        }
    }

    void addAtIndex(int index, int val)
    {
        Lnode *n = new Lnode(val);
        Lnode *temp = head;
        if (index == 0)
        {
            n->next = head;
            head = n;
        }
        else
        {
            while (temp != NULL && index > 1)
            {
                temp = temp->next;
                index--;
            }
            if (temp == NULL)
                return;
            if (temp != NULL && temp->next == NULL)
            {
                temp->next = n;
            }
            else
            {
                n->next = temp->next;
                temp->next = n;
            }
        }
    }

    void deleteAtIndex(int index)
    {
        Lnode *temp = head;
        if (index == 0)
        {
            head = head->next;
        }
        while (temp != NULL && index > 1)
        {
            temp = temp->next;
            index--;
        }
        if (temp == NULL)
            return;
        if (temp != NULL && temp->next != NULL)
        {
            temp->next = temp->next->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */