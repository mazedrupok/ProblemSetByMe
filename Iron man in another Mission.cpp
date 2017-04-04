#include <bits/stdc++.h>
using namespace std;
bool row[1001] = {0};
bool col[1001] = {0};
bool c1[2001] = {0};
bool c2[2001] = {0};
int main ()
{
    //ios::sync_with_stdio(0); cin.tie(0); //read("in.txt");
    clock_t start;
    double duration;

    start = clock();

    /* Your algorithm here */
    freopen ("in.txt", "r", stdin);
    freopen ("outMazed.txt", "w", stdout);
    int r, c, k, x, y, tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d %d", &r, &c, &k);
        memset (row, 0, sizeof (row));
        memset (col, 0, sizeof (col));
        memset (c1, 0, sizeof (c1));
        memset (c2, 0, sizeof (c2));
        while (k--) {
            scanf (" %d %d", &x, &y);
            row[x] = 1;
            col[y] = 1;
            c1[x+y-1] = 1;
            c2[r-x+y] = 1;
        }
        bool temp = 1;
        for (int i = 1; i <= r && temp; i++) {
            for (int j = 1; j <= c && temp; j++) {
                if (row[i] == 0 && col[j] == 0 && c1[i+j-1] == 0 && c2[r-i+j] == 0) temp = 0;
            }
        }
        printf ("Case %d: ", ++cs);
        if (temp == 1) {
            printf ("YES\n");
        }
        else printf ("NO\n");
    }

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    //cout<<"Time: "<< duration <<'\n';
    return 0;
}
