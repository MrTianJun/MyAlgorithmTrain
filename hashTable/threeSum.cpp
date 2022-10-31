#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> nums)
{
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());


    // core code
    for (int i = 0; i < nums.size(); i++) {


        // 剪枝
        if (nums[i] > 0) break;

        // 去重a
        if (i > 0 && nums[i] == nums[i-1]) continue;

        int target = -nums[i];
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] > target)
                right--;
            else if (nums[left] + nums[right] < target)
                left++;
            else {
                ret.push_back({nums[i], nums[left], nums[right]});
                // 去重b
                while (left < right && nums[left] == nums[left+1]) left++;
                // 去重c
                while (left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            }
        }
    }

    return ret;
}



int main()
{
    vector<int> nums;
    int input;
    while (cin >> input) {
        nums.push_back(input);
    }


    vector<vector<int>> ret = threeSum(nums);
    
    cout << "End call threeSum()" << endl;
    for (const vector<int>& v:ret) {
        for (const int& e:v) {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
