#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int pairSum(ListNode* head) {
        // store vals of list in stack, at the same time get the size of list
        
        stack<int> st;
        ListNode* cur = head;
        int size = 0;
        while(cur->next != nullptr){
            st.push(cur->val);
            cur = cur->next;
            size++;
        }
        st.push(cur->val);
        size++; 
        
        // til half of the size, get the pairSum and the maxSum
        cur = head;
        int sum = 0;
        int max = 0;
        for(int i = 0; i < size / 2; i++){
            sum =  st.top() + cur->val;
            if(max < sum) max = sum;
            cur = cur->next;
            st.pop();
        }

        return max;

        // timeComplextiy O(N) + O(2/N) 
        // spaceComplexity O(N) 
    }
};