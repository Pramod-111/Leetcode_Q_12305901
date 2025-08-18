class Solution {
    const double EPS = 1e-6; // tolerance for floating-point comparison

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(),
                            cards.end()); // convert int -> double
        return canMake24(nums);
    }

private:
    // Recursive function to check if we can form 24 from current numbers
    bool canMake24(vector<double>& nums) {
        int n = nums.size();

        // Base case: only one number left → check if it's 24
        if (n == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }

        // Try all pairs of numbers (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double a = nums[i], b = nums[j];

                // Remaining numbers after removing i and j
                vector<double> rest;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j)
                        rest.push_back(nums[k]);
                }

                // Try all possible results with a and b
                for (double val : possibleResults(a, b)) {
                    rest.push_back(val);
                    if (canMake24(rest))
                        return true;
                    rest.pop_back(); // backtrack
                }
            }
        }
        return false;
    }

    // Generate all valid results from two numbers
    vector<double> possibleResults(double a, double b) {
        vector<double> res;
        res.push_back(a + b);
        res.push_back(a - b);
        res.push_back(b - a);
        res.push_back(a * b);
        if (fabs(b) > EPS)
            res.push_back(a / b); // avoid division by zero
        if (fabs(a) > EPS)
            res.push_back(b / a);
        return res;
    }
};
