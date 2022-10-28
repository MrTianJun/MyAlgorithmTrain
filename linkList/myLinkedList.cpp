#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int x):val(x), next(nullptr) {}
    ListNode(int x, ListNode* next):val(x), next(next) {}
};

class myLinkedList
{
public:
    myLinkedList():head(NULL), tail(NULL), siz(0) { }

    int get(int index) {
        if (index >= siz || index < 0) return -1;
        ListNode* cur = head;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    int addAtIndex(int index, int val) {
        if (index >= siz || index < 0) return -1;
        ListNode* cur = head;
        if (index > 0) {
            index--;
            while (index--) {
                cur = cur->next;
            }
            ListNode* newnode = new ListNode(val);
            ListNode* tmp = cur->next;
            cur->next = newnode;
            newnode->next = tmp;
        }
        else {
            ListNode* newnode = new ListNode(val);
            newnode->next = head;
            head = newnode;
        }

        return val;
    }



private:
    ListNode* head;
    ListNode* tail;
    int siz;
};


int main()
{




    return 0;
}
