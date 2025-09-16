// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         if (n == 0)
//             return;

//         k = k % n; // In case k > n

//         // Step 1: Reverse whole array
//         reverse(nums.begin(), nums.end());
//         // Step 2: Reverse first k elements
//         reverse(nums.begin(), nums.begin() + k);
//         // Step 3: Reverse remaining n-k elements
//         reverse(nums.begin() + k, nums.end());
//     }
// };




class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return;

        k = k % n; // handle case when k > n

        vector<int> temp(n);

        // Place each element in its new rotated position
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        // Copy back into original array
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};

