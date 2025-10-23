#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()
#define ll long long 

class SegmentTree{
public:
int n;
vector<int>&arr;
vector<ll>tree;

SegmentTree(vector<int>&input) : arr(input) {

     
     n = input.size();
     tree.assign(4*n, 0);  

}

void build( int node , int st, int en ){
      
    if( st == en ){
        // leaf node 
        tree[node] = arr[st ] ;  // = arr[en]
        return ;
    }

    int mid = (en + st) >> 1;

    build( 2*node+1, st, mid);
    build( 2*node + 2, mid + 1, en);

    tree[node] = tree[2*node+1] + tree[2*node + 2];



}


 // range sum query [l,r]
ll query(int node, int l, int r, int st, int en ){  // [st,end] range of the array

    // base case 
    if( l > en || r < st ) {       // no overlap
         return 0;
    }

    // complete overlap

    if( l <= st && en <= r){
        return tree[node];
    }

    int mid = ( st + en)/2;

    ll lsum = query(2*node+1, l, r, st,mid);
    ll rsum = query(2*node+2, l, r, mid+1, en );

    return lsum + rsum;

}

void update(int node, int idx, ll val, int st, int en ){

    if( st == en ){
   
         tree[node] = val;
         arr[idx] = val;
         return ;

    }

    // chek in which part( left, rifhr) , idx lies

    int mid = (en + st) >> 1;

    if( idx <= mid ) update(2*node + 1, idx,val, st, mid);
    else update( 2*node+ 2, idx, val, mid+1, en);

    tree[node] = tree[2*node +  1] + tree[2*node + 2];

}


};

int main(int argc, char const *argv[]) { 

    int n, q;
    cin >> n >> q;

    vector<int>arr(n);
    loop(i,0,n) cin >> arr[i];

    SegmentTree seg(arr);
    seg.build(0,0,n-1);
    while(q--){

      int qtype;
      cin>> qtype;

       if( qtype == 1){
          int idx;
          ll val;
          cin >> idx >> val;

          seg.update(0,idx-1,val,0, n-1);

       }else {
            int l, r; cin>>l >>r;      // zero based indexing 
           cout << seg.query(0,l-1,r-1,0,n-1) <<'\n';
       }

    }




    return 0;
}