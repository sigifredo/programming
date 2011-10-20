
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
    rp |= base[i];
    if(rp == codif) return 1;
    int min = inf;
    for(int k = i+1; k < nBase; k++)
    {
        if((base[k]&codif) != base[k]) continue;
        int r = f(codif, nBase, base, k, rp);
        if(min > r && r > 0) min = r + 1;
    }
    return min;
}

int main()
{
    int n, m;

    while(readNM(m, n))
    {
        int base[m];
        int b2[m];
        int cod[n];

        std::memset(base, 0, m*sizeof(int));
        std::memset(b2, 0, m*sizeof(int));
        std::memset(cod, 0, n*sizeof(int));

        for(int i = 0; i < m; i++) readline(base[i]);
        for(int i = 0; i < n; i++) readline(cod[i]);

        for(int i = 0; i < m; i++)
        {
            for(int j = i; j < m; j++)
            {
                b2[i] |= base[j];
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = m-1; j >= 0; --j)
            {
                if((b2[j] & cod[i]) == cod[i])
                {
                    int r = f(cod[i], m, base, j, 0);
                    cout << ((r == inf)?0:r) << " ";
                }
            }
		cout << endl;
        }

    }

    return 0;
}
