#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main(int argc, char const *argv[]) { setupIO();

     int t; cin >> t;
    
       while(t--){
         int N, M; cin >> N >> M;


         multiset<int>msa, msb;
         msa.insert(1);

         for( int i = 2; i <= N; i++){
             int x; cin >> x;
             msa.insert(x);
         }

        for( int i = 1; i <= N; i++){
             int x; cin >> x;
             msb.insert(x);
        }

         int cnt = 0;

        for( int el : msa ){
        
           auto it = msb.upper_bound( el );

           if( it != msb.end() ) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
             msb.erase( msb.find(*it));
             cnt++;
             continue;
           }

             break;
        }
       
      

      cout << N - cnt <<'\n';

        }



    return 0;
}


// write two pointer solution also