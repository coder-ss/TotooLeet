#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	if(head == NULL) {
    		return NULL;
    	}

        ListNode *tmp;
        while(head && head->val == val) {
        	tmp = head;
        	head = head->next;
        	delete tmp;
        }
        ListNode *current = head;

        while(current && current->next) {
        	if(current->next->val == val) {
        		tmp = current->next;
        		current->next = current->next->next;
        		delete tmp;
        	} else {
        		current = current->next;
        	}
        }

        return head;
    }
};

int main() {
	ListNode *head = new ListNode(1);
	ListNode *node1 = new ListNode(2);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(2);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;

	Solution sol;

	head = sol.removeElements(head, 2);

	while(head) {
		std::cout<<head->val<<" ";
		head = head->next;
	}

	return 0;
}