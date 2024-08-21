// https://codeforces.com/contest/2001/submission/277426071

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt; cin >> tt;

    while(tt--) {
        int n; cin >> n;
        vector<int>parent(n + 1);

        auto f = [&](int i, int node, auto &&self) -> void {
            cout << "? " << i << " " << node << endl;
            int x; cin >> x;
            if(x == i) parent[node] = i;
            else self(x, node, self);
        };

        for(int i = 2; i <= n; i++) f(1, i, f);

        cout << "! ";

        for(int i = 2; i <= n; i++) {
            cout << i << " " << parent[i] << " ";
        }

        cout << endl;
    }
}