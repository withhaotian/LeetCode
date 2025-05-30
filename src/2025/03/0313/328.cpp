/*
    给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。

    第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。

    请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。

    你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。

    输入: head = [1,2,3,4,5]
    输出: [1,3,5,2,4]

    输入: head = [2,1,3,5,6,4,7]
    输出: [2,3,6,7,1,5,4]
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* init_list(){
    vector<int> arr = {2,1,3,5,6,4,7};
    ListNode* head = new ListNode(arr[0]);
    ListNode* tmp = head;
    for (int i = 1; i < arr.size(); i++) {
        ListNode* node = new ListNode(arr[i]);
        head->next = node;
        head = node;
    }

    return tmp;
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;

        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = odd->next;
        }
        
        odd->next = even_head;

        return head;
    }
};

int main() {
    ListNode* head = init_list();

    Solution s;
    ListNode* new_head = s.oddEvenList(head);
    while (new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;

    return 0;
}