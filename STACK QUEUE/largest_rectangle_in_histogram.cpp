/*
https://leetcode.com/problems/largest-rectangle-in-histogram/description/

    concpet : monotonic stack + 
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     vector <int> next_smaller_index( vector <int>& arr){
               
               int N = arr.size();

               stack < int> st;

               vector <int>nse(N);

               //. if there is no nse of arr[i], then in ans arr put its idx els put inedx - 1;

               for( int i = N -1 ; i >= 0 ; i--){

                   while( !st.empty() && arr[i] <= arr[ st.top()] ) st.pop();

                   nse[i] = st.empty() ? i : i - 1;

                   st.push( i);
               }

          return nse;
     }
     vector <int> prev_smaller_index( vector <int>& arr){
               
               int N = arr.size();

               stack < int> st;

               //. if there is no prev smaller el put then in ans arr , put the the idx of that elememt ie arr[i] is pse of itsele  else put pse_idx + 1;

               vector < int> pse (N);

               for( int i = 0; i < N; i++ ){
                    
                    while( !st.empty() && arr[i] <= arr[ st.top()] ) st.pop();

                    pse[i] =  st.empty() ? i : i + 1;
                    st.push( i);
               }

               return pse;

     }
    int largestRectangleArea(vector<int>& heights) {
        
              int N = heights.size();

              vector <int>L = prev_smaller_index(heights);
              vector <int>R = next_smaller_index( heights);

              int res = 0;

              for( int i = 0; i < N; i++){
                  int height = heights[i];
                  int width = R[i] - L[i] + 1;

              res = max( res,  height * width);

              }

              return res;
    }
};
int main(){


    return 0;
}