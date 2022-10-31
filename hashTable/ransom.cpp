#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ransom(string s1, string s2)
{
    vector<int> record(26, 0);
    int siz1 = s1.size();
    int siz2 = s2.size();

    for (int i = 0; i < siz1; i++) {
        record[s1[i] - 'a']++;
    }

    for (int j = 0; j < siz2; j++) {
        record[s2[j] - 'a']--;
    }

    for (const int& r:record) {
        if (r > 0) return false;
    }

    return true;
}




int main() 
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << ransom(s1, s2) << endl;

    return 0;
}
