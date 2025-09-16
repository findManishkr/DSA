/*
https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/?envType=daily-question&envId=2025-09-16


 concept : greedy + stack + observation 

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd ( int a, int b){
        if( a == 0 ) return b;
        return gcd( b%a, a);
    }
    int lcm( int a, int b){
        return ( a / gcd(a,b) )  * b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
             int n = nums.size();

                stack < int > st;
             
               for( int i = 0; i < nums.size(); i++){

                 if( !st.empty() ){
                   
                   if( gcd( st.top(), nums[i]) > 1 ){
                        int x = lcm( st.top(), nums[i]);
                        st.pop();
                        st.push( x);
                   }else if( gcd( st.top(), nums[i]) == 1 ) {
                        st.push( nums[i]);
                   }



                 }else{
                      st.push( nums[i]);
                 }

               }

                vector<int> ans;
               while( !st.empty() ){
                 ans.push_back(st.top());
                  st.pop();
               }
                 reverse( ans.begin(), ans.end());
               return ans;
    }
};

int main(){


    return 0;
}