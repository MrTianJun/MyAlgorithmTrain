#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
// voilent
vector<int> twoSum(vector<int> nums, int target)
{
    int siz = nums.size();
    int i, j;
    for (i = 0; i < siz; i++) {
        for (j = 0; j < siz; j++) {
            if (i != j && nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
*/

vector<int> twoSum(vector<int> nums, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        auto iter = map.find(target - nums[i]);
        if (iter != map.end()) {
            return {iter->second, i};
        }
        map.insert(pair<int, int>(nums[i], i));
    }
    return {-1, -1};
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

    vector<int> ret = twoSum(nums, target);
    for (int r:ret)
        cout << r << " ";
    cout << endl;


    return 0;
}
