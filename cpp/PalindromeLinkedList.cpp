#include <iostream>

using namespace std;

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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
        	return true;
        }

        int len = this->len(head);
        int half = len / 2 - 1;

		ListNode *p = head;
		ListNode *pBreak, *pMiddle;
        for(int i = 0; i < half; ++i) {
        	p = p->next;
        }

        pBreak = p;
        p = p->next;
        pBreak->next = NULL;

        pMiddle = NULL;
        if(len % 2) {
        	pMiddle = p;
        	p = p->next;
        }

        p = this->reverse(p);

        while(head) {
        	if(head->val != p->val) {
        		return false;
        	}
        	head = head->next;
        	p = p->next;
        }

        return true;
    }

private:
	int len(ListNode* head) {
		int len = 0;
		while(head) {
			len++;
			head = head->next;
		}

		return len;
	}

	ListNode* reverse(ListNode *head) {
		ListNode *p = head;
		ListNode *q, *tmp;

		q = p->next;
		while(q) {
			tmp = q->next;
			q->next = p;
			p = q;
			q = tmp;
		}

		head = p;
		return head;
	}
};

int main() {
	return 0;
}