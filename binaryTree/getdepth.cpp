#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct treeNode
{
    int val;
    treeNode* left;
    treeNode* right;
    treeNode():val(0), left(nullptr), right(nullptr) {}
    treeNode(int v):val(v), left(nullptr), right(nullptr) {}
    treeNode(int v, treeNode* l, treeNode* r):val(v), left(l), right(r) {}
};

/*
int getdepth(treeNode* root) 
{
    if (root == nullptr) return 0;
    int leftdepth = getdepth(root->left);
    int rightdepth = getdepth(root->right);
    int depth = 1 + max(leftdepth, rightdepth);
    return depth;
}
*/

// level order method
int getdepth(treeNode* root) 
{
    if (root == nullptr) return 0;
    queue<treeNode*> que;
    que.push(root);
    int depth = 0;

    while (!que.empty()) {
        int siz = que.size();
        depth++;
        for (int i = 0; i < siz; i++) {
            treeNode* tmp = que.front();
            que.pop();
            if (tmp->left) que.push(tmp->left);
            if (tmp->right) que.push(tmp->right);
        }
    }

    return depth;
}



int main()
{
    treeNode* r1 = new treeNode(1);;
    treeNode* r2 = new treeNode(2);;
    treeNode* r3 = new treeNode(2);;
    treeNode* r4 = new treeNode(3);;
    treeNode* r5 = new treeNode(4);;
    treeNode* r6 = new treeNode(4);;
    treeNode* r7 = new treeNode(3);;

    r1->left = r2;
    r1->right = r3;

    r2->left = r4; 
    r2->right = r5; 
    r3->left = r6;
    r3->right = r7;

    cout << getdepth(r1) << endl;

    return 0;
}

