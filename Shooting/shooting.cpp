
#include<iostream>
#include<utility>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;

struct point {
    int x, y;
    point(int x = 1, int y = -1): x(x), y(y) {}
    bool operator < (const point &p) const {
        return (x*p.y - p.x*y > 0);
    }
};

typedef std::pair<point, point> pair;

int main()
{
    while(true)
    {
        int n;
        cin >> n;

        if(n == 0) break;

        pair ps[n];

        for(int i = 0; i < n; i++)
        {
            cin >> ps[i].first.x >> ps[i].first.y;
            cin >> ps[i].second.x >> ps[i].second.y;
            if(ps[i].second < ps[i].first) std::swap(ps[i].first, ps[i].second);
        }
//         cout << "coordenadas" << endl;
// 	for(int i = 0; i < n; i++)
// 	{
// 	    cout << "(" << ps[i].first.x << ", " << ps[i].first.y << ") - (" << ps[i].second.x << ", " << ps[i].second.y << ")" << endl;
// 	}
        std::sort(ps, ps+n);
// 	cout << "sort" << endl;
// 	for(int i = 0; i < n; i++)
// 	{
// 	    cout << "(" << ps[i].first.x << ", " << ps[i].first.y << ") - (" << ps[i].second.x << ", " << ps[i].second.y << ")" << endl;
// 	}
        point k;
	int shots = 0;
        for(int i = 0; i < n; i++)
        {
            if(k < ps[i].first)
            {
                shots++;
                k = ps[i].second;
            }
            else
            {
                if(ps[i].second < k) k = ps[i].second;
            }
        }
        cout << shots << endl;
    }

    return 0;
}