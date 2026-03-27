
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
