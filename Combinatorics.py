from typing import List,Dict
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

#allArrangements
def allarrangements(s:str)->List[str]:
     res:List[str]=[]
     used:List[bool]=[False]*len(s)
     def backtrack(current:str):
        if current:
            res.append(current)
        for i in range(len(s)):
            if not used[i]:
                used[i]=True
                backtrack(current+s[i])
                used[i]=False
    
     backtrack('')
     return res

#allarrangementsArray
def allarrangementsArray(nums:List[int])->List[List[int]]:
    res:List[List[int]]=[]
    used:List[bool]=[False]*len(nums)

    def backtrack(current:List[int]):
        if current:
            res.append(current)
        for i in range(len(nums)):
            if not used[i]:
                used[i]=True
                newCurr:List[int]=current[:]
                newCurr.append(nums[i])
                backtrack(newCurr)
                used[i]=False
    backtrack([])
    return res

#duplicateArrangements

def allarrangementsDup(nums:List[int])->List[List[int]]:
    res:List[List[int]]=[]
    mpp:Dict[int,int]={}
    for num in nums:
        mpp[num]=mpp.get(num,0)+1
    def backtrack(current:List[int]):
        if current:
            res.append(current)
        for num in nums:
            if mpp[num]>0:
                mpp[num]-=1
                newCurr:List[int]=current[:]
                newCurr.append(num)
                backtrack(newCurr)
                mpp[num]-=1
    backtrack([])
    return res

#allcombinations
def allcombinations(s:str)->List[str]:
    res:List[str]=[]
    used:List[bool]=[False]*len(s)

    def backtrack(startingIndex:int,current:str):
        if current:
            res.append(current)
        for i in range(startingIndex,len(s)):
            if not used[i]:
                used[i]=True
                backtrack(i+1,current+s[i])
                used[i]=False
    backtrack(0,'')
    return res

#allfixedcombinations
def allfixedcombinations(s:str,r:int)->List[str]:
    res:List[str]=[]
    used:List[bool]=[False]*len(s)

    def backtrack(startingIndex:int,current:str):
        if r==len(current):
            res.append(current)
            return
        needed:int=r-len(current)
        remaining:int=len(s)-startingIndex+1
        if remaining<needed:
            return 
        for i in range(startingIndex,len(s)):
            if not used[i]:
                used[i]=True
                backtrack(i+1,current+s[i])
                used[i]=False
    backtrack(0,'')
    return res

#allfixedarrangementsArray
def allfixedarrangementsArray(nums:List[int],r:int)->List[List[int]]:
    res:List[List[int]]=[]
    used:List[bool]=[False]*len(nums)

    def backtrack(current:List[int]):
        if r==len(current):
            res.append(current)
            return
        for i in range(len(nums)):
            if not used[i]:
                used[i]=True
                newCurr:List[int]=current[:]
                newCurr.append(nums[i])
                backtrack(newCurr)
                used[i]=False
    backtrack([])
    return res


#fixedduplicateArrangements

def allfixedarrangementsDup(nums:List[int],r:int)->List[List[int]]:
    res:List[List[int]]=[]
    mpp:Dict[int,int]={}
    for num in nums:
        mpp[num]=mpp.get(num,0)+1
    def backtrack(current:List[int]):
        if r==len(current):
            res.append(current)
            return
        for num in nums:
            if mpp[num]>0:
                mpp[num]-=1
                newCurr:List[int]=current[:]
                newCurr.append(num)
                backtrack(newCurr)
                mpp[num]-=1
    backtrack([])
    return res


def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res=[]
        mpp={}
        r=len(nums)
        for num in nums:
            mpp[num]=mpp.get(num,0)+1
        def bt(current):
            if r==len(current):
                res.append(current)
                return
            for num in mpp:
                if mpp[num]>0:
                    mpp[num]-=1
                    newCurr=current[:]
                    newCurr.append(num)
                    bt(newCurr)
                    mpp[num]+=1
        bt([])
        return res


def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res=[]
        def bt(start,current):
            if sum(current)==target:
                res.append(current)
                return
            
            for i in range(start,len(candidates)):
                if sum(current)<target:
                    newCurr=current[:]
                    newCurr.append(candidates[i])
                    bt(i,newCurr)
                else:
                    return
        bt(0,[])
        return res

def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res=[]
        def bt(start,current):
            s=sum(current)
            if s==target:
                res.append(current)
                return
            for i in range(start,len(nums)):
                if i>start and nums[i]==nums[i-1]:
                    continue
                if s+nums[i]>target:
                    break

                newCurr=current[:]
                newCurr.append(nums[i])
                bt(i+1,newCurr)
                
        bt(0,[])
        return res


def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res=[]
        nums=[i for i in range(1,10)]
        def bt(start,current):
            s=sum(current)
            if s==n and len(current)==k:
                res.append(current)
                return
            if s>n:
                return
            for i in range(start,len(nums)):
                newCurr=current[:]
                newCurr.append(nums[i])
                bt(i+1,newCurr)
        bt(0,[])
        return res

def numTilePossibilities(self, tiles: str) -> int:
        res=[]
        mpp={}
        for t in tiles:
            mpp[t]=mpp.get(t,0)+1


        def bt(current):
            if current:
                res.append(current)
            for t in mpp:
                if mpp[t]>0:
                    mpp[t]-=1
                    current.append(t)
                    bt(current)
                    current.pop()
                    mpp[t]+=1
        bt([])
        return len(res)