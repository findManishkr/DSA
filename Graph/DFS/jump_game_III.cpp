/*
  topic : simple dfs - bfs , initially i thought it is dp problem , but there may be cycle in it , that leads
  to infinite recursion ie stack overflow

  link : https://leetcode.com/problems/jump-game-iii/?envType=study-plan-v2&envId=graph-theory


*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     vector < bool >vis;
    bool f( vector <int>&arr, int idx ){
        if( idx < 0 || idx >= arr.size()  || vis[idx] ) return false;
        if( arr[idx] == 0 ) return true;

          vis[idx] = 1;

           bool ans  = false;
        ans = f( arr, idx + arr[idx]) || f( arr, idx - arr[idx] );

        return  ans;
    }
    bool canReach(vector<int>& arr, int start) {
           vis.assign(arr.size(),0);
           return f( arr, start);
    }



// bfs solution 
 bool canReach( vector<int>&arr, int start){


      unordered_set <int> seen;
      seen.insert( start );
      queue<int>q;
      q.push( start );

       while( !q.empty() ){

        int idx = q.front(); q.pop();

          if( arr[idx] == 0 ) return true;

          if( idx + arr[idx] < arr.size() &&   !seen.count( idx + arr[idx]) )  {
            q.push( idx + arr[idx]);
            seen.insert( idx + arr[idx]);
          }

            if( idx - arr[idx] >= 0  &&  !seen.count( idx - arr[idx]) )  {
                  q.push( idx - arr[idx]);
                seen.insert( idx - arr[idx]);
          }

       }

       return false;

    }

};
int main(){

    return 0;
}