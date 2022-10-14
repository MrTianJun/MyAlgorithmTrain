#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

/*
// violent solution
int minSubArrayLen(vector<int> nums, int target)
{
    int siz = nums.size();
    int min_len = INT32_MAX;

    for (int i  = 0; i < siz; i++) {
        int sum = 0;
        for (int j = i; j < siz; j++) {
            sum += nums[j];
            if (sum >= target) {
                int len = j - i + 1; 
                min_len = len < min_len ? len : min_len;
                break;
            }
        }
    }

    return min_len == INT32_MAX ? 0 : min_len;
}
*/


// slide window
int minSubArrayLen(vector<int> nums, int target)
{
    int siz = nums.size();
    int min_len = INT32_MAX;

    int i = 0;
    int sum = 0;
    for (int j = i; j < siz; j++) {
        sum += nums[j];

        // core code
        while (sum >= target) {
            int len = j - i + 1;
            min_len = len < min_len ? len : min_len;
            sum -= nums[i++];
        }
    }

    return min_len == INT32_MAX ? 0 : min_len;
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

    cout << minSubArrayLen(nums, target) << endl;

    return 0;
}
