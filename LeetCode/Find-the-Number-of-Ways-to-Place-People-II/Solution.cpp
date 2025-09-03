        points.sort(key = lambda x: (x[0], -x[1]))
        N = len(points)
        ans = 0
        for i in range(N):
            x1, y1 = points[i]
            # now get monostack. contribution is size of the monostack
            stack = []
            for _, y2 in points[:i]:
                if y2 < y1:
                    continue
                if not stack:
                    stack.append(y2)
                else:
                    while stack and y2 <= stack[-1]: # pop off anything that is not strict smaller than y2
                        stack.pop()
                    stack.append(y2)
            ans += len(stack)

        return ans