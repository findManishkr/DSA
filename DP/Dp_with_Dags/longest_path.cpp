/*


https://atcoder.jp/contests/dp/tasks/dp_g
  
concept : dp with dags

idea : difficulty was to find, how we can use previously calculated result;

*/



#include <bits/stdc++.h>
using namespace std;
 


#define loop(i,a,b) for( int i= (a) ; i <(b); i++)
#define ll long long 


void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}


vector <int>dp;

vector < list<int>>graph;
bool IsLeafNode( int node ){
    return !graph[node].size() ;
}
int f(   int node ){
   
    if( IsLeafNode( node ) ) return 0;

       

       if( dp[node] != -1) return dp[ node];

      int ans = 0;

      for( int nbd : graph[node])
       ans =  max( ans, 1 + f(nbd));

    return  dp[node] = ans;
}
int main(){  setupIO();

    int N, M;
    cin >> N >> M;

    graph.assign( N+1, list<int>{});   // 1 based nodes
    dp.assign( N + 1, -1);


     loop(i,0,M){         /// consturct graph
        int u, v;
        cin >> u >> v;
        graph[u].push_back( v);
     }

       int longestPath = 0;

          loop(node, 1, N+1){
       
             longestPath = max( longestPath, f(node) );
        }
   

        cout << longestPath <<'\n';

  return 0;
}
  
