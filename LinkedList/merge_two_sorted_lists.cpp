/*

https://leetcode.com/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-100-liked

concept : two pointer approach

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
           ListNode * ans = new ListNode();
           ListNode *curr = ans;

        
           ListNode *ptr1 = list1, *ptr2 = list2;

           while( ptr1 && ptr2 ){

                if( ptr1-> val < ptr2->val )
                curr->next = new ListNode( ptr1->val), ptr1 = ptr1->next;
                else 
                curr->next = new ListNode( ptr2->val), ptr2 = ptr2->next;

                curr = curr->next;

           }

           if( !ptr1)
           curr->next = ptr2;
           else
           curr->next = ptr1;


    return ans->next;

    }
};

/*

[1,2]

[2,3,4,5]

[0] -> [1]->[2]-> [2] -> 

*/

/*

 testing and debugging



*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}