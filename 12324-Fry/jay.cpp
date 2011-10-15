
#include<iostream>

#ifdef DEBUG
#    define print(X)	std::cout << __LINE__ << " - " << X << std::endl
#else
#    define print(X)
#endif
#define MIN(X, Y)	(X < Y)?X:Y

using std::cin;

bool read(int &n)
{
    cin >> n;
    if(n == 0) return false;
    else return true;
}

int f(int n, int * t, int * dm, int i = 0, int b = 0)
{
    if(i == n)
    {
        print(i << " -> " << 0);
        return 0;
    }

    if(b > 0)
    {
        int a =  t[i]    + f(n, t, dm, i+1, b   + dm[i]); // l1
        int b = (t[i]/2) + f(n, t, dm, i+1, b-1 + dm[i]); // l2

        int m = MIN(a, b);
        print(i << "\ta: " << a << "\tb: " << b);
        print(i << " -> " << m);

        return MIN(a, b);
    }
    else
    {
        int m =  t[i]    + f(n, t, dm, i+1, b   + dm[i]); // l3
        print(i << " -> " << m);
        return m;
    }
}

int main(int argc, char **argv)
{
    int n;
    while(read(n))
    {
        int t[n];
        int dm[n];

        for(int i = 0; i < n; i++) {
            cin >> t[i];
            cin >> dm[i];
        }

        for(int i = 0; i < n; i++) {
            print(t[i]);
        }

        std::cout << f(n, t, dm) << std::endl;
    }
    return 0;
}
