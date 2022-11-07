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

int getNum(treeNode* root) 
{
    if (root == nullptr) return 0;
    int leftNum = getNum(root->left);
    int rightNum = getNum(root->right);
    int num = 1 + leftNum + rightNum;
    return num;
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

    cout << getNum(r1) << endl;

    return 0;
}


