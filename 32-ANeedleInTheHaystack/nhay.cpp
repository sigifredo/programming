
// Problem link: http://www.spoj.pl/problems/NHAY/

#include<cstring>
#include<cstdio>


bool readInt(int &n)
{
    n = std::getchar();
    if(n == EOF || n == '\n') return false;
    else
    {
        std::getchar();
        n -= 48;
        return true;
    }
}

bool readChar(char &c)
{
    c = std::getchar();
    if(c == EOF || c == '\n') return false;
    else return true;
}

int main()
{
    int n;

    while(readInt(n))
    {
        int b[n];
        char needle[n+1];

        std::memset(b, 0, n*sizeof(int));
        std::memset(needle, '\0', (n+1)*sizeof(char));

        for(int i = 0; i < n; i++) readChar(needle[i]); std::getchar();

        for(int i = 1, q = 0; i < n; i++)
        {
            if(needle[i] == needle[q]) q++;
            else q = 0;
            b[i] = q;
        }

        char c;
        int i = 0, q = 0;
        while(readChar(c))
        {
            if(c == needle[q])
            {
                q++;
                if(q == n)
                {
                    std::printf("%d\n", (i-n+1));
                    q = b[q-1];
                }
            }
            else
            {
                if(needle[q+1] == c) q = b[q+1];
                else q = 0;
            }
            i++;
        }
    }

    return 0;
}
