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
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next || !head->next->next)
            return head;

        int idx = 1;
        ListNode* curr = head;

        ListNode* oddTail = NULL;
        ListNode* oddHead = NULL;
        ListNode* evenHead = NULL;
        ListNode* evenTail = NULL;

        while (curr) {

            if (idx % 2) {

                if (!oddTail) {

                    oddTail = curr;
                    oddHead = oddTail;

                } else {

                    oddTail->next = curr;
                    oddTail = oddTail->next;
                }

            } else {

                if (!evenTail) {

                    evenTail = curr;
                    evenHead = evenTail;

                } else {

                    evenTail->next = curr;
                    evenTail = evenTail->next;
                }
            }

            idx++;
            curr = curr->next;
        }

        oddTail->next = NULL;  // remove remaining lists
        evenTail->next = NULL; // remove remaining lists

        oddTail->next = evenHead;

        return oddHead;
    }
};

/*
  # approach
    - pick first oddTail nodes , then pick all even nodes,

    - connect them , to get the answer





*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}