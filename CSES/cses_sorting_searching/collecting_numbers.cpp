/*
https://cses.fi/problemset/task/2216/



*/


#include <bits/stdc++.h>


using namespace std;

#define loop(i,a,b) for( int i = (a); i < (b); i++)
#define ll long long
#define pll pair<ll,ll>

/*
 * Problem: Collecting Numbers (CSES 2216)
 * Link: https://cses.fi/problemset/task/2216/
 *
 * Problem statement (brief):
 * Given a permutation of numbers 1..n, you scan the array left-to-right and
 * collect numbers in strictly increasing order in rounds. You may need multiple
 * rounds; each round you can collect an increasing subsequence by value where
 * indices are increasing. Return the minimum number of rounds required to
 * collect all numbers.
 *
 * Data structures:
 * - priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, cmp> (min-heap by value)
 *   storing (value, original_index). The index lets us check left-to-right order.
 *
 * Algorithm (Greedy):
 * - While the heap is not empty, start a new round and pop elements in
 *   increasing value order, collecting them as long as each popped element's
 *   index is strictly greater than the previously collected element's index.
 * - Each pop corresponds to taking an element in the current left-to-right
 *   scan; when the index order fails, finish the round and start a new one.
 *
 * Proof sketch (correctness):
 * - By always selecting the smallest remaining values, a round greedily takes
 *   as many elements as possible whose indices are increasing. Any element that
 *   could be taken in the same round would be popped during that round, so
 *   the greedy strategy is optimal and yields the minimum number of rounds.
 *
 * Complexity:
 * - Time: O(n log n) due to heap operations for n elements.
 * - Space: O(n) for storing all elements in the heap.
 */
// Comparator for priority_queue to make it a min-heap by value.
// If values are equal, smaller index should have higher priority (so it comes first).
struct cmp{
     bool operator() (const pll &a, const pll &b){
         if( a.first == b.first ) return a.second > b.second;
         // min-heap: element with smaller first should come before, so return a.first > b.first
         return a.first > b.first;
     }
};
int main(){

 int n; cin >> n;

  // min-priority queue storing (value, original_index)
  priority_queue< pll, vector< pll> , cmp> pq;
  loop(i,0, n){
     ll x; cin >> x;
     // push each element along with its index so we can process by value
     pq.push({x,i});       // (el , idx);
  }


   ll cnt = 0;
   

   // while there are unprocessed elements, perform one "round" by
   // popping as many values as possible that have strictly increasing indices
   while(  !pq.empty() ){ 

          // previous number and index collected in current round
          ll prevNum = 0, prevIdx = -1;


          // Collect as many numbers in ascending value order as possible
          // while their indices are strictly increasing (can be collected in one scan)
          while( (!pq.empty()) && (prevNum <= pq.top().first) && (prevIdx < pq.top().second) ){

                  prevNum = pq.top().first;
                  prevIdx = pq.top().second;
                  pq.pop();
          }
           // finished one round
           cnt++; 
          

   }

           cout << cnt <<'\n';


    return 0;
}


/*
 * Summary:
 * The program counts the minimum number of left-to-right rounds required
 * to collect all numbers in increasing order by repeatedly extracting the
 * longest sequence (by value monotonicity and increasing indices) using a
 * min-priority queue.
 */