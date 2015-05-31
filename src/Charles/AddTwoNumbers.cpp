#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution
{
public:
    ListNode * addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *head = NULL;
        ListNode *r = NULL;
        int carry = 0;

        while ((p != NULL) && (q != NULL))
        {
            int sum = p->val + q->val + carry;
            carry = sum / 10;

            ListNode *tmp = new ListNode(sum % 10);
            if (head == NULL)
            {
                head = tmp;
                r = tmp;
            }
            else
            {
                r->next = tmp;
                r = tmp;
            }
            p = p->next;
            q = q->next;
        }

        while (p != NULL)
        {
            int sum = p->val + carry;
            carry = sum / 10;

            ListNode *tmp = new ListNode(sum % 10);
            if (head == NULL)
            {
                head = tmp;
                r = tmp;
            }
            else
            {
                r->next = tmp;
                r = tmp;
            }
            p = p->next;
        }

        while (q != NULL)
        {
            int sum = q->val + carry;
            carry = sum / 10;

            ListNode *tmp = new ListNode(sum % 10);
            if (head == NULL)
            {
                head = tmp;
                r = tmp;
            }
            else
            {
                r->next = tmp;
                r = tmp;
            }
            q = q->next;
        }

        if (carry)
        {
            ListNode *tmp =  new ListNode(carry);
            if (head == NULL)
            {
                head = tmp;
            }
            else
            {
                r->next = tmp;
            }
        }

        return head;
    }
};

ListNode *constructList(int *nums, int size)
{
    ListNode *head = NULL;
    ListNode *r = NULL;
    for (int i = 0; i < size; i++)
    {
        ListNode *tmp = new ListNode(nums[i]);
        if (head == NULL)
        {
            head = tmp;
            r = tmp;
        }
        else
        {
            r->next = tmp;
            r = tmp;
        }
    }
    return head;
}

void printList(ListNode *list)
{
    for (ListNode *p = list; p != NULL; p = p->next)
    {
        std::cout << p->val;
    }
    std::cout << std::endl;
}

void freeList(ListNode *list)
{
    ListNode *next = NULL;
    for (ListNode *p = list; p != NULL; p = p->next)
    {
        next = p->next;
        delete p;
    }
}

int main(void)
{
    ListNode *l1;
    ListNode *l2;
    Solution test;

    //test case1
    int l1_nums[] = {2, 4, 3};
    int l2_nums[] = {5, 6, 4};

    //test case2
    int l3_nums[] = {9, 9, 9};
    int l4_nums[] = {9, 9, 9};


    //construct list l1 l2
    l1 = constructList(l1_nums, sizeof(l1_nums) / sizeof(int));
    l2 = constructList(l2_nums, sizeof(l2_nums) / sizeof(int));
    
    ListNode *l3 = test.addTwoNumbers(l1, l2); 

    printList(l3);
    freeList(l1);
    freeList(l2);
    freeList(l3);

    l1 = constructList(l1_nums, sizeof(l1_nums) / sizeof(int));
    
    l3 = test.addTwoNumbers(l1, NULL);
    printList(l3);
    freeList(l1);
    freeList(l3);

    l1 = constructList(l3_nums, sizeof(l3_nums) / sizeof(int));
    l2 = constructList(l4_nums, sizeof(l4_nums) / sizeof(int));
    
    l3 = test.addTwoNumbers(l1, l2);
    printList(l3);
    freeList(l1);
    freeList(l2);
    freeList(l3);
}
