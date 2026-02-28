#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace
std;

void printBinary(int num)
{
	for (int i = 8;i >= 0;--i)
	{
		cout << ((num >> i) & 1);
	}
	cout << endl;
}
bool isBitSet(int num, int i)
{
	return num & (1 << i);
}
int setTheBit(int& num, int i)
{
	return num = num | (1 << i);
}
int unsetTheBit(int& num, int i)
{
	return num = num & (~(1 << i));
}
int toggleTheBit(int& num, int i)
{
	return num = num ^ (1 << i);
}
int countBits(int& num)
{
	int count = 0;
	for (int i = 10;i >= 0;--i)
	{
		if ((num >> i) & 1)
			count++;
	}
	return count;
}
void swap(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
bool isPowerOf2(int num)
{
	return num & (num - 1);
}
void toUpper(char& letter)
{
	letter = (int)letter & ~(1 << 5);
}
void toLower(char& letter)
{
	letter = letter | (1 << 5);
}
void toClearLSB(int& num, int i)
{
	num = num & ~((1 << (i + 1)) - 1);
}
void toClearMSB(int& num, int i)
{
	num = num & ((1 << (i + 1)) - 1);
}
//bitmasking motivationalProblem 
void bitmasking()
{
	int numberOfWorkers;
	cin >> numberOfWorkers;
	vector<int> masks(numberOfWorkers, 0);
	for (int i = 0;i < numberOfWorkers;++i)
	{
		int numberOfDays;
		cin >> numberOfDays;
		int mask = 0;
		for (int i = 0;i < numberOfDays;++i)
		{
			int day;
			cin >> day;
			mask = (mask | (1 << day));
		}
		masks[i] = mask;
	}
	for (int i = 0;i < numberOfWorkers;++i)
	{
		printBinary(masks[i]);
	}
	int maxDays = 0;
	for (int i = 0;i < numberOfWorkers;++i)
	{
		for (int j = i + 1;j < numberOfWorkers;++j)
		{
			bitset<30> worker1Days = masks[i];
			bitset<30> worker2Days = masks[j];
			bitset<30> intersection = worker1Days & worker2Days;
			int countOfCommonDays = intersection.count();
			maxDays = max(maxDays, countOfCommonDays);
		}
	}
	cout << maxDays;
}
vector<vector<int>> subsets(vector<int> nums)
{
	int n = nums.size();
	int noOfSubsets = (1 << n);
	vector<vector<int>> subsets;
	for (int mask = 0;mask < noOfSubsets;++mask)
	{
		vector<int> subset;
		for (int i = 0;i < n;++i)
		{
			if ((mask & (1 << i)) != 0)
			{
				subset.push_back(nums[i]);
			}
		}
		subsets.push_back(subset);
	}
	return subsets;
}
int subsetXORSum(vector<int>& nums)
{
	int totalXorSum = 0;
	int n = nums.size();
	int numberOfCombinations = 1 << n;
	for (int mask = 0;mask < numberOfCombinations;++mask)
	{
		int subsetXOR = 0;
		for (int i = 0;i < n;++i)
		{
			if ((mask & (1 << i)) != 0)
				subsetXOR ^= nums[i];
		}
		totalXorSum += subsetXOR;
	}
	return totalXorSum;
}
vector<string> AllPossibleStrings(string s) {
	// Code here
	vector<string> res;
	int nc = 1 << s.size();
	for (int combo = 0;combo < nc;++combo)
	{
		string subset;
		for (int i = 0;i < s.size();++i)
		{
			if ((combo & (1 << i)) != 0)
			{
				subset.push_back(s[i]);
			}
		}
		res.push_back(subset);
	}
	sort(res.begin(), res.end());
	return res;
}
int hammingDistance(int x, int y) {
	int z = x ^ y;
	bitset<32> r = z;
	return r.count();
}
int totalHammingDistance(vector<int>& nums) {
	int hammingDistance = 0;
	int n = nums.size();
	for (int i = 0;i < n;++i)
	{
		for (int j = i + 1;j < n;++j)
		{
			bitset<32> pairHammingDis = nums[i] ^ nums[j];
			hammingDistance += pairHammingDis.count();
		}
	}
	return hammingDistance;
}
int bitwiseComplement(int n) {
	if (n == 0)
		return -1;
	int numberOfBits = log2(n) + 1;
	unsigned mask = (1U << numberOfBits) - 1;
	return n ^ mask;
}