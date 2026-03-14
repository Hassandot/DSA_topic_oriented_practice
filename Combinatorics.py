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

# 77. Combinations
# Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
def combine(self, n: int, k: int) -> List[List[int]]:
        res=[]
        nums=[i for i in range(1,n+1)]
        used=[False]*len(nums)
        def bt(start,current):
            if len(current)==k:
                res.append(current)
                return 
            needed=k-len(current)
            remaining=len(nums)-start
            if remaining<needed:
                return

            for i in range(start,len(nums)):
                if not used[i]:
                    used[i]=True
                    newCurr=copy.copy(current)
                    newCurr.append(nums[i])
                    bt(i+1,newCurr)
                    used[i]=False
        bt(0,[])
        return res

# 784. Letter Case Permutation
# Given a string s, you can transform every letter individually to be lowercase or uppercase to create
def letterCasePermutation(self, s: str) -> List[str]:
        res=[]
        k=len(s)
        def bt(start,current):
            if len(current)==k:
                res.append(current)
                return 
            
            if s[start].isdigit():
                bt(start+1,current+s[start])
            else:
                bt(start+1,current+s[start].lower())
                bt(start+1,current+s[start].upper())
        bt(0,'')
        return res