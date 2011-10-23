
#include<iostream>
#include<fstream>
#include<utility>
#include<cstring>
#include<map>

#define MIN(X, Y)   (X<Y)?X:Y


typedef std::map<int, int> mp;
typedef std::map<int, mp> mmap;

using namespace std;

int f(int n, int u, int d, int s, mmap &m)
{
    if(n == 0) return s;

    if(m[n][s] != 0) return m[n][s];

    if(s-d <= 0)
    {
        m[n-1][s+u] = f(n-1, u, d, s+u, m);
        return m[n-1][s+u];
    }

    m[n-1][s+u] = f(n-1, u, d, s+u, m);
    m[n-1][s-d] = f(n-1, u, d, s-d, m);

    return MIN(m[n-1][s+u], m[n-1][s-d]);
}

int main()
{
    int n, m;

    while(cin >> n >> m)
    {
        mmap _m;

        int u, d; cin >> u >> d;

        int min = f(n, u, d, 0, _m);

        for(int i = 1; i < m; i++)
        {
            cin >> u >> d;
            int a = f(n, u, d, 0, _m);
            if(a < min) min = a;
        }

        cout << min << endl;

    }

    return 0;
}