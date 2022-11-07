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

vector<vector<int>> levelOrder(treeNode* root)
{
    vector<vector<int>> ret;
    if (root == nullptr) return ret;
    queue<treeNode*> que;
    que.push(root);

    while (!que.empty()) {
        int siz = que.size();
        vector<int> vec;
        for (int i = 0; i < siz; i++) {
            treeNode* tmp = que.front(); que.pop();
            vec.push_back(tmp->val);
            if (tmp->left) que.push(tmp->left);
            if (tmp->right) que.push(tmp->right);
        }
        ret.push_back(vec);
    }

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
    vector<vector<int>> ret = levelOrder(r1);
    for (const auto& vec:ret) {
        for (const int& e:vec) {
            cout << e << " "; 
        }
        cout << endl;
    }


    return 0;
}
