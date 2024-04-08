#include <bits/stdc++.h>

using namespace std;


string isValid(string s) {
    unordered_map<char, int> charCount;
    unordered_map<int, int> freqCount;


    for (char c : s) {
        charCount[c]++;
    }

    for (auto& pair : charCount) {
        freqCount[pair.second]++;
    }

    if (freqCount.size() == 1) {
        return "YES";
    }

    if (freqCount.size() > 2) {
        return "NO";
    }

    auto it = freqCount.begin();
    int freq1 = it->first;
    int count1 = it->second;
    ++it;
    int freq2 = it->first;
    int count2 = it->second;

    if ((count1 == 1 && (freq1 == freq2 + 1 || freq1 == 1)) || (count2 == 1 && (freq2 == freq1 + 1 || freq2 == 1))) {
        return "YES";
    }

    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
