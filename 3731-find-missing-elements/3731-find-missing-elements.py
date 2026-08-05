class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
       smallest = min(nums)
       largest = max(nums)
       missing =[]
       for i in range(smallest,largest+1):
            if i  not in nums:
               missing.append(i)
       return missing
        