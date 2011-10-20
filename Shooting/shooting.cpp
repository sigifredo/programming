
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
        return (x*p.y - p.x*y < 0);
    }
};

typedef std::pair<point, point> pair;

bool sort(const pair &p1, const pair &p2)
{
    return p1.first.x < p2.first.x;
}

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
        std::sort(ps, ps+n, sort);
        int k = ps[0].first.x - 1, disp = 0;
        for(int i = 0; i < n; i++)
        {
            if(ps[i].first.x > k)
            {
                disp++;
                k = ps[i].second.x;
            }
            else
            {
                if(ps[i].second.x < k) k = ps[i].second.x;
            }
        }
        cout << disp << endl;
    }

    return 0;
}
