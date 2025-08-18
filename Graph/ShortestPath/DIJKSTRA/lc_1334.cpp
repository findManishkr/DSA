/*



*/


#include <bits/stdc++.h>
using namespace std;



#define pii pair<int,int>
#define pq priority_queue
class Solution {
public:
    const int inf =  1e9 ;

    vector < vector < pii>> graph;
    int dijkstra ( int node  , int threshold ,int n){


        vector < bool >vis( n, 0);
        vector < int>dist(n, inf);
       pq < pii, vector < pii >, greater< pii> > q;
        
        dist[node] = 0;
       q.push( {0,node});

       while(!q.empty() ){

        auto [d , u] = q.top(); q.pop();

        if( vis[u] ) continue;   vis[u]  = 1;

        for( auto [v, w] : graph[u] ){
                
               if( dist[u] + w < dist[v] ){
                 dist[v] = dist[u] + w;
                 q.push( {dist[v], v});
               } 

        }


       }

        int cnt = 0;
        for( int el : dist){
            if( el <= threshold) cnt++;
        }

       return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

         graph.assign( n, vector<pii>());
         for( int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];

             graph[u].push_back( {v,wt});
             graph[v].push_back( {u, wt});
         }

         int ansCity = -1;
         int minicity = inf;
         for( int node = 0; node < n; node++){
              int d =      dijkstra(node, distanceThreshold,n);
           if( minicity >= d   ){
             minicity = d;
             ansCity = node;
           }

         }

         return ansCity;
    }
};

/*
 time :  O (  N * ( V + Elogv) )

  
*/

int main(){

    
    return 0;
}