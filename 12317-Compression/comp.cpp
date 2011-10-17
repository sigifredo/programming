
#include<iostream>
#include<list>

using std::cout;
using std::cin;
using std::endl;

typedef std::list<int> lst;
typedef std::list<lst> llist;

bool readNM(int &m, int &n)
{
    cin >> m >> n;
    if(n == 0 && m == 0) return false;
    else return true;
}

void readline(lst &l)
{
    int n, aux;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        l.push_back(aux);
    }
}

int main()
{
    int n, m;

    while(readNM(m, n))
    {
        lst base[m];
        lst cod[n];

        for(int i = 0; i < m; i++) readline(base[i]);
        for(int i = 0; i < n; i++) readline(cod[i]);


    }

    return 0;
}
