from typing import List
# 46. Permutations
# Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
def permute(self, nums: List[int]) -> List[List[int]]:
        res:List[int]=[]
        used:List[bool]=[False]*len(nums)
        def backtrack(current:List[int]):
            if len(current)==len(nums):
                res.append(current)
            
            for i in range(len(nums)):
                if not used[i]:
                    used[i]=True
                    newCurrent:List[int]=copy.copy(current)
                    newCurrent.append(nums[i])
                    backtrack(newCurrent)
                    used[i]=False
            
        backtrack([])
        return res

# 78. Subsets
# Given an integer array nums of unique elements, return all possible subsets (the power set). The solution set must not contain duplicate subsets. The subsets can be returned in any order.
def subsets(self, nums: List[int]) -> List[List[int]]:
        res:List[List[int]]=[]
        used:List[bool]=[False]*len(nums)

        def bt(start,current):
            if current:
                res.append(current)
            for i in range(start,len(nums)):
                if not used[i]:
                    used[i]=True
                    newCurr=copy.copy(current)
                    newCurr.append(nums[i])
                    bt(i+1,newCurr)
                    used[i]=False
        res.append([])
        bt(0,[])
        return res

