/*

 https://leetcode.com/problems/critical-connections-in-a-network/


*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector < vector <int>>graph;
    vector <int>tin;
    vector <int>low;
    vector <bool>vis;
    int timer = 1;
    

    void f( int node, int par ,   vector<vector<int>>&bridges ){

        vis[ node ] = 1;
        
        tin[ node ]  = low[ node ] = timer++;

        for( int nbd : graph[ node] ){

            if( nbd == par ) continue ;

            if( !vis[ nbd] ){
               
             f( nbd, node, bridges);

             low[node] = min(  low[node], low[nbd] );

             if( low[nbd] > tin[node] )
                bridges.push_back( {node, nbd});
             



            }else{

             low[node] = min(  low[node], low[nbd] );

            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

         tin.assign(n,0);
         low.assign(n,0);
         vis.assign(n,0);
         graph.assign( n, vector <int>() );

         for( auto x : connections){
            int u = x[0], v = x[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
         }

       vector<vector<int>>bridges;

       f( 0, -1, bridges);


    return bridges;
    }
};


int main(){





    return 0;
}