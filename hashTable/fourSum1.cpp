#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target) 
{
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int siz = nums.size();

    for (int k = 0; k < siz - 3; k++) {
        if (k > 0 && nums[k] == nums[k-1]) continue;

        for (int i = k + 1; i < siz - 2; i++) {
            if (nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = siz - 1;
            while (left < right) {
                if (nums[k] + nums[i] + nums[left] + nums[right] > target)
                    right--;
                else if (nums[k] + nums[i] + nums[left] + nums[right] < target)
                    left++;
                else {
                    ret.push_back({nums[k], nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (right < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
    }

    return ret;
}

int main()
{
    int target;
    cin >> target;
    vector<int> nums;
    
    int input;
    while (cin >> input) {
        nums.push_back(input);
    }

    vector<vector<int>> ret = fourSum(nums, target);

    for (const vector<int>& v:ret) {
        for (const int& e:v) {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
