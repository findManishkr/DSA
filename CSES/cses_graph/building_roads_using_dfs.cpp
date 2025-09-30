#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

void f( int node, vector< bool>&vis,vector< vector<int>>&graph){
        if( vis[node] == 1 ) return ;
          
           vis[node] = 1;


           for( int nbd : graph[node])
               f(nbd,vis, graph);
           


}

void dfs( int node, vector< bool>&vis,vector< vector<int>>&graph ){

        vis[node] = true;


        for( int nbd : graph[node]){

             if( !vis[nbd] ){
                 dfs(nbd,vis, graph);
             }

             
        }

}
int main(int argc, char const *argv[]) { //setupIO();


    int n, m; // n :-> no of vertices, m :->no of edges
    cin >> n >> m;

    vector< vector<int>>graph(n+1, vector<int>());
    vector< bool > vis(n+1, false);

     while(m--){

         int a, b;
         cin >> a>> b;
         graph[a].push_back(b);
         graph[b].push_back(a);

     }
        
       vector<int>reqNodes;
      loop(i,1, n + 1){
          if(  !vis[i] ){
              f(i,vis,graph);
             reqNodes.push_back(i);
          }
      }

       
        cout << reqNodes.size() - 1 <<'\n';
         loop(i,1, reqNodes.size() )
        cout << reqNodes[i-1] <<' ' << reqNodes[i] <<'\n';
       



    return 0;
}