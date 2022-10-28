#include <iostream>

using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int val):val(val), next(nullptr) {}
    ListNode(int val, ListNode* ptr): val(val), next(ptr) {}
};


ListNode* reverseList(ListNode* head) 
{
    ListNode* cur = head;
    ListNode* pre = nullptr;

    // core
    while (cur != nullptr) {
        ListNode* tmp = cur->next;
        cur->next = pre;

        pre = cur;
        cur = tmp;
    }
    return pre;
}

int main() 
{
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

    ListNode* nhead = reverseList(head);
    cur = nhead;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}
