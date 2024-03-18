#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(string a, string b) {
    int anagram = 0;
     
    for (char k : a) {
        int f = b.find(k);
        if(f == std::string::npos){
            continue;
        } else {
            int d = a.find(k);
            a[d] = '1';
            b[f] = '1';
            anagram +=2;
            
        }
    
    }
   
    anagram = (a+b).size() - anagram;

    return anagram;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
