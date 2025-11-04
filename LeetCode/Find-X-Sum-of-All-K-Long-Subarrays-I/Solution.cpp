    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)
        res = []

        def func(arr):
            res = 0
            count = {}
            for a in arr:
                count[a] = 1+count.get(a, 0)

            heap = []
            for a,b in count.items():
                heapq.heappush(heap, (b, a))
                if len(heap) > x:
                    heapq.heappop(heap)
            
            for a,b in heap:
                res += a*b
            
            return res


        for i in range(n-k+1):
            sub = nums[i:i+k]
            res.append(func(sub))
        
        return res```