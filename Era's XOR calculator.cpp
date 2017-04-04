#include <bits/stdc++.h>
using namespace std;
int main ()
{
    //ios::sync_with_stdio(0); cin.tie(0); //read("in.txt");

    clock_t start;
    double duration;
    start = clock();

    freopen ("in.txt", "r", stdin);
    freopen ("outMazed.txt", "w", stdout);
    int tc, len, x, cs = 0;
    string s;
    cin >> tc;
    while (tc--) {
        cin >> s;
        len = s.length() - 1;
        if (len == 0) x = s[len] - 48;
        else x = 10 * (s[len-1] - 48) + (s[len] - 48);
        cout << "Case #" << ++cs << ": ";
        if (x %4 == 0) cout << s << endl;
        else if (x %4 == 1) cout << "1\n";
        else if (x %4 == 3) cout << "0\n";
        else if (x %4 == 2) {
            int carry = 1;
            while (carry && len >= 0) {
                int temp = s[len] - 48 + carry;
                carry = temp /10;
                s[len] = (temp %10) + 48;
                len--;
            }
            if (carry) cout << carry;
            cout << s << endl;
        }
    }


    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    //cout<<"Time: "<< duration <<'\n';

    return 0;
}
