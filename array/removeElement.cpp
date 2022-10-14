#include <iostream>
#include <vector>

using namespace std;

// return new array
vector<int> removeElement(vector<int> nums, int target)
{
    int siz = nums.size();
    int slowidx = 0;
    for (int i = 0; i < siz; i++) 
    {
        if (nums[i] != target) {
            nums[slowidx++] = nums[i];
        }
    }

    // note: slowidx++, so final slowidx is the new array's length
    // take only part of an array
    vector<int> ret(nums.begin(), nums.begin() + slowidx);
    return ret;

    /*
    // or 
    return vector<int>(nums.begin(), nums.begin() + slowidx);

    // or
    vector<int> ret = vector<int>(nums.begin(), nums.begin() + slowidx);
    return ret;
    */

}

/*
// return new array's length
int removeElement(vector<int> nums, int target)
{
    int siz = nums.size();
    int slowidx = 0;
    for (int i = 0; i < siz; i++) 
    {
        if (nums[i] != target) {
            nums[slowidx++] = nums[i];
        }
    }

    // note: slowidx++, so final slowidx is the new array's length

    return slowidx;
}
*/


int main()
{
    int target;
    cin >> target;
    int input;
    vector<int> nums;

    while (cin >> input) {
        nums.push_back(input);
    }

    // return new array
    vector<int> ans = removeElement(nums, target);
    for (const auto& ele:ans) {
        cout << ele << " ";
    }
    cout << endl;

    // return the length of new array
    //cout << removeElement(nums, target) << endl;

    return 0;
}
