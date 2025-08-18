/*

https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

 concetp : easy floyad warshall

 note : floyad warshall can be applied with if -ve edge weights are present also, but edgs should not form -ve wt cylce

*/





#include <bits/stdc++.h>
using namespace std;

#define inf 1e9 
#define loop(i,a,b) for( int i = (a); i < (b); i++)
class Solution {
public:


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        

              vector <  vector < int>> dist( n, vector <int>(n,inf) );

              // dist from  node to self node is zero ie  dist[i][i] = 0  for all i belonging [0, n-1]

              for( int i = 0; i < n; i++) 
              dist[i][i] = 0;

              for( auto x : edges ){
                int a = x[0], b = x[1], wt = x[2];
                 
                 dist[a][b] = wt;
                 dist[b][a] = wt;

              }

         // floyad warshall algorithms to compute shortest path b/w all pairs of cities


         loop( k, 0, n){    // update distances for each intermediate city
            loop( i, 0, n){
                loop( j, 0, n)
                    dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j]);     // update shortest path from i to j through k
                
            }
         }   


       int ansNode = -1;
       int mini = inf;
       loop( i, 0, n){
          int cnt = 0;
          loop( j, 0, n){
            if( i== j) continue;
             if( dist[i][j] <=  distanceThreshold )
             cnt++;

          }


          if( mini >= cnt ){
             mini = cnt;
             ansNode = i;
          }

       }

       return ansNode;
    }
};


// since size of graph is very small with nodes <= 100 
// we can use `Floyad Warshall algorith `

int main(){



    return 0;
}