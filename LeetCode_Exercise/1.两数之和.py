#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    """使用哈希算法解题"""
    # def twoSum(self, nums: List[int], target: int) -> List[int]:
    #     hashmap={}
    #     for ind,num in enumerate(nums):
    #         hashmap[num] = ind
    #     for i,num in enumerate(nums):
    #         j = hashmap.get(target - num)
    #         if j is not None and i!=j:
    #             return [i,j]
    
    """使用字典算法解题"""
    """
    enumerate() 函数用于将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，同时列出数据和数据下标，
    >>>seasons = ['Spring', 'Summer', 'Fall', 'Winter']
    >>> list(enumerate(seasons))
    [(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]

    >>>seq = ['one', 'two', 'three']
    >>> for i, element in enumerate(seq):
    ...     print i, element
    ... 
    0 one
    1 two
    2 three
    """
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for index, num in enumerate(nums):
            another_num = target - num
            if another_num in hashmap:
                return [hashmap[another_num], index]
            hashmap[num] = index
        return None
    
    
    """自己的算法，运行用例不完全正确"""
    # def twoSum(self, nums: List[int], target: int) -> List[int]:
    #     if not isinstance(nums, list):
    #         return
    #     else:
    #         for num in nums:
    #             if not isinstance(num, int):
    #                 return
    #     if not isinstance(target, int):
    #         return

    #     new_nums = []

    #     num_len = len(nums)
    #     for i in range(num_len):
    #         for j  in  range(i + 1, num_len):
    #             print(i, j)
    #             if nums[i] + nums[j] == target:
    #                 new_nums.append(i)
    #                 new_nums.append(j)

    #     return new_nums
        
# @lc code=end

