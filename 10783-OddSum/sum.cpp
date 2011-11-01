
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;

    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            int a, b, sum = 0; cin >> a >> b;
            if(a%2 == 0) a++;

            for(; a <= b; a+=2) sum += a;

            cout << "Case " << (i+1) << ": " << sum << endl;
        }
    }

    return 0;
}
