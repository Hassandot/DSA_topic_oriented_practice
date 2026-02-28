#include <iostream>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include<numeric>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include <map>
#include <stack>
#include<vector>
#include<bit>
#include <bitset>
const int mod = 1e9 + 7;
const int n = 1e6;
#define ll long long
using namespace std;
const int N = 1e5 + 10;
vector<bool> vis(N,0);
vector<int> g[N];
bool dfs(int vertex,int parent)
{
	vis[vertex] = true;
	bool isLoopExist = false;
	for (int child : g[vertex])
	{
		if (vis[child] && child==parent) continue;
		if (vis[child]) return true;
			
		isLoopExist|=dfs(child,vertex);
	}
	return isLoopExist;
}
void dfs(vector<vector<char>>& grid,int i,int j)
{
	int row, col;
	row = grid.size();
	col = grid[0].size();
	if (i < 0 || j < 0 || i >= row || j >= col) return;
	if (grid[i][j] == '1') grid[i][j] = '0';
	else return;

	dfs(grid, i - 1, j);
	dfs(grid, i + 1, j);
	dfs(grid, i, j-1);
	dfs(grid, i, j+1);
}
int numIslands(vector<vector<char>>& grid) {
	int count = 0;
	for (int i=0;i<grid.size();++i)
	{
		for (int j = 0;j < grid[0].size();++j)
		{
			if (grid[i][j] == '1')
			{
				count++;
				dfs(grid, i, j);
			}
		}
	}
	return count;
}
//incomplete problem wronge approch should be refine later
int numberOfSequence(string tiles)
{
	unordered_set<string> sequences;
	int noc = 1 << tiles.size();
	for (int mask = 1;mask < noc;++mask)
	{
		string sequence;
		for (int i = 0;i < tiles.size();++i)
		{
			if (mask & (1 << i))
				sequence.push_back(tiles[i]);
		}
		sequences.insert(sequence);
	}
	return sequences.size();
}
int numTilePossibilities(string tiles) {
	int count = 0;
	for (int i = 1;i < tiles.size();++i)
	{
		string tile = tiles.substr(0, i);
		count+=numberOfSequence(tile);
	}
	return count;
}
vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
	int exLeft = 0;
	int exRight = n - 1; 
	unordered_map<char, pair<int, int>> mpp;
	mpp['R'] = { 0,1 };
	mpp['L'] = { 0,-1 };
	mpp['U'] = { -1,0 };
	mpp['D'] = { 1,0 };
	vector<int> res;
	for (int i = 0;i < s.size();++i)
	{
		int startRow = startPos[0];
		int startCol = startPos[1];
		int steps = 0;
		for (int j = i;j < s.size();++j)
		{
			startRow += mpp[s[j]].first;
			startCol += mpp[s[j]].second;
			if (startRow<exLeft || startRow>exRight || startCol<exLeft || startCol>exRight)
				break;
			steps++;
		}
		res.push_back(steps);
	}
	return res;
}
string binary(int num)
{
	if (num == 0)
		return "0";
	if (num == 1)
		return "1";
	return binary(num / 2) + to_string(num % 2);
}
string findDifferentBinaryString(vector<string>& nums) {
	int noc = 1<<nums.size();
	for (int mask = 0;mask < noc;++mask)
	{
		string bin=binary(mask);
		int n = bin.size();
		for (int i = 0;i < nums.size() - n;++i)
			bin = "0" + bin;
		auto it=find(nums.begin(), nums.end(), bin);
		if (it == nums.end())
			return bin;
	}
	return "";
}
vector<string> stringSequence(string target) {
	string temp = "a";
	vector<string> res;
	int n = target.size();
	int i = 0;
	while(true)
	{
		res.push_back(temp);
		if (temp[i] == target[i])
		{
			if (temp == target)
				break;
			i++;
			temp += "a";
		}
		else
			temp[i] += 1;
	}
	return res;
}
int minimumPushes(string word) {
	unordered_map<char, int> frempp;
	for (const char& ch : word) frempp[ch]++;
	vector<pair<char, int>> sortedword(frempp.begin(), frempp.end());
	sort(sortedword.begin(), sortedword.end(), [](const pair<char, int>& a, const pair<char, int>& b) {return a.second > b.second;});
	unordered_set<char> set;
	unordered_map<char, int> mpp;
	int letterCost = 0;
	int totalCost = 0;
	for (const auto&pair:sortedword)
	{
		if (set.size() % 8 == 0)
			letterCost++;
		int previousSetSize = set.size();
		set.insert(pair.first);
		if (set.size() != previousSetSize)
		{
			mpp[pair.first] = letterCost;
		}
	}
	for (const char& ch : word)
	{
		totalCost += mpp[ch];
	}
	return totalCost;
}
string removeOccurrences(string s, string part) {
	bool flag = false;
	while (!flag)
	{
		int it=s.find(part);
		if ( it== string::npos)
			flag = true;
		else
		{
			int startIndex = it;
			int endIndex = startIndex + part.size()-1;
			string temp;
			for (int i = 0;i < s.size();++i)
			{
				if ((i >= startIndex) && (i <= endIndex))
					continue;
				temp.push_back(s[i]);
			}
			s = temp;
		}
	}
	return s;
}
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

	unordered_set<char> stt(pattern.begin(), pattern.end());
	vector<int> seq;
	int currentConsegitive = 1;
	for (int i = 1;i < pattern.size();++i)
	{
		if (pattern[i] == pattern[i - 1])
		{
			currentConsegitive++;
		}
		else
		{
			seq.push_back(currentConsegitive);
			currentConsegitive = 1;
		}
	}
	seq.push_back(currentConsegitive);
	int n = stt.size();
	vector<string> res;
	for (const string& word : words)
	{
		unordered_map<char, int> temp;
		for (const char& ch : word) temp[ch]++;
		if (temp.size() == n)
		{
			vector<int> temp_seq;
			int currentConsegitive = 1;
			int insert = 0;
			for (int i = 1;i < word.size();++i)
			{
				if (word[i] == word[i - 1])
				{
					currentConsegitive++;
				}
				else
				{
					temp_seq.push_back(currentConsegitive);
					currentConsegitive = 1;
				}
			}
			temp_seq.push_back(currentConsegitive);

			if (temp_seq == seq)
				res.push_back(word);
		}
	}
	return res;
}
bool hasIncreasingSubarrays(vector<int>& nums, int k) {
	int size = 0;
	for (int i = 0;i + 1 < nums.size();++i)
	{
		int temp_size = 0;
		for (int j = i;j + 1 < nums.size();++j)
		{
			if (nums[j + 1] > nums[j])
				temp_size++;
			else
				break;
		}
		size = max(size, temp_size+1);
	}
	if (size == 0)
		size = 1;
	if (size >= k)
		return true;
	return false;
}
string bin(int num)
{
	if (num == 0) return "0";
	if (num == 1) return "1";
	return bin(num / 2) + to_string(num % 2);
}
//8 -> 0
//4- >0
//2 -> 0
//1->  1000
int bs(vector<int>& array, int start, int end, int target)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;
	if (array[mid] == target)
		return mid;
	else if (array[mid] < target)
		return bs(array, mid + 1, end, target);
	else
		return bs(array, start, mid - 1, target);
}
void sumTriangle(vector<int>& array)
{
	if (array.size() == 1)
	{
		cout << array[0]<<'\n';
		return;
	}
	vector<int> arr;
	for (int i = 0;i + 1 < array.size();++i)
		arr.push_back(array[i] + array[i + 1]);
	sumTriangle(arr);
	for (int i = 0;i < array.size();++i)
		cout << array[i] << " ";
	cout << endl;
}
vector<int> minMax(vector<int> array, int index)
{
	if (index == 0)
		return { array[0],array[0] };
	vector<int> res=minMax(array, index - 1);
	if (res[0] > array[index])
		res[0] = array[index];
	if (res[1] < array[index])
		res[1] = array[index];
	return res;
}
vector<int> getMinMax(vector<int>& arr) {
	return minMax(arr, arr.size() - 1);
}
char firstLetter(string letters,int n,int index)
{
	if ( n == index)
		return ' ';
	if (isupper(letters[index]))
		return letters[index];
	return firstLetter(letters, n, ++index);
}
void reverseString(vector<char>& s, int n,int index) {
	if (n - 1 == index)
		return;
	reverseString(s, n, ++index);
	cout << s[index];
}
void printNos(int n) {
	if (n == 0)
		return;
	printNos(n - 1);
	cout << n;
}
//int fib(int n) {
//	if (n < 2)
//		return n;
//	return fib(n - 1) + fib(n - 2);
//}
int specialFib(int a, int b,int n)
{
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	if (n == 2)
		return a ^ b;
	return specialFib(a, b, n%3);
}
int stringLength(string word)
{
	if (word.empty())
		return 0;
	return 1+stringLength(word.substr(1));
}
int fib(int a, int b, int c, int n)
{
	if (n == 1)
		return a;
	if (n == 2)
		return b;
	if (n == 3)
		return c;
	return fib(a,b,c,n - 1) + fib(a,b,c,n - 2) + fib(a,b,c,n - 3);
}
void bubbleSort(vector<int>& array, int n, int count)
{
	if (count == 0)
		return;
	int cnt = 0;
	for (int i = 0;i+1 < n;++i)
	{
		if (array[i] >= array[i + 1])
		{
			swap(array[i], array[i + 1]);
			cnt++;
		}
	}
	bubbleSort(array, n - 1, cnt);
}
void insertionsort(vector<int>& arr, int index)
{
	if (index == arr.size())
		return;
	int num = arr[index];
	arr.erase(arr.begin() + index);
	for (int i = 0;i <arr.size();++i)
	{
		if (num <= arr[i])
		{
			arr.insert(arr.begin()+i,num);
			break;
		}
	}
	insertionsort(arr, index+1);
}
int digitSum(int number)
{
	if (number == 0)
		return 0;
	int lastDigit = number % 10;
	return lastDigit+digitSum(number / 10);
}
int multiply(int a, int b)
{
	if (b == 0)
		return 0;
	return a + multiply(a, b - 1);
}
bool isPrime(int num,int divisor=2) {
	if (divisor == num)
		return true;
	if (divisor * divisor > num)
		return true;
	return (num % divisor == 0) ? false : isPrime(num, ++divisor);
}
int sum(int n)
{
	if (n == 1)
		return 1;
	return n + sum(--n);
}
int fac(int n)
{
	if (n <= 1)
		return 1;
	return n * fac(n - 1);
}
bool issorted(vector<int>& arr ,int index=0,int previousNumber=INT_MIN)
{
	if (index == arr.size())
		return true;
	return (previousNumber <= arr[index]) ? issorted(arr,index+1,arr[index] ) : false;
}
int helper(int num, int count = 0)
{
	if (num == 0)
		return count;
	if (num & 1)
		num--;
	else
		num >>= 1;
	return helper(num, ++count);
}
int numberOfSteps(int num) {
	return helper(num);
}
string removeDub(string word, string newWord="", int index = 0)
{
	if (word.size() == 1)
		return word;
	if (index == word.size())
		return newWord;
	if (newWord.empty())
		newWord.push_back(word[index]);
	if (newWord[newWord.size() - 1] != word[index])
		newWord.push_back(word[index]);
	return removeDub(word, newWord, ++index);
}
void revNumber(int num)
{
	if (num == 0)
		return ;
	cout<<num % 10;
	revNumber(num / 10);
}
int numberReverse(int num)
{
	int sum = 0;
	int multiplier = 10;
	while (num != 0)
	{
		sum = sum * multiplier;
		sum+=num % 10;
		num /= 10;
	}
	return sum;
}
int inplacereverse(int num)
{
	if (num <10)
		return num;

	int lastDigit = num % 10;
	int coming=inplacereverse(num / 10);
	lastDigit = (lastDigit * pow(10,floor( log10(coming) + 1))) + coming;
	return lastDigit;
}
bool isnumberpal(int number)
{
	if (number < 10)
		return true;
	
	if (floor(number / pow(10, floor(log10(number)))) != number % 10)
		return false;
	number = number % static_cast<int>(pow(10, floor(log10(number))));
	number /= 10;
	return isnumberpal(number);
}
int numberOfZeros(int number,int count=0)
{
	if (number < 10)
		return (number == 0) ? ++count : count;
	return (number % 10 == 0) ? numberOfZeros(number / 10, ++count) : numberOfZeros(number / 10, count);
}
string removeLetter(string word, string result,int index = 0, char letter='a')
{
	if (index == word.size())
		return result;
	if (word[index] != letter)
		result.push_back(word[index]);
	return removeLetter(word, result, ++index, letter);
}
string removeLetter(string word, char letter, int index = 0)
{
	if (index == word.size())
		return "";
	string l = "";
	if (word[index] != letter)
		l = word[index];
	return l+ removeLetter(word, letter, ++index);
}
int evenNumberBitwiseORs(vector<int>& nums) {
	int res = 0;
	bool found = false;
	for (int& num : nums)
	{
		if (!found && (!(num & 1)))
		{
			found = true;
			res = num;continue;
		}
		else if (!(num & 1))
		{
			if ((res ^ num) == 0)
				continue;
			res = res ^ num;
		}
	}
	return res;
}
int encrypt(int num)
{
	int length = floor(log10(num) + 1);
	int maxDigit = -1;
	while (num != 0)
	{
		maxDigit = max(maxDigit, num % 10);
		num /= 10;
	}
	string number;
	for (int i = 0;i < length;++i)
	{
		number += to_string(maxDigit);
	}
	return stoi(number);
}
//int digitSum(int number)
//{
//	if (number == 0)
//		return 0;
//	int lastDigit = number % 10;
//	return lastDigit + digitSum(number / 10);
//}
int helper(unordered_map<int, int>& mpp,int lowLimit, int highLimit,int maximum)
{
	if (lowLimit > highLimit)
		return maximum;
	int num = digitSum(lowLimit);
	mpp[num]++;
	return helper(mpp,lowLimit+1, highLimit,max(mpp[num], maximum));
}
int countBalls(int lowLimit, int highLimit) {
	unordered_map<int, int> mpp;
	return helper(mpp,lowLimit, highLimit,0);
}
string shortestCompletingWord(string licensePlate, vector<string>& words) {
	unordered_map<char, int> mpp;
	for (char ch : licensePlate)
	{
		if (isalpha(ch))
		{
			mpp[tolower(ch)]++;
		}
	}
	string res = "";
	for (int i = 0;i < words.size();++i)
	{
		unordered_map<char, int> fre_mpp;
		for (char ch : words[i]) fre_mpp[ch]++;
		unordered_set<char> stt(words[i].begin(), words[i].end());
		bool flag = false;
		int findCount = 0;
		for (char ch : stt)
		{
			if (mpp.count(ch))
			{
				if (fre_mpp[ch] >= mpp[ch])
					findCount++;
				else
				{
					flag = true;
					break;
				}
			}
		}
		if (!flag&&findCount==mpp.size())
		{
			if (res.empty() || res.size() > words[i].size())
				res = words[i];
		}
	}
	return res;
}
int main()
{
	/*
	int v, e;
	cin >> v >> e;
	for (int i = 0;i < e;++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	cout << "Is Loop exist :" << dfs(0, -1);*/
	int number;
	cout << "Enter the number ";
	cin >> number;
	for (int i = 0;i < number;++i)
	{
		for (int j = i;j < number;++j)
		{
			cout << j;
		}
		cout << '\n';
	}
}

