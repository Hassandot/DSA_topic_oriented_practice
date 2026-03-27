
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