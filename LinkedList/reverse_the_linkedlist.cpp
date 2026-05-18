/*

https://leetcode.com/problems/reverse-linked-list



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
    ListNode* reverseList(ListNode* head) {
        

         ListNode *res = NULL, *prev = NULL, *curr = head;

         while( curr ){

            prev = curr;
            curr = curr->next ;
            prev->next = res;
            res = prev;

         }

         return res;
    }
};


/*

  [1]->[2]->[3]->[4]->[5]


  res = NULL,  prev = NULL, curr = [1]

  itr = 1

   prev = [1] , curr = [2], res = [1]->[N]
                           prev->next  = res;

   itr = 2                        

   prev = [2], curr = [3], res = [2]->[1]->N

   itr = 3

   prev = [3], curr = [4] res = [3]->[2]->[1]->N

   itr = 4

   prev = [4], curr= [5] , res = [4]->[3]->[2]->[1]->N;

   itr = 5

   prev = [5], curr= NULL, res = [5]->[4]->[3]->[2]->[1]->N;







*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}