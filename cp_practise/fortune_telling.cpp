/*


https://codeforces.com/problemset/problem/1634/B

concept : bits + parity


(+ and ^ ) have the same parity

ie 

odd + odd = even
even + even = even 
even + odd = odd
odd + even = odd









*/




#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define ll long long
void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

bool IsSameParity( ll x, ll y){
    return ( x % 2 == y % 2);
}
int main(){ setupIO();

     int t; cin >> t;
    for( int tc = 1; tc <= t; tc++){

      ll n, x, y;
      cin >> n >> x >> y;

        ll sum = 0;
       loop(i,0,n) {
         ll el ; cin >> el;
         sum += el;
       }

       if( IsSameParity(x+sum,y) )
       cout <<"Alice\n";
       else 
       cout <<"Bob\n";
     


    }


    return 0;
}


/*
    # deciphering the problem statemnt
      - 







*/