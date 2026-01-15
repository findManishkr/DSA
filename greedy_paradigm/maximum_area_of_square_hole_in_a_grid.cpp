/*

https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/?envType=daily-question&envId=2026-01-15

concept : greedy + sorting


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


class Solution {
public:
    int Longest_AP_seq( vector<int>&arr, int sz){
             int maxLen = 1;
             int currLen = 1;
            for( int i = 0; i < sz-1; i++){
                  if( arr[i]+1 != arr[i+1]){
                      currLen = 1;
                      continue;
                  }
                     currLen++ ;
                     maxLen = max( maxLen, currLen);
            }
         return maxLen;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
                 int szh = hBars.size();
                 int szv = vBars.size();   

                  sort( hBars.begin(), hBars.end());    //  hlogh 
                  sort( vBars.begin(), vBars.end());     // vlogv
              
                 int horiSideToBeRemoved = Longest_AP_seq(hBars, szh); 
                 int VertSideToBeRemoved = Longest_AP_seq(vBars, szv);

                 int sqSide = min(horiSideToBeRemoved,VertSideToBeRemoved) + 1;

                 return sqSide * sqSide;
    }
};

/*


# Solution

find max square area possible from grid of ( m + 1) * (n + 1) by romoving some bars 
from `hbars` and `vbars`


# find biggest ap seq (say lenH), in both h bars and v bars( say lenv) 


ans = [min( lenH , lenV)+1]^2

time complexity :->

       hlogh + vlogv

        




*/
int main(int argc, char const *argv[]) { setupIO();



    return 0;
}