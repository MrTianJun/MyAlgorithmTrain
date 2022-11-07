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

int getHeight(treeNode* root) 
{
    if (root == nullptr) return 0;
    int leftHeight = getHeight(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = getHeight(root->right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;
    else return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(treeNode* root) 
{
    int ret = getHeight(root);
    if (ret == -1) return false;
    return true;
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
   // r2->right = r5; 
    r3->left = r6;
    r3->right = r7;

    cout << isBalanced(r1) << endl;

    return 0;
}



