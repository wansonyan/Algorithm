from ast import List
from collections import defaultdict


class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n, idx_map, ans = len(arr), {num: i for i, num in enumerate(arr)}, 0
        dp = defaultdict(lambda: defaultdict(lambda: 2))
        for i in range(n - 1):
            for j in range(i + 1, n):
                if (nxt := arr[i] + arr[j]) in idx_map:
                    dp[j][idx_map[nxt]] = dp[i][j] + 1
                    ans = max(ans, dp[j][idx_map[nxt]])
        return ans

