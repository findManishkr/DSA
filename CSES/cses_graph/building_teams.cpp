/*

https://cses.fi/problemset/task/1668/

concpet: bi-partite based

*/


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
bool dfs( int node ,bool col, vector<vector<int>>&graph, unordered_map<int,bool>&mp){
             /* 
               dfs() :-> this function checks whether graph is bipartite or not
             
             */

            mp[ node ] = col;

            bool ans = true;

         for( int nbd : graph[node]){
             if( mp.count(nbd) && mp[nbd] != mp[node] ) continue;
             if( mp.count( nbd) && mp[nbd] == mp[node]) return false;
             // otherwiase
              ans &= dfs( nbd, !col, graph, mp);
         }
             
   return ans;
}
int main(int argc, char const *argv[]) {  setupIO();

    int v , e;
    cin >> v >> e;

    vector< vector<int>>graph(v+1, vector<int>() );
    unordered_map<int,bool>mp;

     while(e--){
          int u, v;
          cin>> u>> v;
          graph[u].push_back(v);
          graph[v].push_back(u);
     }

     vector<int>ans;

     loop(i,1,v+1){
        if( !mp.count(i) ){
            if( dfs(i,1,graph, mp)  == false){
                 cout << "IMPOSSIBLE\n";
                   return 0;
            }
        }
     }

     loop(i,1,v+1){
         if( mp[i] )
             cout <<2 <<' ';
         else 
             cout <<1 <<' ';        
     }


    return 0;
}