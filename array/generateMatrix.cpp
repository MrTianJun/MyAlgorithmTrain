#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ret(n, vector<int>(n, 0));
    int num = 1;
    int loop = n - 2;
    int startx = 0;
    int startz = 0;
    int offset = 1;
    int mid = n / 2;
    int i, j;

    while (loop--) {
        i = startx;
        j = startz;

        for (; i < n - offset; i++) {
            ret[j][i] = num++;
        }

        for (; j < n - offset; j++) {
            ret[j][i] = num++;
        }

        for (; i > startx; i--) {
            ret[j][i] = num++;
        }

        for (; j > startz; j--) {
            ret[j][i] = num++;
        }

        startx++;
        startz++;
        offset++;
    }

    if (n % 2) {
        ret[mid][mid] = num;
    }

    return ret;
}



int main()
{
    int target;
    cin >> target;
    vector<vector<int>> ret = generateMatrix(target);

    for (const auto& row : ret) {
        for (const auto& ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}


