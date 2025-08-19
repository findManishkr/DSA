/*


https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/


  concept : normal bfs + extra catch : identify nodes uniquely

   ie : BFS on (x,y,r) x,y is coordinate, r is remain number of obstacles you can remove.
*/


#include <bits/stdc++.h>
using namespace std;
 //  solution 1

#define tp tuple <int,int,int>
class Solution {
public:
   vector < vector <int>>dir = { {1,0}, {0,1}, {-1,0},{0,-1} };
    int shortestPath(vector<vector<int>>& grid, int k) {
          int M = grid.size(), N = grid[0].size();

        vector<  vector < vector <int>>>dist( M,  vector < vector <int>>( N, vector <int>(k + 1, -1)));
         vector< vector < vector <bool>>>vis(M,  vector <vector<bool>>(N,  vector <bool>(k + 1, 0) )); 


           queue <  tp > q;
           q.push( {0,0,k});
           vis[0][0][k] = 1;
           dist[0][0][k] = 0;
           

           while( !q.empty() ){

          auto [i, j, ll] = q.front(); q.pop();

               // process node (i,j)

               if( i == M -1 && j == N -1 && ll >= 0)
                 return dist[ M -1][ N -1][ll];




               for( auto x : dir ){
                  int nx = i + x[0], ny = j + x[1];

                  if( nx < 0 || nx >= M || ny < 0|| ny >= N ) continue;

                    if( grid[nx][ny] ==  1 && ll > 0 &&  !vis[ nx][ny][ll-1] ){
                          q.push( {nx, ny, ll -1 });

                          vis[nx][ny][ll-1] = 1;
                       dist[nx][ny][ll-1] = 1 + dist[i][j][ll];

                    } else if( grid[nx][ny] == 0 && !vis[nx][ny][ll] ){
                         q.push( {nx,ny, ll });
                         vis[nx][ny][ll] = 1;
                        dist[nx][ny][ll] = 1 + dist[i][j][ll];

                    }

                    
               }

           }

        return -1;
    }
};



int main(){



    return 0;
}

