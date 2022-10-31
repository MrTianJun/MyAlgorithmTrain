#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
int fourSum(vector<int> nums1, vector<int> nums2, 
            vector<int> nums3, vector<int> nums4)
{
    int ret = 0;
    int siz = nums1.size();
    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) {
            for (int m = 0; m < siz; m++) {
                for (int n = 0; n < siz; n++) {
                    if (nums1[i] + nums2[j] + nums3[m] + nums4[n] == 0)
                        ret++;
                }
            }
        }
    } 

    return ret;
}
*/

int fourSum(vector<int> nums1, vector<int> nums2, 
            vector<int> nums3, vector<int> nums4)
{
    unordered_map<int, int> map;
    int ret = 0;
    for (const int & n1:nums1) {
        for (const int & n2:nums2) {
            map[n1 + n2]++;
        }
    }

    for (const int & n3:nums3) {
        for (const int & n4:nums4) {
            if (map.find(0 - (n3+n4)) != map.end()) {
                ret += map[0-(n3+n4)];
            }
        }
    }

    return ret;
}





int main()
{
    vector<int> nums1, nums2, nums3, nums4;
    int input;
    while (cin >> input) {
        nums1.push_back(input);
        if (cin.get() == '\n') break;
    }

    while (cin >> input) {
        nums2.push_back(input);
        if (cin.get() == '\n') break;
    }

    while (cin >> input) {
        nums3.push_back(input);
        if (cin.get() == '\n') break;
    }

    while (cin >> input) {
        nums4.push_back(input);
        if (cin.get() == '\n') break;
    }

    cout << fourSum(nums1, nums2, nums3, nums4) << endl;


    return 0;
}
