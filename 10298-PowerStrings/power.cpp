
// Acepted

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    while(cin >> s && s != ".")
    {
        int b[s.size()], n = s.size();

        b[0] = 0;
        for(int i = 1; i < n; i++)
        {
            b[i] = b[i-1];
            while(b[i] > 0 && s[i] != s[b[i]]) b[i] = b[b[i]-1];
            if(s[i] == s[b[i]]) b[i]++;
        }
        int u = s.size() - b[s.size()-1];
        cout << s.size() / u << endl;
    }
}
