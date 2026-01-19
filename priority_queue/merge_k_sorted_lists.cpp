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


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
              int N = lists.size();
              ListNode* ans = new ListNode();
               ListNode* temp = ans;

        priority_queue< pair< int,ListNode*> , vector<pair< int,ListNode*>>, greater< pair< int,ListNode*> >> pq;

             for( int i = 0; i < N; i++){
                 ListNode* node = lists[i];
                 if( node )
                 pq.push({node->val,node});
             }

             while( !pq.empty() ){
                 
                  auto [value, node]  = pq.top(); pq.pop();
                  if( node->next )
                  pq.push( {node->next->val, node->next});

                  temp->next = node; 
                  temp = temp->next;

             }


             return ans->next;

    }
};

/*



/*

 using minHeap time complexity can be boiled down to `NlogK` \
      |-> figure out how ? \
            |-> hint > keep at most k el in heap at any moment of time



        // Eureka : if find the heap supported soln which has complexity NlogK
             | -> now give it words\
                  |-> put all first heads in the an     

          

  






*/





int main(int argc, char const *argv[]) { setupIO();



    return 0;
}