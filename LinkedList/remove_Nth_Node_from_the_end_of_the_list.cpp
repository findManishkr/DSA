/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=study-plan-v2&envId=top-100-liked



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

 // one pass solution

class Solution1 {
public:
    int size_of_the_linkedList(ListNode* head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
         -it is two pass soln,
            |-> first traversal to find size of the linkedlist
            |-> second traversal in for loop

            time : O(N + N ) = O(2N)=> O(N)
            space: O(1)



        */

        int sz = size_of_the_linkedList(head);

        if (sz == 1) {

            delete head; // free the memory
            return NULL; // edge case
        }
        if (sz == n) { // ie delete the head node

            ListNode* node_to_delete = head;
            head = head->next;

            delete node_to_delete;
            return head; // edge case
        }

        ListNode* temp = head;

        for (int i = 1; i <= (sz - n + 1 - 2);
             i++) // move pointer  just before , the node to be removed
            temp = temp->next;

        ListNode* node_to_delete = temp->next;

        temp->next = temp->next->next; // unlink

        delete node_to_delete;

        return head;
    }
};

// approach 2 -> one pass solution

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

         ListNode *ptr1 = head, *ptr2 = head;

         // move ptr2 by ` n steps`

          while(n--)
          ptr2 = ptr2->next;

         // if ptr2 == NULL, then node to be deleted is head node of the linkedlist

         if( !ptr2 ){
            ListNode* node_to_be_deleted = head;
            head = head->next;
            delete node_to_be_deleted;
            return head;
         } 

         // else move both pointers 1 step untill `ptr2` reaches last node of the linkedlist

         while( ptr2->next ){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
         }

         // now , next node of ptr1 is node to be deleted;

         ListNode *node_to_be_deleted = ptr1->next;
         ptr1->next = ptr1->next->next;      // unlink

         delete node_to_be_deleted;

        return head;
    }
};

/*
// write single pass solution

1. // observe how single pass solution can be implemented, using slow and fast pointer

 `node just before the node can be found by keeping two pointer having n distance b/w them`

 [1] -> [2] -> [3] -> [4] -> [5]
  |------n------|

 [1] -> [2] -> [3] -> [4] -> [5]
         |------n------|

 [1] -> [2] -> [3] -> [4] -> [5]
                |------n------|
        
 

 `clean code ` yeah!



*/
int main(int argc, char const *argv[]) { setupIO();



    return 0;
}