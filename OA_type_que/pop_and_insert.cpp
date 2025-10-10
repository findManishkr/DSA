

/*
https://atcoder.jp/contests/abc426/tasks/abc426_d


*/



#include <bits/stdc++.h>
using namespace std;

int f(string s, char Charr,int n ) {
     
    int MaxCharrLen = 0,  CurrCharrLen = 0;
    int totalOps = 0;

     for( int i = 0; i < n; i++){

       if( s[i] == Charr){
              CurrCharrLen++;
              MaxCharrLen = max( MaxCharrLen, CurrCharrLen);
             totalOps += 2;
        }else{
           CurrCharrLen = 0;
            totalOps += 1;

        }
   
       }

       return (totalOps - 2*MaxCharrLen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string s;
        cin >> s;

       
        cout << min(f(s, '0',N), f(s, '1',N)) << '\n';
    }

    return 0;
}
