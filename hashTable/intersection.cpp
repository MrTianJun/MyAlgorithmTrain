#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int> nums1, vector<int> nums2)
{
    unordered_set<int> ret;
    unordered_set<int> nums1_set(nums1.begin(), nums1.end());
    for (const int& num2:nums2) {
        if (nums1_set.find(num2) != nums1_set.end()) {
            ret.insert(num2);
        }
    }

    return vector<int>(ret.begin(), ret.end());
}


int main()
{
    vector<int> nums1;
    vector<int> nums2;

    int input;
    while (cin >> input) {
        nums1.push_back(input);
        if (cin.get() == '\n') break;
    }

    while (cin >> input) {
        nums2.push_back(input);
        if (cin.get() == '\n') break;
    }

    for (const int& num1:nums1) 
        cout << num1 << " ";
    cout << endl;

    for (const int& num2:nums2) 
        cout << num2 << " ";
    cout << endl;

    vector<int> ret = intersection(nums1, nums2);
    for (const int& r:ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
