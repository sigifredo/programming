
// Problem link: http://www.spoj.pl/problems/NHAY/

#include<cstring>
#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

// bool readInt(int &n)
// {
//     int e;
//     n = 0;
//     while(e = std::getchar())
//     {
//         if(e == '\n') return 1;
//         else if(e == EOF) return 0;
//         n = (n * 10) + (e-48);
//     }
//     return 0;
// }
// 
// bool readChar(char &c)
// {
//     c = std::getchar();
//     if(c == EOF || c == '\n') return false;
//     else return true;
// }

int main()
{
    int n;
    bool first = true;

    while(cin >> n)
    {
	if(not first) std::puts("");
	else first = false;

        int b[n];
	string needle;
	string haystack;
//         char needle[n+1];

        std::memset(b, 0, n*sizeof(int));
//         std::memset(needle, '\0', (n+1)*sizeof(char));

//         for(int i = 0; i < n; i++) readChar(needle[i]); std::getchar();
	cin >> needle;
	cin >> haystack;

        for(int i = 1, q = 0; i < n; i++)
        {
            if(needle[i] == needle[q]) q++;
            else q = 0;
            b[i] = q;
        }

        char c;
        int i = 0, q = 0;
        while(i < haystack.size())
        {
	    c = haystack[i];
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
		if(q > 0)
		{
		}
                if(needle[q+1] == c) q = b[q+1];	// ver aquí
                else q = 0;				// ver aquí
            }
            i++;
        }

//          Definición de variables:
//    un entero, m ← 0 (puntero de examen en S)
//    un entero, i ← 0 (la posición del caracter actual en W, y avance relativo respecto de m, para S)
//    un array de enteros, T (la tabla, calculada a continuación, o en otra parte)
//  Si tamaño de S es mayor o igual que tamaño de W entonces
//    Precalcular TablaKMP(W,T)
//    Mientras m + i es menor que la longitud de S, hacer
//      Si W[i] = S[m + i] entonces
//        Si i es igual a la longitud de W - 1 entonces
//          Devolver m
//        Fin si
//        Asignar i ← i + 1
//      Si no entonces
//        Asignar m ← m + i - T[i]
//        Si i es mayor que 0 entonces
//          Asignar i ← T[i]
//        Fin si
//      Fin si
//    Repetir
//  Fin si
    }

    return 0;
}
