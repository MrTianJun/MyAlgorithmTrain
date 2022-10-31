#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isAnagram(string s1, string s2)
{
    int siz1 = s1.size();
    int siz2 = s2.size();
    if (siz1 != siz2) return false;

    vector<int> record(26, 0);
    for (int i = 0; i < siz1; i++) {
        record[s1[i] - 'a']++;
    }

    for (int i = 0; i < siz2; i++) {
        record[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (record[i] != 0) return false;
    }

    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << isAnagram(s1, s2) << endl;
    return 0;
}
