
import collections
 
 
class Solution(object):
    def lengthOfLongestSubsequenceDistinct(self,k:int,s:tuple)->int:
        ans =0
        left = right = 0
        size = len(s)
        count = collections.Counter()
        while right<size:
            ch1 = s[right]
            count[ch1]+=1
            while len(count)>k:
                ch2 = s[left]
                count[ch2]-=1
                if count[ch2]==0:
                    del count[ch2]
                left += 1
            right += 1
            ans = max(ans,right-left)
        return ans
#测试
a = Solution()
b = a.lengthOfLongestSubsequenceDistinct(11,(3,3,3,1,2,1,1,2,3,3,4))
print(b)


