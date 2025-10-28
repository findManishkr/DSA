#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()


// approach : prefix /maxi-mini techinueq


class Solution {
public:
    int maxProfit(vector<int>& prices) {
               int n = prices.size();
            int profit = 0;

            int mini = prices[0];

            for( int i = 1; i <  n; i++){
               
                if( prices[i] - mini  > profit ){
                      profit = prices[i] - mini;
                }

                mini = min( mini, prices[i]);

            }

            return profit;

    }
};




// approach 2 : divide and conquer
/*
  NLog(N);

*/



class Solution {
public:
    const int inf = INT_MAX;
    int f( int st, int en, vector<int>&arr ){
           if( st == en ) return 0;
           if( en - st == 1)  return arr[en] > arr[st] ? (arr[en] - arr[st]) : 0;


           // divide ops

           int mid = ( st + en ) >> 1;

           int lans = f(st, mid, arr);
           int rans = f( mid + 1, en, arr);

           // find minium in left half , max in right half 

            // and take their differ

            int mini = inf;
            int  maxi = -inf;

            for( int i = st; i <= mid; i++)
            mini = min( mini, arr[i]);

            for( int i = mid + 1; i <= en; i++)
            maxi = max( maxi, arr[i]);

            int cross = max(0, maxi - mini);




          return max( {lans, rans, cross});
    }
    int maxProfit(vector<int>& prices) {


     return f(0,prices.size()-1, prices);   
    }
};


int main(int argc, char const *argv[]) { 


    return 0;
}