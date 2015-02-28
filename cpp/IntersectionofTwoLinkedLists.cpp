#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
        	return NULL;
        }

        ListNode *pA, *pB;
        pA = headA;
        pB = headB;
        while(pA->next != NULL && pB->next != NULL) {
        	pA = pA->next;
        	pB = pB->next;
        }
        while(pA->next != NULL) {
        	pA = pA->next;
        	headA = headA->next;
        }
        while(pB->next != NULL) {
            pB = pB->next;
            headB = headB->next;
        }

        ListNode *pIS = NULL;
        while(headA != NULL) {
        	if(headA == headB) {
        		if(pIS == NULL) {
        			pIS = headA;
        		}
        	} else {
        		pIS = NULL;
        	}
            headA = headA->next;
            headB = headB->next;
        }

        return pIS;
    }
};

ListNode* buildList(int[], int);
int main() {
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {6};

	ListNode *headA = buildList(arr1, 5);
	ListNode *headB = buildList(arr2, 1);
	headB->next = headA;

	Solution *sol = new Solution;
	ListNode *rs = sol->getIntersectionNode(headA, headB);

	cout<<rs<<endl;
}

ListNode* buildList(int arr[], int len) {
	if(len <= 0)
		return NULL;

	ListNode *phead = new ListNode(arr[0]);
	ListNode *p = phead;
	for(int i = 1; i < len; ++i) {
		ListNode *ptmp = new ListNode(arr[i]);
		p->next = ptmp;
		p = p->next;
	}
	return phead;
}