
from typing import List


class Solution:
    def __init__(self):
        self._encryptTable:Dict[str,str]={}
        self._decryptTable:Dict[str,str]={}
        self.initializeTable()
        self.indexes=[]
        self.outputCount=0
    def initializeTable(self):
        key = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm"
        alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
        self._encryptTable=dict(zip(alphabet,key))
        self._decryptTable=dict(zip(key,alphabet))
    def Encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        cipher:str=''
        for character in longUrl:
            if character.isalpha():
                cipher+=self._encryptTable[character]
            else:
                cipher+=character
        return cipher

    def Decode(self, shortUrl: str) -> str:
        plaintext:str=''
        for character in shortUrl:
            if character.isalpha():
                plaintext+=self._decryptTable[character]
            else:
                plaintext+=character
        return plaintext
    def encode(self, strs: List[str]) -> str:
        msg=''
        for w in strs:
            leng=len(w)
            self.outputCount+=1
            self.indexes.append(leng)
            msg+=self.Encode(w)
        return msg
    def decode(self, s: str) -> List[str]:
        res=[""]*self.outputCount
        currDeccryptedText=''
        n=len(s)
        i=0
        starter=0
        j=0
        while starter<n:
            curr=s[starter:starter+self.indexes[i]]
            res[j]=self.Decode(curr)
            starter+=self.indexes[i]
            i+=1
            j+=1
        return res
def productExceptSelf(self, nums: List[int]) -> List[int]:
        n=len(nums)
        prefix=[1]*(n+1)
        postfix=[1]*(n+1)
        for i in range(n):
            prefix[i+1]=prefix[i]*nums[i]
        for i in range(n-1,-1,-1):
            postfix[i]=postfix[i+1]*nums[i]
        res=[]
        for i in range(n):
            res.append(prefix[i]*postfix[i+1])
        return res

def hasDuplicate(self, nums: List[int]) -> bool:
        mpp={}
        for num in nums:
            mpp[num]=mpp.get(num,0)+1
            if mpp[num]==2:
                return True
        return False
def isAnagram(self, s: str, t: str) -> bool:
        mpp1,mpp2={},{}
        for ch in s:
            mpp1[ch]=mpp1.get(ch,0)+1
        for ch in t:
            mpp2[ch]=mpp2.get(ch,0)+1
        if len(mpp1)!=len(mpp2):
            return False
        if set(s)!=set(t):
            return False
        for key,value in mpp1.items():
            if mpp2[key]!=value:
                return False
        return True

def twoSum(self, nums: List[int], target: int) -> List[int]:
        mpp={}
        for i in range(len(nums)):
            if target-nums[i] in mpp:
                return [mpp[target-nums[i]],i]
            else:
                mpp[nums[i]]=i
        return []

def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mpp={}
        for w in strs:
            k=sorted(w)
            mpp[tuple(k)]=mpp.get(tuple(k),[])
            mpp[tuple(k)].append(w)
        return [value for key,value in mpp.items()]
def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mpp={}
        for num in nums:
            mpp[num]=mpp.get(num,0)+1
        arr=[(key,value) for key,value in mpp.items()]
        arr.sort(reverse=True,key=lambda x:x[1])
        res=[]
        for i,p in enumerate(arr):
            if i==k:
                break
            else:
                res.append(p[0])
        return res
def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        arr=list(set(nums))
        arr.sort()
        lastbest=0
        currentbest=1
        lastelement=arr[0]
        for i in range(1,len(arr)):
            if (arr[i]-lastelement)==1:
                lastelement=arr[i]
                currentbest+=1
            else:
                lastbest=max(lastbest,currentbest)
                currentbest=1
                lastelement=arr[i]
        return max(currentbest,lastbest)



def isValidSudoku(board: List[List[str]]) -> bool:
    m=len(board)
    n=len(board[0])
    rows=[]
    matrixs=[]
    for i in range(m):
        mpp={}
        row=[]
        for j in range(n):
            row.append(board[i][j])
            if (j+1)%3==0:
                rows.append(row)
                row=[]
            if board[i][j].isdigit():
                mpp[board[i][j]]=mpp.get(board[i][j],0)+1
                if mpp[board[i][j]]==2:
                    return False
        if (i+1)%3==0:
            for x in range(3):
                mat=[]   
                mat.append(rows[x])
                temp=x
                for y in range(2):
                    mat.append(rows[temp+3])
                    temp+=3
                matrixs.append(mat)
            rows=[]
    for matrix in matrixs:
        mpp={}
        for i in range(3):
            for j in range(3):
                if matrix[i][j].isdigit():
                    mpp[matrix[i][j]]=mpp.get(matrix[i][j],0)+1
                    if mpp[matrix[i][j]]==2:
                        return False

    for i in range(n):
        mpp={}
        for j in range(m):
            if board[j][i].isdigit():
                mpp[board[j][i]]=mpp.get(board[j][i],0)+1
                if mpp[board[j][i]]==2:
                    return False
    return True

def isPalindrome(self, s: str) -> bool:
        low,high=0,len(s)-1
        while low<=high:
            if not s[low].isalnum():
                low+=1
                continue
            elif not s[high].isalnum():
                high-=1
                continue
            elif s[low].isalnum() and s[high].isalnum():
                if s[low].lower()!=s[high].lower():
                    return False
                else:
                    low+=1
                    high-=1
        return True
def twoSum(self, numbers: List[int], target: int) -> List[int]:
        low,high=0,len(numbers)-1
        while low<high:
            res=numbers[low]+numbers[high]
            if res>target:
                high-=1
            elif res<target:
                low+=1
            else:
                return [low+1,high+1]
        return []


def singleNumber(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        ans=nums[0]
        for i in range(1,len(nums)):
            ans=ans^nums[i]
        return ans

def isValid(self, s: str) -> bool:
        stack=[]
        mpp={'}':'{',']':'[',')':'('}
        for i in range(len(s)):
            if s[i]=='(' or s[i]=='{' or s[i]=='[':
                stack.append(s[i])
            else:
                if len(stack)==0 or stack.pop()!=mpp[s[i]]:
                    return False
        if len(stack)!=0:
            return False
        return True
class MinStack:

    def __init__(self):
        self.stack=[]

    def push(self, val: int) -> None:
        self.stack.append(val)

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return min(self.stack)
def evalRPN(self, tokens: List[str]) -> int:
        stack=[]
        for i in range(len(tokens)):
            if tokens[i] in '+-*/':
                secondnumber=stack.pop()
                firstnumber=stack.pop()
                if tokens[i]=='+':
                    stack.append(firstnumber+secondnumber)
                elif tokens[i]=='-':
                    stack.append(firstnumber-secondnumber)
                elif tokens[i]=='*':
                    stack.append(firstnumber*secondnumber)
                else :
                    stack.append(int(float(firstnumber)/secondnumber))
            else:
                stack.append(int(tokens[i]))
        return stack.pop()