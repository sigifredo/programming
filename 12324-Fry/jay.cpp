
#include<iostream>
#include<cstring>

#define MIN(X, Y)	(X < Y)?X:Y

using std::cin;

bool read(int &n)
{
    cin >> n;
    if(n == 0) return false;
    else return true;
}

int main(int argc, char **argv)
{
    int n;
    while(read(n))
    {
        int t[n];
        int dm[n];
        int balls = 0;
        int bMax = 0;

        for(int i = 0; i < n; i++) {
            cin >> t[i] >> dm[i];
            balls += dm[i];
            if(bMax < dm[i]) bMax = dm[i];
        }

        bMax += balls;

        int dp[n+1][bMax +1];

        memset(dp, -1, (n)*(bMax+1)*sizeof(int));
        memset(dp[n], 0, (bMax+1)*sizeof(int));

        for(int i = n-1; i >= 0; i--)
        {
            for(int b = 0; b <= balls; b++)
            {
                if(b > 0)
                {
                    dp[i][b] = MIN(t[i] + dp[i+1][b+dm[i]], (t[i]/2) + dp[i+1][b-1+dm[i]]);
                }
                else dp[i][b] = t[i] + dp[i+1][b+dm[i]];
            }
        }
        std::cout << dp[0][0] << std::endl;
    }
    return 0;
}