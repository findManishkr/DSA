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

class DSU {
     public:
   int n;
   vector<int>parent;
   vector<int>rank;

    DSU (int n){

         this->n = n;
         parent.resize(n+1);
         rank.resize(n+1);
        loop(i,1,n+1) parent[i] = i;

    }

    int find( int x ){

       if( parent[x] == x ) return x;
       return parent[x] =  find( parent[x] );

    }

    void unite( int a, int b){
        
        a = find(a);
        b = find(b);

        if( a == b) return ;

        if( rank[a] > rank[b] ){
            parent[b] = a;
        }
        else if( rank[b] > rank[a]){
            parent[a] = b;
        }
        else{
            parent[b] = a;
            rank[a]++; // increase rank only when equal
        }
       
    }


};
int main(int argc, char const *argv[]) { //setupIO();


     int n , m;
     cin >> n >> m;

     DSU dsu(n);

     while( m--){

        int a,  b;
        cin >> a >> b;

        dsu.unite(a,b);
     }

     // now collect unique componets;

       vector<int>reqNodes;
      loop(i,1,n+1)
     if( dsu.find(i) == i) reqNodes.push_back(i);


      
        cout << reqNodes.size() - 1 <<'\n';
         loop(i,1, reqNodes.size() )
        cout << reqNodes[i-1] <<' ' << reqNodes[i] <<'\n';
       



    return 0;
}