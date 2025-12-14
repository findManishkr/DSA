/*

https://codeforces.com/contest/1691/problem/B



*/

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
       while( t--){

         int n ; cin >> n;
         vector<int>shoeSize(n) ;
         loop(i,0,n) cin >> shoeSize[i];

        
          map < int, vector<int>> fm;

         loop(i,0,n){
             fm[ shoeSize[i] ].push_back( i+1);
         }

          
              bool Poss = true;
             for(auto x : fm){
             if( x.second.size() <= 1){
                 Poss = false;
                 break;
             }    
            }


             if( Poss){
           vector<int> ans;

           for(auto x : fm){
            
        
            vector<int>temp = x.second;
            int sz = temp.size();

            ans.push_back( temp[sz-1]);
            for( int i = 0;i < sz -1; i++)
            ans.push_back( temp[i]);
         }

          for( int el : ans )
          cout << el <<' ';

          cout << '\n';

        }else{
             cout << -1 <<'\n';
        }
         

         
       }



    return 0;
}

/*

edge case 


never ever write `return 0` keyword in main function, handle it using boolean 
or some other methos 



*/