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

int main(int argc, char const *argv[]) { setupIO();


    class Solution {
public:
 vector < vector< vector< vector <int> > > >dp;
    int f( int r1, int c1, int r2, int c2, vector<vector<int>>& grid ,int M, int N ){

           // base case 
        
               // - early pruning
             
              if( c1 < 0 || c1 >= N || c2 < 0 || c2 >= N ) return 0;
              if( r1 == r2 && c1 == c2 ) return 0;

              // final answer return 
              if( r1 == M && r2 == M ) return 0;

               if( dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];


           


              int res = 0;


              for( int a = -1; a <= 1; a++){
                for( int b = -1 ; b <= 1; b++ )
                    res = max( res, f(r1+1, c1 + a, r2+1, c2+b,grid, M, N) );
              }

           





           return dp[r1][c1][r2][c2] =  grid[r1][c1] + grid[r2][c2] + res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
            int M = grid.size();
            int N = grid[0].size();

                     int x  = max(M,N) + 1;
                 dp.clear();  dp.resize( x , vector<vector<vector<int>>>(x, vector< vector<int>>( x , vector< int>(x, -1))) );

           return f(0,0, 0, N -1,grid,M, N);
        
    }
};

/*
    # deciphering the problem statemnt

    - grid[i][j] - no. cherries collected
    - robot1 @ (0,0), robot2 @( 0, cols -1);
    - * rule\
         |-> (i,j) -> ( i + 1, j -1) , (i+1,j), ( i + 1,j + 1)
         |-> when a robot pass (i,j) -> picks up all grid[i][j] = 0;
         |-> at (i,j) both present -> only one any robot takes cheery
         |-> both robots shuld rich bootom row
         |-> both robots cn't move outside grid any moment


    # REturn 
     -  max. no cherries collect by both robots under rules


    # expected time complexity
     - M , N = [2, 70] 


     -Assumption :
       f(r1,c1, r2, c2) -> return the max. number of cherries collection using both robots from( {(r1,c1), (r2,c2)});


    f(r1,c1, r2, c2) =   grid[r2][c2] + res;

         where res = 
         ```
              int res = 0;
              for( int a = -1; a <= 1; a++){
                for( int b = -1 ; b <= 1; b++ )
                    res = max( res, f(r1+1, c1 + a, r2+1, c2+b,grid, M, N) );
              }

           ```   

         above maxi of nine calls + curr both roboots grid collection  gives the answer

           

         ``
          this solution can be converted to dp
         ``


*/





    return 0;
}