#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()


struct Pair{
int x;
int y;
};


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
          int M = grid.size();
          int N = grid[0].size();
          vector < int> dir = { -1,0,1,0,-1};

          queue < Pair > q;

          int time = 0, freshOrange  = 0;


          for( int i = 0; i < M; i++){
             for( int j = 0;j < N; j++){
                 if( grid[i][j] == 2){
                    q.push( {i,j});
                 }else if( grid[i][j] == 1){
                    freshOrange++;
                 }
             }
          }


          while( !q.empty() && freshOrange > 0 ){

           int sz = q.size();

           for( int idx = 0;idx < sz; idx++){
             
                  auto node = q.front(); q.pop();
                  int i = node.x, j = node.y;

                for( int k = 0; k < 4; k++){
                    int nx = i + dir[k], ny = j +  dir[k+1];

                    if( nx < 0 || nx >= M || ny < 0 || ny >= N || grid[nx][ny] != 1) continue;

                    q.push( {nx,ny});
                    freshOrange--;
                    grid[nx][ny] = 2;    // mark rotted
                }
                   
           }

           time++;
          }


            if( freshOrange == 0 ) return time ;

            return -1;
    }
};

int main(int argc, char const *argv[]) { 



    return 0;
}


/*
Intuition
- Rotten oranges spread to adjacent fresh oranges in one time unit (like a virus spreading).
- Use multi-source BFS: start from all rotten oranges simultaneously and expand outward in layers.
- Each layer represents one time unit. Count layers until all reachable fresh oranges are rotted or none remain.

Approach
- Scan the grid, count fresh oranges (1), and enqueue all initially rotten oranges (2).
- Perform level-order BFS: for each time unit, process all rotten oranges at the current level.
- For each rotten orange, infect adjacent fresh oranges (up, down, left, right) and enqueue them.
- Stop when queue is empty. If any fresh orange remains, return -1; otherwise return the time elapsed.
- Time: O(M × N), Space: O(M × N) for the queue in worst case.

Code Explanation
- struct Pair: simple structure to store (x, y) coordinates of a cell.

- vector<int> dir = {-1, 0, 1, 0, -1}:
    - Encodes 4 directions: up (-1,0), right (0,1), down (1,0), left (0,-1).
    - Accessed as dir[k] and dir[k+1] for the pair at position k.

- int time = 0, freshOrange = 0:
    - time: counts the number of minutes elapsed.
    - freshOrange: count of unrotted oranges (decrements as they rot).

- First loop (initialization):
    - Finds all initially rotten oranges (grid[i][j] == 2) and enqueues them.
    - Counts total fresh oranges (grid[i][j] == 1).

- Main BFS loop (while !q.empty() && freshOrange > 0):
    - int sz = q.size(): number of rotten oranges at the current time level.
    - Inner for loop (idx < sz): processes all rotten oranges at this level.
    
    - auto node = q.front(); q.pop(): extract the current rotten orange's position.
    
    - Direction loop (k < 4):
        - int nx = i + dir[k], ny = j + dir[k+1]: calculate neighbor coordinates.
        - Bounds check (nx/ny must be within grid) and state check (neighbor must be fresh, grid[nx][ny] == 1).
        - If valid and fresh:
            - q.push({nx, ny}): enqueue the newly rotted orange.
            - freshOrange--: decrement fresh orange count.
            - grid[nx][ny] = 2: mark as rotten to avoid re-processing.
    
    - time++: increment time after processing all oranges at this level.

- Return logic:
    - If freshOrange == 0: all fresh oranges rotted, return time.
    - Otherwise: some fresh oranges isolated, return -1.

Complexity Analysis
- Time: O(M × N) — each cell visited at most once.
- Space: O(M × N) — queue can hold up to all cells in worst case (all rotten).
*/
