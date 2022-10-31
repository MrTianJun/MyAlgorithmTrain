#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;


int getSum(int n) 
{
    int sum = 0;
    while (n) 
    {
        sum += (n % 10) * (n % 10);
        n = n / 10;
    }
    return sum;
}

bool happyNum(int n) 
{
    unordered_set<int> ret;
    int new_n = n;
    while (new_n != 1)
    {
        new_n = getSum(new_n);
        if (ret.find(new_n) != ret.end())
            return false;
        ret.insert(new_n);
    }

    return true;
}





int main()
{
    int n = 0;
    cin >> n;
    cout << happyNum(n) << endl;

    return 0;
}
