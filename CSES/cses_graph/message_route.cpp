#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define inf 1e9

void f( int srcNode , int destNode, vector< vector<int>>&graph, vector<bool>&vis, vector<int>dist, vector<int>&parent){

   
      queue<int> q;
      q.push(srcNode);
      vis[srcNode] = 1;

      while( !q.empty()){
         
        int currNode = q.front(); q.pop();

         if( currNode == destNode) break;

         for( int nbd : graph[ currNode]){
             if( !vis[nbd] ){
                 q.push(nbd);
                 parent[nbd] = currNode;
                 dist[nbd] = 1 + dist[currNode];
                 vis[nbd] = true;
             }
         }

      }

      vector< int> shortestPath;

      for( int node = destNode ; node != -1; node = parent[node]){
              shortestPath.push_back( node);
      }

      reverse( shortestPath.begin(),shortestPath.end());

           if( vis[ destNode] == false ) {
              cout <<"IMPOSSIBLE\n";
               return ;
           }

        cout << shortestPath.size() <<'\n';

        for( int el : shortestPath){
             cout << el <<' ';
        }



}
int main(int argc, char const *argv[]) {  //setupIO();
       int v, e;
       cin >> v >> e;

       vector< vector<int>>graph(v+1,vector<int>());
       vector<bool>vis(v+1,false);
       vector<int>parent(v+1, -1);
       vector<int>dist(v+1, 0);
        while(e--){
            int a, b;
            cin >> a >> b;
            
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        f( 1, v,graph, vis,dist,parent);


    return 0;
}