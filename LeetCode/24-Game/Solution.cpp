class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int c : cards)
            nums.push_back((double)c);
        return helper(nums);
    }

private:
    bool helper(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24.0) <
                   1e-6; // tolerance for floating-point errors
        }

        // pick two numbers
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double a = nums[i], b = nums[j];

                // generate possible results of applying operations
                vector<double> ops = calOperations(a, b);

                // create next round excluding nums[i] and nums[j]
                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }

                // try each operation result
                for (double v : ops) {
                    next.push_back(v);
                    if (helper(next))
                        return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> calOperations(double a, double b) {
        vector<double> res;
        res.push_back(a + b);
        res.push_back(a - b);
        res.push_back(b - a);
        res.push_back(a * b);
        if (fabs(b) > 1e-6)
            res.push_back(a / b); // avoid division by zero
        if (fabs(a) > 1e-6)
            res.push_back(b / a);
        return res;
    }
};
