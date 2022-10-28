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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* slow = dummyHead;
    ListNode* fast = dummyHead;
    while (n-- && fast != nullptr) {
        fast = fast->next;
    }

    while (fast->next != nullptr) 
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;

    head = dummyHead->next;
    delete dummyHead;
    return head;
}



int main()
{
    int n;
    cin >> n;

    int input;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (cin >> input) 
    {
        ListNode* tmp = new ListNode(input);
        if (head == nullptr) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;


    ListNode* nhead = removeNthFromEnd(head, n);

    cur = nhead;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;


    return 0;
}
