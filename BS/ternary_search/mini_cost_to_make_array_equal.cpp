/*


https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/

concet : bitonic function , ternary search




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

// - ternary search version : tle 

#define ll long long 
#define inf 1e18
class Solution {
public:
   int N; 
   vector<int>nums;
   vector<int>cost;
    ll f( int val){
         /*
            f -> return cost incurred to make all nums el = val
         */

             ll sum = 0;

             for( int i = 0; i < N; i++)
               sum += 1LL*abs(nums[i]-val)* cost[i];

               return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
           this->N = nums.size();
           this->nums = nums;
           this->cost = cost;
          
         

          int lo = *min_element( nums.begin(),nums.end());
          int hi = *max_element( nums.begin(),nums.end());

          while( hi - lo > 3 ){


            int mid1 =  lo + (hi - lo) / 3;
            int mid2 =  hi - (hi - lo)  /  3;

               ll f1 = f(mid1);
               ll f2 = f(mid2);
            if( f1 < f2 ){
                
                hi = mid2 -1;

            }else if( f2 <= f1  ){   // function f values can be equal at mid1 and mid2
               
                lo = mid1 + 1; 

            }

          }
   
           ll ans = inf;

           for( int i = lo ; i <= hi ; i++){
              ans = min( ans, f(i));
           }




         return ans ;
    }
};


// binary search :    

#define ll long long 
#define inf 1e18
class Solution {
public:
   int N; 
   vector<int>nums;
   vector<int>cost;
    ll f( int val){
         /*
            f -> return cost incurred to make all nums el = val
         */

             ll sum = 0;

             for( int i = 0; i < N; i++)
               sum += 1LL*abs(nums[i]-val)* cost[i];

               return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
           this->N = nums.size();
           this->nums = nums;
           this->cost = cost;
          
         

          int lo = *min_element( nums.begin(),nums.end());
          int hi = *max_element( nums.begin(),nums.end());

         
           while( hi - lo > 1 ){


              ll mid = lo + ((hi-lo) >> 1);


              ll cost1 = f(mid);
              ll cost2 = f(mid-1);

              if( cost1 < cost2){
                
                lo = mid;

              }else{

                   hi = mid;

              }



           }



         return min( f(lo),f(hi));
    }
};

/*
 


    min( f(x) ) =  abs(nums[i]- x) * cost[i];

      for all x belo [min(nums[i]), max(nums[i])] and,
       for all i belo [0,n-1];


*/c

/*
 


    min( f(x) ) =  abs(nums[i]- x) * cost[i];

      for all x belo [min(nums[i]), max(nums[i])] and,
       for all i belo [0,n-1];


*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}