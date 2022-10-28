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

ListNode* getIntersectionNode(ListNode* head_a, ListNode* head_b)
{
    int len_a = 0; 
    int len_b = 0;
    ListNode* cur = head_a;
    while(cur != nullptr) {
        len_a++;
        cur = cur->next;
    }

    cur = head_b;
    while(cur != nullptr) {
        len_b++;
        cur = cur->next;
    }


    ListNode* cur_another;
    if (head_a > head_b) {
        cur = head_a;
        int len = len_a - len_b;
        while (len-- && cur != nullptr) {
            cur = cur->next;
        }

        cur_another = head_b; 
    }
    else {
        cur = head_b;
        int len = len_b - len_a;
        while (len-- && cur != nullptr) {
            cur = cur->next;
        }

        cur_another = head_a; 
    }

    while (cur != nullptr)
    {
        if (cur == cur_another) return cur;
        cur = cur->next;
        cur_another = cur_another->next;
    }
    return nullptr;
}



int main()
{
    ListNode* head_a = nullptr;
    ListNode* tail_a = nullptr;

    ListNode* head_b = nullptr;
    ListNode* tail_b = nullptr;
    int input;
    while (cin >> input) {
        ListNode* tmp = new ListNode(input);
        if (head_a == nullptr && head_b == nullptr) {
            head_a = tmp;
            tail_a = tmp;
            head_b = tmp;
            tail_b = tmp;
        }
        else {
            tail_a->next = tmp;
            tail_b->next = tmp;
            tail_a = tail_a->next;
            tail_b = tail_b->next;
        }
    }

    ListNode* cur = head_a;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    cur = head_b;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    ListNode* ret = getIntersectionNode(head_a, head_b);
    if (ret == nullptr) cout << "No intersection node" << endl;
    if (ret != nullptr) cout << ret->val << endl;

    return 0;
}
