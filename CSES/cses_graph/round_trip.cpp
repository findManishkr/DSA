

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<vector<int>> graph;
vector<bool> vis;
vector<int> parent;
int startCycle = -1, endCycle = -1;

bool dfs(int node, int par) {     // function to detect cylce

       vis[node] = true;

       for( int nbd : graph[node]){
          
           if( nbd == par) continue;     // skip call to given nodes nbd which is parent of nbd parent 

             parent[nbd] = node;
            // explore other paths

            if( !vis[nbd]){
                if(  dfs(nbd,node)  ) return true;
            }else{
                 // vis and not parent then cycle detected here

                   startCycle = nbd;
                   endCycle = node;
                   return true;

            }

            
            

       }

       return false;
   
}

int main() {
    setupIO();
    int N, M;
    cin >> N >> M;

    graph.assign(N + 1, {});
    vis.assign(N + 1, false);
    parent.assign(N + 1, -1);

    while (M--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

        bool IsCycle = false;

        for( int i =1; i <= N; i++){
             if( !vis[i]){
                if( dfs(i,-1) == true){
                     IsCycle = true;
                      break;
                }
             }
        }


         if( IsCycle == false){
             cout <<"IMPOSSIBLE\n";
             return 0;
         }

      vector < int > cycle;
      cycle.push_back( startCycle);
      for( int node = endCycle ; node != startCycle ; node = parent[node] )
          cycle.push_back( node);
      cycle.push_back( startCycle);    
      

        reverse(all(cycle));
         cout << cycle.size() <<'\n';
        for( int el : cycle ){
             cout << el <<' ';
        }
   
    return 0;
}
