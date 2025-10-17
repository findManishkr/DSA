#include <bits/stdc++.h>
using namespace std;
vector< vector<int>>graph;
int f( int node, int par , vector<int>&diameter , vector<int>&toLeaf){


     int max1 = -1, max2 = -1;


     for( int nbd : graph[node] ){
          if( nbd == par ) continue;

            int longChild = f( nbd,node,diameter,toLeaf) ;

            if( longChild > max1 ){
                 max2 = max1;
                 max1 = longChild;
            }else if( longChild > max2 ){
                  max2 = longChild;
            }

     }


      diameter[node] = max1 + max2 + 2;   

       return toLeaf [node] =  1 + max1;
}
int main(){



    int n;
    cin >> n;  // number of nodes
    graph.resize(n+1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
         
    vector<int>toLeaf(n+1,0);
    vector<int>diameter(n+1,0);       // stores the diameter of every subtree rooted at node i
    f(1,-1,diameter, toLeaf);

    int maxDiameter = 0;

    for( int i = 1; i <= n; i++ ){
        maxDiameter = max(   maxDiameter, diameter[i]);
    }


    cout << maxDiameter <<'\n';




    return 0;
}