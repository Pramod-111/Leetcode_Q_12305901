// Complexity:
// Time O(NLogM) and Space O(1) where N is the length of nums
// and M is the maximum number in nums.
func minOperations(nums []int) int {
	result := len(nums) * 2
	currGcd := nums[0]
	for i, num := range nums {
		if num == 1 {
			return len(nums) - count(nums[i:], 1)
		}

		currGcd = gcd(currGcd, num)
		if currGcd == 1 {
			currGcd = num
			j := i - 1
			for currGcd != 1 {
				currGcd = gcd(currGcd, nums[j])
				j--
			}

			result = min(result, i-j+len(nums)-2)
			currGcd = num
		}
	}

	if result == len(nums)*2 {
		return -1
	}
	return result
}

func count(nums []int, x int) int {
	result := 0
	for _, num := range nums {
		if num == x {
			result++
		}
	}
	return result
}

func gcd(a, b int) int {
	for a != 0 {
		a, b = b%a, a
	}
	return b
}
