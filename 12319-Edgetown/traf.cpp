
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

#define MIN(X, Y)   (X < Y)?X:Y
#define BUF         500
#define print(X)    cout << X << endl
#define debug()     cout << __LINE__ << endl

int inf = 1 << 28;

int main(int argc, char **)
{
    int n, A, B;

    while(cin >> n)
    {
MIENTRAS:
        char linea[500];

        int d1[n][n];
        int d2[n][n];

        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
            {
                if(i == j) d1[i][i] = d2[j][j] = 0;
                else d1[i][j] = d2[i][j] = inf;
            }

        for(int i = 0; i < n; i++)
        {
            cin.getline(linea, 500);
            stringstream ss(linea);
            int aux;
            ss >> aux;
            while(ss >> aux)
            {
                d1[i][aux-1] = 1;
            }
        }

        for(int i = 0; i < n; i++)
        {
            cin.getline(linea, 500);
            stringstream ss(linea);
            int aux;
            ss >> aux;
            while(ss >> aux)
            {
                d2[i][aux-1] = 1;
            }
        }

        {
            cin.getline(linea, 500);
            stringstream ss(linea);
            ss >> A;
            ss >> B;
        }

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                {
                    d1[i][j] = MIN(d1[i][j], d1[i][k] + d1[k][j]);
                    d2[i][j] = MIN(d2[i][j], d2[i][k] + d2[k][j]);

                }

        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(d2[i][j] > (A*d1[i][j]+B))
{
                    cout << "No" << endl;
                    goto MIENTRAS;
                }

        cout << "Yes" <<endl;

    }
    return 0;
}
