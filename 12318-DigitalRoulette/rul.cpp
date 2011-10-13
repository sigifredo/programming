
#include<iostream>
#include<map>

using namespace std;

typedef long long lint;

bool leerNM(int &n, int &m)
{
    cin >> n >> m;

    if(n == 0 && m == 0) return false;
    else return true;
}

lint pol(int k, int x, int * coef, int n)
{
    lint p = 0LL;
    lint xx = 1LL;

    for(int i = 0, j = 0; i <= k; i++, ++j)
    {
        lint w = (coef[i]%n * xx%n)%n;
        p = (p%n + w%n)%n;
        xx = ((xx%n) * (x%n))%n;
    }

    return p%n;
}

int main(int argc, char** argv)
{
    int n, m, k;

    while(leerNM(n, m))
    {
        cin >> k;

        int c[k+1];

        for(int i = 0; i <= k; i++) cin >> c[i];

        map<lint, bool> num;

        for(int i = 0; i <= m; i++)
        {
            lint r = pol(k, i, c, n+1LL);
            num[r] = true;
        }

        cout << num.size() << endl;
    }

    return 0;
}
