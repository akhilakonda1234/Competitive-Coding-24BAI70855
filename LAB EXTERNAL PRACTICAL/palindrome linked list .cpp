class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;

        ListNode* temp = head;

        // Store values
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Check palindrome
        int i = 0;
        int j = arr.size() - 1;

        while (i < j) {
            if (arr[i] != arr[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};
