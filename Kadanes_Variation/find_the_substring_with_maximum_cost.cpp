/*
https://leetcode.com/problems/find-the-substring-with-maximum-cost/

concpet : variation of kadanes algo 

*/


#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

class Solution {
public:
     const int inf = 1e9;
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {

           unordered_map< char,int> mp;

           for( int i= 0; i < chars.size(); i++)
                  mp[ chars[i] ] = i;

            
             vector < int > arr;

            for( char ch : s){
                if( mp.count( ch) )
                 arr.push_back( vals[ mp[ch] ])   ;
                else{
                    arr.push_back( ch - 'a' + 1);
                }
            }

        // now find the maximum subarray sum of arr;

          int sum = 0, maxi = -inf;

          for( int i = 0; i < arr.size(); i++){

                sum += arr[i];
               if( sum < 0){
                    sum = 0;
               }
                maxi = max( maxi, sum);
             


              
          }

        return max(0,maxi);  
    }
};

/*

 problem is reduced down to maximum subarray sum;

*/

int main(int argc, char const *argv[]) { // setupIO();



    return 0;
}