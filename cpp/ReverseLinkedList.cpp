#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *tmp = NULL;

        while(q) {
            tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }

        head->next = NULL;
        return p;
    }
};


int main() {
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for(int i = 2; i <= 4; ++i) {
        p->next = new ListNode(i);
        p = p->next;
    }

    p = head;
    while(p) {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;

    Solution *sol = new Solution;
    head = sol->reverseList(head);

    while(head) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}