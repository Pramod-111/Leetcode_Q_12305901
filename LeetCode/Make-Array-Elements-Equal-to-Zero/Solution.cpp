public int CountValidSelections(int[] nums) {
    int n = nums.Length, result = 0;
    int currSum = 0, totalSum = nums.Sum();
    
    for(int i = 0; i < n; i++)
    {
        currSum += nums[i];
        totalSum -= nums[i];
        if(nums[i] != 0) continue;

        if(currSum == totalSum) result += 2;
        if(Math.Abs(currSum - totalSum) == 1) result++;
    }

    return result;
}