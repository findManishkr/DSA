#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
const int inf = INT_MAX;

class SegmentTree{
 public:
 int n;

 vector<int>&arr;
 vector<int>tree;

 SegmentTree( vector<int>&input ) : arr(input) {

   n = input.size();
   tree.assign(4*n, 0);
   build(0,0, n-1);
  

 }

  void build( int node, int st, int en ){
       if( st == en ){
          // leaf node
          tree[node] = arr[st];   // 
          return ;
       }    
       
         int mid = (st + en ) >> 1;

       build(2*node + 1, st, mid );
       build(2*node + 2, mid + 1, en);
     
      tree[node] = min( tree[2*node + 1], tree[2*node + 2]);

  }
      /// minimum query in range [l,r]
  int query(int node, int l, int r, int st, int en ){

      // no overlapping
       if( l > en || r < st ) return inf;
       // complete overlap
       if( l <= st && en <= r) return tree[node];

       // else in case of partial overlap

       int mid = ( st + en ) >> 1;

       int lmin = query(2*node + 1, l, r, st, mid);
       int rmin = query( 2*node+2, l,r, mid + 1, en);

        
     return min( lmin, rmin);

  }
           // update the value at idx to  `val`
  void update ( int node, int idx, int val, int st, int en ){

           if( st == en ){

              arr[idx] = val;
              tree[node] = val;

              return ;
           }

           int mid = (st + en) >> 1;

           if( idx <= mid ) update(2*node + 1, idx, val, st, mid);
           else update( 2*node + 2, idx, val, mid + 1, en);

           // now again build/ update  the updated tree

           tree[node] = min( tree[2*node + 1], tree[2*node + 2]);

  }
 



};

int main(int argc, char const *argv[]) {


  int n, q;
  cin >> n >> q;
  
  vector<int>arr(n);
  loop(i,0,n) cin >> arr[i];

  SegmentTree seg(arr);

  while(q--){

    int queryType; cin >> queryType;

     if( queryType == 1){
          int idx, val;
          cin >> idx >> val;
          seg.update(0,idx -1, val, 0, n-1);    // considering 0 based indexing 


     }else{

        int l, r;
        cin >> l >> r;

        cout << seg.query(0, l -1, r -1, 0, n -1) <<'\n';


     }


       


  }

   
    return 0;
}