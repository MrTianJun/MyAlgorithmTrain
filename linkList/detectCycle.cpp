#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int val):val(val), next(nullptr) {}
    ListNode(int val, ListNode* ptr): val(val), next(nullptr) {}
};

int detectCycle(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) {
            ListNode* index1 = head;
            ListNode* index2 = slow;
            int pos = 0;
            while (index1 != index2) {
                index1 = index1->next;
                index2 = index2->next;
                pos++;
            }
            return pos;
        }
    }
    return -1;
}




int main()
{
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int input;
    while (cin >> input) {
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

    // cycle
    tail->next = head->next->next->next;

    cout << detectCycle(head) << endl;

    return 0;
}

