/*
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/?envType=study-plan-v2&envId=graph-theory

  concept : single source bfs
*/

#include <bits/stdc++.h>
using namespace std;


void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}



class Solution {
public:
    vector < vector < int >> dir = { {1,0}, { -1,0}, {0, 1}, { 0, -1} };

    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {   // e : entrance
          int M = maze.size(), N = maze[0].size();

           queue < pair < int, int > > q;
             
            int srcR = e[0], srcC = e[1];
            q.push( {srcR, srcC});

            maze[ srcR ][ srcC] = '+';
               int steps = 0;

             while(  !q.empty()  ){

                int sz = q.size();

                  while( sz--){
                   
                   auto [i,j] = q.front(); q.pop();  //  This way, i and j are copied from the front of the queue before it is popped and destroyed.

                     /*



                    int* p = new int(10);
delete p;
cout << *p;  // ❌ Undefined behavior



                     */


                      for( auto x :  dir){
                         int nr = i + x[0], nc = j + x[1];
                        
                         if(   nr < 0 || nc < 0 || nc >= N || nr >= M   || maze[ nr ][ nc ] == '+') continue;

                         if( nr == srcR && nc == srcC) continue;
                        if( nr == 0 || nc == 0 || nr == M -1 || nc == N -1  )
                             return steps + 1;

                            maze[ nr ][ nc] = '+';

                            q.push( {nr, nc}); 


                      }

                  }

                    steps++;


             }

           return - 1;
        
    }
};


/*
  ` ==22==ERROR: AddressSanitizer: heap-use-after-free on address 0x515000018d78 ` : ->

  means that your C++ program is trying to access memory that was already freed — in simple terms:

🧨 What happened?
You deleted (freed) a memory block (using delete or free), and then later you or the STL (like a queue, vector, etc.) tried to read or write to that memory again.

This is called a "use-after-free" bug — and it's one of the most dangerous types of bugs in C++



*/


int main() { setupIO();
   
     
     
    

   

    return 0;
}
