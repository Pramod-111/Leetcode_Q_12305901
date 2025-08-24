func longestSubarray(nums []int) int {
    left, maxWindow, lastZero := 0, 0, -1 

    for right := range nums { 
        if nums[right] == 0 {
            left = lastZero + 1
            lastZero = right 
        } 
        maxWindow = max(maxWindow, right - left)
    } 
    return maxWindow 
}

func max (x, y int) int {
    if x > y {
        return x 
    }
    return y 
} 