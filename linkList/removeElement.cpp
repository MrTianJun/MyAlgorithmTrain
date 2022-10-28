#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr) { }
    ListNode(int x, ListNode* nex):val(x), next(nex) {}
};


ListNode* removeElement(ListNode* head, int target) 
{

    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* cur = dummyHead;

    while (cur->next != nullptr) 
    {
        if (cur->next->val == target) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else {
            cur = cur->next;
        }
    }

    head = dummyHead->next;
    delete dummyHead;
    return head;
}


int main()
{
    int target;
    cin >> target;
    ListNode* head = NULL;
    ListNode* tail = NULL;

    // ---------------------------------------------
    // -------------- input ------------------------
    // ---------------------------------------------


    /* 
    // 头插法
    int input;
    while (cin >> input) {
        ListNode* tmp = new ListNode(input);
        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tmp->next = head;
            head = tmp;
        }
    }
    */


    // 尾插法
    int input;
    while (cin >> input) {
        ListNode* tmp = new ListNode(input);
        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    // input result
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // call removeElement
    ListNode* ret = removeElement(head, target);
    // ---------------------------------------------
    // -------------- output -----------------------
    // ---------------------------------------------
    cur = ret;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    delete cur;

    return 0;
}
