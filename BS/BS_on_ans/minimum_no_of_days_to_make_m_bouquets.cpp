/*

https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i, a, b) for(int i = (a); i <= (b); i++)

const int mod = 1e9 + 7;
void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}

#define ll long long 
class Solution {
public:
    bool f( vector<int>&bd , int m , int d, int k){

        int cnt = 0, res = 0;
   
           for( int i = 0; i < bd.size(); i++){
             
             if( d >= bd[i] ) cnt++;
             else
               cnt = 0;
             

             if( cnt == k){
                 res++;
                 cnt = 0;
             }

           }

        return ( res >=  m );

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
           if( 1LL * bloomDay.size() < 1LL* m * k) return -1;
          

         int low = 1;
         int high = *max_element( bloomDay.begin(), bloomDay.end());  // o(N)
      
           int ans = -1;
         while(  high - low >= 0 ){
          
         
          int mid =  low + ( high - low ) /2;

          if( f( bloomDay, m, mid, k) ){
             ans = mid;
             high = mid -1;
          }else{
             low = mid + 1;
          }


         }

         return ans;
    }
};

/*
    1482. Minimum Number of Days to Make m Bouquets

    `To Find`: min no of days I will have to wait to make `m` bouquets,
               where each bouquet requires `k` adjacent flowers

    `Observations`:
    1 - I have to make `m` bouquets using `k` adjacent flowers
    2 - ith flower blooms on bloomDay[i] (after that it can be used)
    3 - A flower can only be used in one bouquet
    4 - If total flowers < m * k → it's impossible → return -1 early

    `Expected Complexity`:
    - Time: O(N * log(M)), where N = size of bloomDay, M = range of days
    - Space: O(1)

    `My Approach`:
    1 - From the problem statement, it clearly looks like
        a **minimisation problem using binary search on the answer space**

    2 - I will binary search on the number of days required to make m bouquets

    3 - My search space will be: 
        low = 1
        high = max(bloomDay[i]) → the last day any flower blooms

    4 - For each mid in binary search:
        - I will check if it's possible to make m bouquets by `mid` days
        - I will write a helper function `f(...)` that checks this using a greedy approach:
              - Count how many consecutive flowers are bloomed by `mid` day
              - Every time I get k such flowers → make one bouquet
              - Reset counter after each bouquet

    5 - If f(...) returns true:
           → means I can make `m` bouquets by `mid` day
           → try to reduce days → high = mid - 1
           → store ans = mid
        Else:
           → means not enough bloomed flowers → increase wait → low = mid + 1

    6 - Edge Case:
        - If total required flowers (m * k) > bloomDay.size() → return -1

    7 - Binary Search guarantees minimal day when f(...) first becomes true

    `Conclusion`:
    - Problem solved using binary search on days
    - Greedy helper function checks feasibility in O(N)
    - Efficient and handles all constraints up to 1e5 elements and 1e9 values


*/


 int main(){  setupIO();

 
    return 0;
}