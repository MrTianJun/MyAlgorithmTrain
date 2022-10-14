#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<int> sortedSquares(vector<int> nums) 
{
    int siz = nums.size();
    int left = 0;
    int right = siz - 1;
    vector<int> ret(siz, 0);
    int idx = siz - 1;
    while (left <= right)
    {
        int leftSqu = nums[left] * nums[left];
        int rightSqu = nums[right] * nums[right];
        if (leftSqu > rightSqu) {
            ret[idx--] = leftSqu;
            left++;
        }

        if (leftSqu <= rightSqu) {
            ret[idx--] = rightSqu;
            right--;
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

    vector<int> ret = sortedSquares(nums);

    for (const int& e:ret) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
