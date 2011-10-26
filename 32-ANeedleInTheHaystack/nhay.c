
// Problem link: http://www.spoj.pl/problems/NHAY/

#include<string.h>
#include<stdio.h>


int readInt(int * n)
{
    int e;
    *n = 0;
    while(e = getchar())
    {
        if(e == '\n') return 1;
        else if(e == EOF) return 0;
        *n = (*n * 10) + (e-48);
    }
    return 0;
}

int readChar(char * c)
{
    *c = getchar();
    if(*c == EOF || *c == '\n') return 0;
    else return 1;
}

int main()
{
    int n;

    while(readInt(&n))
    {
        int b[n], i, q;
        char needle[n+1];

        memset(b, 0, n*sizeof(int));
        memset(needle, '\0', (n+1)*sizeof(char));

        for(i = 0; i < n; i++) readChar(&needle[i]);
        getchar();

        for(i = 1, q = 0; i < n; i++)
        {
            if(needle[i] == needle[q]) q++;
            else q = 0;
            b[i] = q;
        }

        char c;
        int e = 0;
        i = q = 0;
        while(readChar(&c))
        {
            if(c == needle[q])
            {
                q++;
                if(q == n)
                {
                    printf("%d\n", (i-n+1));
                    q = b[q-1];
                    e++;
                }
            }
            else
            {
                if(needle[q+1] == c) q = b[q+1];
                else q = 0;
            }
            i++;
        }
        if(e == 0) puts("");
    }

    return 0;
}