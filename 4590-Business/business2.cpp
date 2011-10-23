
#include<iostream>
#include<cstring>
#include<cstdio>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int n, m, oo=1<<28;

    while(cin >> n >> m)
    {
        int min = oo;
        for(int i = 0; i < m; i++)
        {
            int u, d; cin >> u >> d;

            int j = n*d/(u+d)+1;

            int aux = (u+d)*j-n*d;;

            if(min > aux) min = aux;
        }

        cout << min << endl;
    }

    return 0;
}
