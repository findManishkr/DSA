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



class Solution {
public:
    int M, N;
    vector<vector<int>> grid;
    vector< vector<int>>dir = {{-1,0},{0,-1}, {1,0}, {0,1}};
    int  TotalSteps;
    int f(  int sr, int sc, int er, int ec ,int stepsCount ){

         if( sr < 0 || sc < 0 || sr >= M || sc >= N ||  grid[sr][sc] == -1 ) return 0;
         if( sr == er && sc == ec  )
         return  stepsCount == TotalSteps ? 1 : 0;

            int ans = 0;

          

          for( auto x : dir ){
              
                int temp =  grid[sr][sc];
                
                grid[sr][sc] = -1; // mark visited

            int nx = sr + x[0], ny = sc + x[1];
             ans += f( nx, ny, er,ec,stepsCount+1);

              grid[sr][sc] = temp ; // unmark it 
          }
        

           
     
        
       
        
       




       return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        this->M = grid.size(), N = grid[0].size();
         this->grid = grid;

         int sr = -1, sc = -1, er = -1, ec = -1,blockedCells = 0;

         for( int i = 0; i < M; i++){
            for( int j = 0; j < N; j++){
                if( grid[i][j] == 1){
                    sr = i, sc = j;
                }else if(  grid[i][j] == 2 ){
                      er = i, ec = j;
                }else if( grid[i][j] == -1){
                    blockedCells++;
                }
            }
         }
            
            this->TotalSteps = M * N -1 - ( blockedCells++);
       return f( sr, sc, er, ec,0);
    }
};

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}