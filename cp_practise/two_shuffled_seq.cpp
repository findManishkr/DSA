/*
https://codeforces.com/contest/1144/problem/C

concept + `sorting + some observation`


*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define vi vector<int>
#define all(x)  (x).begin(), (x).end()

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main(int argc , char const *argv[]) { setupIO();

    int n; cin >> n; 
   

    vi arr(n);
    loop(i,0,n) cin >> arr[i];

    sort( arr.begin(),arr.end() );

    vi ins;
    set<int>seen;


    for( int i = 0; i < n; i++){
        if( ins.empty() || arr[i] > ins.back() ){
            ins.push_back( arr[i]);
            seen.insert( i);
        }
    }

    vi des;

    for( int i = n -1; i >= 0 ; i--){
        if( seen.count(i)) continue;

        if( des.empty() || arr[i] < des.back() )
        des.push_back( arr[i] );
    }
   
    if( ins.size() + des.size() < n ){
         cout << "NO\n";
    }else{
       cout <<"YES\n";
       cout << ins.size() <<'\n';
       for( int el : ins) cout << el <<' ';  
       cout << '\n';
       cout << des.size() <<'\n';
       for( int el : des ) cout << el <<' ';
       cout << '\n';


    }





    return 0;
}

/*
there is some little issue in the code 

`debug and find it`




*/