#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define ll long long
#define inf INT_MAX
int main(int argc, char const *argv[]) { 

int n; cin >> n;

vector<ll>arr(n);
loop(i,0,n) cin >> arr[i];

ll maxEndinghere = 0, maxSoFar = -inf;

loop(i,0,n){

    maxEndinghere += arr[i];

    maxSoFar = max(maxSoFar, maxEndinghere);

    if( maxEndinghere < 0){
        maxEndinghere = 0;
    }
}


  cout << maxSoFar <<'\n';

    return 0;
}