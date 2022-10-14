#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(logn)
int BinarySearch(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size();
    while (left <= right) 
    {
        int middle = left + (right - left) / 2;
        if (nums[middle] > target) {
            right = middle - 1;
        }
        if (nums[middle] < target) {
            left = middle + 1;
        }
        if (nums[middle] == target) {
            return middle;
        }
        
    }
    return -1;
}


int main()
{
    int target;
    cin >> target;
    vector<int> nums;
    int input;
    while (cin >> input) 
    {
        nums.push_back(input);
    }

    cout << BinarySearch(nums, target) << endl;

    return 0;
}
