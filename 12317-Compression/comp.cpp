
#include<iostream>
#include<cstring>

#define print(X)	std::cout << X << std::endl

using std::cout;
using std::cin;
using std::endl;

int inf = 1 << 28;

bool readNM(int &m, int &n)
{
    cin >> m >> n;
    if(n == 0 && m == 0) return false;
    else return true;
}

void readline(int &l)
{
    int n, aux;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        aux = 1 << aux;
        l |= aux;
    }
}

int f(int codif, int nBase, int * base, int i, int rp)
{
    if((base[i] & codif) != base[i]) return inf;
    rp |= base[i];
    if(rp == codif) return 1;
    int min = inf;
    for(int k = i+1; k < nBase; k++)
    {
        int r = f(codif, nBase, base, k, rp);
        if(min > r && r > 0) min = r + 1;
    }
    return min;
}

int encode(int codif, int nBase, int * base)
{
    int min = inf;
    for(int i = 0; i < nBase; i++)
    {
        if((base[i] & codif) != base[i]) continue;

        int r = f(codif, nBase, base, i, 0);
        if(min > r && r > 0) min = r;
    }
    return (min == inf)?0:min;
}

int main()
{
    int n, m;

    while(readNM(m, n))
    {
        int base[m];
        int cod[n];

        std::memset(base, 0, m*sizeof(int));
        std::memset(cod, 0, n*sizeof(int));

        for(int i = 0; i < m; i++) readline(base[i]);
        for(int i = 0; i < n; i++) readline(cod[i]);

        for(int i = 0; i < n; i++) cout << encode(cod[i], m, base) << " ";
        cout << endl;
    }

    return 0;
}
