#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int val):val(val), next(nullptr) {}
    ListNode(int val, ListNode* ptr):val(val), next(ptr) {}
};

ListNode* swapPairs(ListNode* head) 
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    while (cur->next != nullptr && cur->next->next != nullptr)
    {
        ListNode* tmp1 = cur->next;
        ListNode* tmp2 = cur->next->next->next;

        cur->next = cur->next->next;
        cur->next->next = tmp1;
        cur->next->next->next = tmp2;

        cur = cur->next->next;
    }

    head = dummyHead->next;
    delete dummyHead;
    return head;
}




int main() 
{
    int input;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    while (cin >> input)
    {
        ListNode* tmp = new ListNode(input);
        if (head == nullptr) 
        {
            head = tmp;
            tail = tmp;
        }
        else 
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    cout << "Finish input" << endl;
    ListNode* cur = head;
    while (cur != nullptr)
    {
        cout << cur->val << " "; 
        cur = cur->next;
    }
    cout << endl;
    cout << "Input done" << endl;


    ListNode* nhead = swapPairs(head);
    cout << "Finish call swapPairs()" << endl;
    cur = nhead;
    while (cur != nullptr)
    {
        cout << cur->val << " "; 
        cur = cur->next;
    }
    cout << endl;
    cout << "Finish output" << endl;

    return 0;
}
