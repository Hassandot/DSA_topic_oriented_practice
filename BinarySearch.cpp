#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include <numeric>
using namespace std;
vector<int> searchRange(vector<int>& arr, int target)
{
	int low, high, mid;
	low = 0;
	high = arr.size() - 1;
	int firstOccurence = INT_MAX, lastOccurance = -1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] == target)
		{
			firstOccurence = min(firstOccurence, mid);
		}
		if (arr[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (firstOccurence == INT_MAX)
		return { -1,-1 };
	low = 0;
	high = arr.size() - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] == target)
		{
			lastOccurance = max(lastOccurance, mid);
		}
		if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return { firstOccurence,lastOccurance };
}
int countOccurrences(const vector<int>& arr, int target) {
	auto firstOccurence = lower_bound(arr.begin(), arr.end(), target);
	if (firstOccurence == arr.end())
		return -1;
	int first = firstOccurence - arr.begin();
	int last = first;
	auto lastOccurence = lower_bound(arr.begin(), arr.end(), target + 1);
	if (lastOccurence != arr.begin() && *(lastOccurence - 1) == target)
		last = (lastOccurence - 1) - arr.begin();
	return last - first + 1;
}
int floor(vector<int>& arr, int target) {
	int low = 0, high = arr.size() - 1;
	int f = INT_MIN;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] <= target)
			f = max(f, mid);
		if (arr[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return arr[f];
}
int ceil(vector<int>& arr, int target)
{
	int low = 0;
	int high = arr.size() - 1;
	int mid;
	int c = INT_MAX;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] >= target)
			c = min(c, mid);
		if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (c != INT_MAX) ? arr[c] : -1;
}
int lowerbound(vector<int>& arr, int target)
{
	int low = 0;
	int high = arr.size() - 1;
	int mid;
	int lb = INT_MAX;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] >= target)
			lb = min(lb, mid);
		if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (lb == INT_MAX) ? -1 : lb;
}
int upperbound(vector<int>& arr, int target)
{
	int low = 0;
	int high = arr.size() - 1;
	int mid;
	int ub = INT_MAX;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] > target)
			ub = min(ub, mid);
		if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (ub != INT_MAX) ? ub : -1;
}
int searchInsertPosition(vector<int>& arr, int target)
{
	int l = 0;
	int h = arr.size() - 1;
	int mid;
	int ip = INT_MAX;
	while (l <= h)
	{
		mid = l + (h - l) / 2;
		if (arr[mid] >= target)
			ip = min(ip, mid);
		if (arr[mid] > target)
			h = mid - 1;
		else
			l = mid + 1;
	}
	return (ip != INT_MAX) ? ip : arr.size();
}
int searchInRotatedSortedArray(vector<int>& arr, int target)
{
	int l = 0;
	int h = arr.size() - 1;
	int mid;
	while (l <= h)
	{
		mid = l + (h - l) / 2;
		if (arr[mid] == target)
			return mid;
		if (arr[l] <= arr[mid])
		{
			if (arr[l] <= target && target <= arr[mid])
			{
				h = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		else {
			if (arr[mid] <= target && target <= arr[h])
			{
				l = mid + 1;
			}
			else
			{
				h = mid - 1;
			}
		}
	}
	return -1;
}
int sortedArray2(vector<int>& arr, int target)
{
	int l = 0;
	int h = arr.size() - 1;
	int mid;
	while (l <= h)
	{
		mid = l + (h - l) / 2;
		if (arr[mid] == target)
			return mid;
		if (arr[l] == arr[mid] && arr[mid] == arr[h])
		{
			l = l + 1;
			h = h - 1;
			continue;
		}
		if (arr[l] <= arr[mid])
		{
			if (target >= arr[l] && target <= arr[mid])
			{
				h = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		else
		{
			if (target >= arr[mid] && target <= arr[h])
			{
				l = mid + 1;
			}
			else {
				h = mid - 1;
			}
		}
	}
	return -1;
}
bool search(vector<int>& nums, int target) {
	int l = 0;
	int h = nums.size() - 1;
	int mid;
	while (l <= h)
	{
		mid = l + (h - l) / 2;
		if (nums[mid] == target)
			return true;
		if (nums[l] == nums[mid] && nums[mid] == nums[h])
		{
			l = l + 1;
			h = h - 1;
			continue;
		}
		if (nums[l] <= nums[mid])
		{
			if (target >= nums[l] && target <= nums[mid])
			{
				h = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		else
		{
			if (target >= nums[mid] && target <= nums[h])
			{
				l = mid + 1;
			}
			else {
				h = mid - 1;
			}
		}
	}
	return false;
}
int findMin(vector<int>& nums) {
	int low = 0;
	int high = nums.size() - 1;
	int ans = INT_MAX;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (nums[low] <= nums[mid]) {
			ans = min(ans, nums[low]);
			low = mid + 1;
		}
		else {
			ans = min(ans, nums[mid]);
			high = mid - 1;
		}
	}
	return ans;
}
int findMin2(vector<int>& nums) {
	int low = 0;
	int high = nums.size() - 1;
	int ans = nums[0];
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] == nums[low] && nums[mid] == nums[high])
		{
			ans = min(ans, nums[low]);
			low++;
			high--;
			continue;
		}
		if (nums[low] <= nums[mid]) {
			ans = min(ans, nums[low]);
			low = mid + 1;
		}
		else {
			ans = min(ans, nums[mid]);
			high = mid - 1;
		}
	}
	return ans;
}
int timesArrayRotated(vector<int>& nums)
{
	int low = 0;
	int high = nums.size() - 1;
	int mid;
	int ans = INT_MAX;
	int index = INT_MAX;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (nums[low] <= nums[mid])
		{
			if (nums[low] < ans)
			{
				ans = min(nums[low], ans);
				index = low;
			}
			low = mid + 1;
		}
		else
		{
			if (ans > nums[mid])
			{
				ans = min(ans, nums[mid]);
				index = mid;
			}
			high = mid - 1;
		}
	}
	return index;
}
int singleNonDuplicate(vector<int>& nums) {
	if (nums.size() == 1)
		return nums[0];
	int n = nums.size();
	if (nums[0] != nums[1])
		return nums[0];
	if (nums[n - 1] != nums[n - 2])
		return nums[n - 1];
	int low = 1;
	int high = n - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
			return nums[mid];
		if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
		{
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}
//eko
//{2,3,4,5,6}
// 
//m=requiredWoods=6
// now we have to give the maximum height to cut the tree to get suficient woods
int getWoods(vector<int>& trees, int cuttingHeight)
{
	int totalWoods = 0;
	for (int i = 0;i < trees.size();++i)
	{
		if (trees[i] >= cuttingHeight)
		{
			totalWoods += trees[i] - cuttingHeight;
		}
	}
	return totalWoods;
}
int Eko(vector<int>& trees, int m)
{
	int maxHeight = *max_element(trees.begin(), trees.end());
	int low = 0;
	int high = maxHeight;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (getWoods(trees, mid) >= m)
		{
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return high;
}
int squareroot(int num)
{
	int low = 1;
	int high = num;
	int ans = 1;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (mid * mid <= num)
		{
			ans = max(ans, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}
bool calculatePower(int num, int times, int max)
{
	int total = num;
	for (int i = 1;i < times;++i)
	{
		total *= num;
		if (total >= max)
		{
			return false;
		}
	}
	return true;
}
int nthroot(int num, int root)
{
	int low = 1;
	int high = num;
	int ans = 1;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (calculatePower(mid, root, num))
		{
			ans = max(ans, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}
long long int hoursToEatBananas(vector<int>& piles, int bananaPerHour)
{
	long long int totalHours = 0;
	for (int i = 0;i < piles.size();++i)
	{
		totalHours += ceil((double)piles[i] * 1LL / (double)bananaPerHour * 1LL);
	}
	return totalHours;
}
int minEatingSpeed(vector<int>& piles, int h)
{
	int n = *max_element(piles.begin(), piles.end());
	int low = 1;
	int high = n;
	int ans = n;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (hoursToEatBananas(piles, mid) <= h)
		{
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}
bool isPossible(vector<int>& bloomDays, int bouquents, int adjacent, int flowerday)
{
	int totalBouquentsFormed = 0;
	int totalFlowergathered = 0;
	for (int i = 0;i < bloomDays.size();++i)
	{
		if (bloomDays[i] > flowerday)
		{
			totalBouquentsFormed += totalFlowergathered / adjacent;
			totalFlowergathered = 0;
		}
		else {
			totalFlowergathered++;
		}
	}
	totalBouquentsFormed += totalFlowergathered / adjacent;
	if (totalBouquentsFormed >= bouquents)
		return true;
	return false;
}
//int minDays(vector<int>& bloomDay, int m, int k) 
//{
//	if (bloomDay.size() < m * k)
//		return -1;
//	int max = *max_element(bloomDay.begin(), bloomDay.end());
//	int min = *min_element(bloomDay.begin(), bloomDay.end());
//	for (;min <= max;++min)
//	{
//		if (isPossible(bloomDay, m, k, min))
//		{
//			return min;
//		}
//	}
//	return -1;
//}
int minDays(vector<int>& bloomDay, int m, int k)
{
	if (bloomDay.size() < m * k)
		return -1;
	int max = *max_element(bloomDay.begin(), bloomDay.end());
	int minimum = *min_element(bloomDay.begin(), bloomDay.end());
	int low = minimum;
	int high = max;
	int mid;
	int ans = INT_MAX;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (isPossible(bloomDay, m, k, mid))
		{
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return (ans != INT_MAX) ? ans : -1;
}
//{1,2,3,4,5,6,7,8,9,10};
//days=5
int requiredDays(vector<int>& weights, int weight)
{
	int days = 0;
	int maxCarrier = 0;
	for (int i = 0;i < weights.size();++i)
	{
		if (maxCarrier + weights[i] > weight)
		{
			days++;
			maxCarrier = weights[i];
		}
		else {
			maxCarrier += weights[i];
		}
	}
	return ++days;
}
//int shipWithinDays(vector<int>& weights, int days) {
//	int start = *max_element(weights.begin(), weights.end());
//	int end = accumulate(weights.begin(), weights.end(), 0);
//	for (;start <= end;++start)
//	{
//		if (requiredDays(weights, start) <= days)
//			return start;
//	}
//	return -1;
//}
int shipWithinDays(vector<int>& weights, int days) {
	int low = *max_element(weights.begin(), weights.end());
	int high = accumulate(weights.begin(), weights.end(), 0);
	int ans = high;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (requiredDays(weights, mid) <= days)
		{
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}
bool isItPossible(vector<int>& stalls, int minDistance, int requiredCows)
{
	int cows = 1;
	int previousStall = stalls[0];
	for (int i = 1;i < stalls.size();++i) {
		if ((stalls[i] - previousStall) >= minDistance)
		{
			cows++;
			previousStall = stalls[i];
		}
	}
	if (cows >= requiredCows)
		return true;
	return false;
}
int aggressiveCows(vector<int>& stalls, int k) {

	int start = 1;
	sort(stalls.begin(), stalls.end());
	int end = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
	int maxDistance = start;
	for (;start <= end;++start)
	{
		if (isItPossible(stalls, start, k))
		{
			maxDistance = max(maxDistance, start);
		}
		else {
			break;
		}
	}
	return maxDistance;
}
bool canBeAllocated(vector<int>& pages, int maxPages, int maxStudent)
{
	int students = 0;
	int allocatedPages = 0;
	for (int i = 0;i < pages.size();++i)
	{
		if ((allocatedPages + pages[i]) > maxPages)
		{
			students++;
			allocatedPages = pages[i];
		}
		else {
			allocatedPages += pages[i];
		}
	}
	if (++students <= maxStudent)
		return true;
	return false;
}
int findPages(vector<int>& arr, int k) {
	if (arr.size() < k)
		return -1;
	int low = *max_element(arr.begin(), arr.end());
	int high = accumulate(arr.begin(), arr.end(), 0);
	int mid;
	int ans = high;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (canBeAllocated(arr, mid, k))
		{
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}
bool splitPossible(vector<int>& nums, int maxSplit, int maxPossibleSplit)
{
	int countOfSplit = 0;
	int currentSplit = 0;
	for (int i = 0;i < nums.size();++i)
	{
		if ((currentSplit + nums[i]) > maxSplit)
		{
			countOfSplit++;
			currentSplit = nums[i];
		}
		else {
			currentSplit += nums[i];
		}
	}
	if (++countOfSplit <= maxPossibleSplit)
		return true;
	return false;
}
int splitArray(vector<int>& nums, int k) {
	int low = *max_element(nums.begin(), nums.end());
	int high = accumulate(nums.begin(), nums.end(), 0);
	int mid;
	int ans = high;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (splitPossible(nums, mid, k))
		{
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}