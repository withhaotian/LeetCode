#include <iostream>
using namespace std;

/*
    206. 反转链表
    给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
    输入：head = [1,2,3,4,5]
    输出：[5,4,3,2,1]
*/

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode* n): val(x), next(n) {}
};

ListNode* init_listnode() {
    ListNode* node = new ListNode(1);
    ListNode* head = node;
    for (int i = 2; i <= 5; i++) {
        ListNode* new_node = new ListNode(i);
        node->next = new_node;
        node = new_node;
    }
    return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = pre;
    while(head){
        pre = head;
        head = head->next;
        pre->next = cur;
        cur = pre;
    }

    return pre;
}

int main() {
    ListNode* head = init_listnode();
    ListNode* tmp = head;
    while(tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;

    ListNode* new_head = reverseList(head);
    tmp = new_head;
    while(tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    return 0;
}