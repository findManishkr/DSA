/*
 https://codeforces.com/problemset/problem/1883/G1


*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for (int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// approach 1 : binary search + sorted multiset solution

void solve1() {
    int N, M;
    cin >> N >> M;

    multiset<int> msa, msb;
    msa.insert(1);

    for (int i = 2; i <= N; i++) {
        int x;
        cin >> x;
        msa.insert(x);
    }

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        msb.insert(x);
    }

    int cnt = 0;
    for (int el : msa) {
        auto it = msb.upper_bound(el);

        if (it != msb.end()) {
            msb.erase(it);
            cnt++;
        } else {
            break;
        }
    }

    cout << N - cnt << '\n';
}

// approach 2 : sorting + two pointer solution

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> arr_a(N), arr_b(N);

    arr_a[0] = 1;
    for (int i = 1; i < N; i++) {
        cin >> arr_a[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> arr_b[i];
    }

    sort(all(arr_a));
    sort(all(arr_b));

    int i = N - 1, j = N - 1;
    int cnt = 0;

    while (i >= 0 && j >= 0) {
        if (arr_a[i] >= arr_b[j]) {
            i--;
        } else {
            i--;
            j--;
            cnt++;
        }
    }

    cout << N - cnt << '\n';
}

int main() {
    setupIO();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
