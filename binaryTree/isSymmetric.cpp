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

bool isSymmetric(treeNode* root)
{
    if (root == nullptr) return true;
    queue<treeNode*> que;
    que.push(root->left);
    que.push(root->right);

    while (!que.empty()) {
        treeNode* leftNode = que.front(); que.pop();
        treeNode* rightNode = que.front(); que.pop();
        if (leftNode == nullptr && rightNode == nullptr) 
            continue;
        if (leftNode->val == rightNode->val) {
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        else 
            return false;
        /*
        if (leftNode != nullptr || rightNode !=nullptr || leftNode->val != rightNode->val)
            return false;
        que.push(leftNode->left);
        que.push(rightNode->right);
        que.push(leftNode->right);
        que.push(rightNode->left);
        */
    }

    return true;
}

int main()
{
    treeNode* r1 = new treeNode(1);;
    treeNode* r2 = new treeNode(2);;
    treeNode* r3 = new treeNode(2);;
    treeNode* r4 = new treeNode(3);;
    treeNode* r5 = new treeNode(3);;
    treeNode* r6 = new treeNode(4);;
    treeNode* r7 = new treeNode(3);;

    r1->left = r2;
    r1->right = r3;

    r2->left = r4; 
    r2->right = r5; 
    r3->left = r6;
    r3->right = r7;
    cout << isSymmetric(r1) << endl;



    return 0;
}

