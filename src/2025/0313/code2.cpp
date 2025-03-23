/*
    # 2095. 删除链表的中间节点
    给你一个链表的头节点 head 。删除 链表的 中间节点 ，并返回修改后的链表的头节点 head 。

    长度为 n 链表的中间节点是从头数起第 ⌊n / 2⌋ 个节点（下标从 0 开始），其中 ⌊x⌋ 表示小于或等于 x 的最大整数。

    对于 n = 1、2、3、4 和 5 的情况，中间节点的下标分别是 0、1、1、2 和 2 。

    输入：head = [1,3,4,7,1,2,6]
    输出：[1,3,4,1,2,6]
    解释：
    上图表示给出的链表。节点的下标分别标注在每个节点的下方。
    由于 n = 7 ，值为 7 的节点 3 是中间节点，用红色标注。
    返回结果为移除节点后的新链表。
*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* init_list(){
    vector<int> arr = {1,2,3,4};
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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = prev->next->next;
        
        return head;
    }
};

int main() {    
    Solution s;
    
    ListNode* head = init_list();
    ListNode* new_head = s.deleteMiddle(head);
    while (new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }

    return 0;
}