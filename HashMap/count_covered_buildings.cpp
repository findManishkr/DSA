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

// solution1 : approach -> hashmap

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
           int cnt = 0;

           map < int, set < int> >mp1;   //( same x : all diff y val)
           map < int, set < int> >mp2;    // ( same y : all diff x val )

          for( auto v : buildings){
               mp1[ v[0] ].insert(v[1]);
               mp2[ v[1] ].insert(v[0]);
          }


        
          for( auto v : buildings){
              int xc = v[0], yc= v[1];

              bool hz = false, vr = false;       /// horizontal check vertical check

              auto it1 = (mp1[xc]).find( yc );
              auto it2 = (mp2[yc]).find( xc );

              if( it1 != mp1[xc].begin() && ++it1 != mp1[xc].end())
                  vr = true;
              if( it2 != mp2[yc].begin() && ++it2 != mp2[yc].end() )
                  hz = true;

              if( hz && vr )
              cnt++;
              
          }

        return cnt;
    }

    /*
        //time and space complexity

        for each query , log(N) time is taken to process
        
        so for N queries

        // time = Nlog(N)

        // space 

          O(N)

    
    */
};

// add O(N) time solution here

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}