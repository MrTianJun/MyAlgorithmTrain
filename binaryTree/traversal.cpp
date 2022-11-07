#include <iostream>
#include <vector>

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

void traversal(treeNode* cur, vector<int>& ret)
{
    /*
    // preorder
    if (cur == nullptr) return;
    ret.push_back(cur->val);
    traversal(cur->left, ret);
    traversal(cur->right, ret);

    // inorder
    if (cur == nullptr) return;
    traversal(cur->left, ret);
    ret.push_back(cur->val);
    traversal(cur->right, ret);
    */

      
    // postorder
    if (cur == nullptr) return;
    traversal(cur->left, ret);
    traversal(cur->right, ret);
    ret.push_back(cur->val);
}

vector<int> binaryTreeTraversal(treeNode* root)
{
    vector<int> ret;
    traversal(root, ret);
    return ret;
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

    vector<int> ret;
    ret = binaryTreeTraversal(r1);

    for (const int& r:ret) {
        cout << r << " ";
    }
    cout << endl;


    return 0;
}
