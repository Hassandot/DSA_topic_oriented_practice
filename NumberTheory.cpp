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
int calPower(int a, int b)
{
	int result = 1;
	for (int i = 1;i <= b;++i)
	{
		result *= a;
	}
	return result;
}
int fast_calPower(int a, int b)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			b--;
			res *= a;
		}
		else {
			b >>= 1;
			a *= a;
		}
	}
	return res;
}
int binaryExponentiation(int a, int b)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			res = (res * 1LL * a) % mod;
		}
		b >>= 1;
		a = (a * 1LL * a) % mod;
	}
	return res;
}
int gcd(int a, int b)
{
	while (a > 0)
	{
		int rem = b % a;
		b = a;
		a = rem;
	}
	return b;
}
int gcd_cal(int dividend, int divisor)
{
	if (divisor == 0)
		return dividend;
	return gcd_cal(divisor, dividend % divisor);
}
int lcm(int a, int b)
{
	return (a * b) / gcd_cal(a, b);
}
ll binaryExponentiation_safe(ll a, ll b, int MOD)
{
	a %= MOD;
	ll ans = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			ans = (ans * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD;
	}
	return ans;
}
ll safe_multiplication(ll a, ll b)
{
	a %= mod;
	ll ans = 0;
	while (b > 0)
	{
		if (b & 1)
			ans = (ans + a) % mod;
		b >>= 1;
		a = (a + a) % mod;
	}
	return ans;
}
ll be_safest(ll a, ll b)
{
	a %= mod;
	b %= mod;
	ll ans = 1;
	while (b > 0)
	{
		if (b & 1)
			ans = safe_multiplication(ans, a);
		b >>= 1;
		a = safe_multiplication(a, a);
	}
	return ans;
}
vector<vector<int>> subsets(vector<int>& nums) {
	int n = nums.size();
	int noOfSubsets = 1 << n;
	vector<vector<int>> masks;
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
		masks.push_back(subset);
	}
	return masks;
}
vector<vector<int>> unique_subsets(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	map<int, int> mpp;
	for (const int& num : nums)
		mpp[num]++;
	vector<int> unique_nums;
	vector<int> countsOfEachElement;
	for (const auto& p : mpp)
	{
		unique_nums.push_back(p.first);
		countsOfEachElement.push_back(p.second);
	}
	int numberOfCombinations = 1;
	for (const int& count : countsOfEachElement)
		numberOfCombinations *= count + 1;
	vector<vector<int>> subsets;
	int countOfUniqueNumbers = unique_nums.size();
	for (int combination_id = 0;combination_id < numberOfCombinations;++combination_id)
	{
		vector<int> subset;
		int temp = combination_id;
		for (int i = 0;i < countOfUniqueNumbers;++i)
		{
			int choicesOfithElement = countsOfEachElement[i] + 1;
			int numberOfElementToPick = temp % choicesOfithElement;
			temp /= choicesOfithElement;
			for (int j = 0;j < numberOfElementToPick;++j)
			{
				subset.push_back(unique_nums[i]);
			}
		}
		subsets.push_back(subset);
	}
	return subsets;
}
bool isPrime(int num)
{
	if (num == 1)
		return false;
	for (int i = 2;i * i <= num;++i)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
vector<int> primeNumbers(int start, int end) {
	vector<int> primes;
	for (;start <= end;++start)
	{
		if (isPrime(start))
			primes.push_back(start);
	}
	return primes;
}
void generatePrimes(int num)
{
	vector<int> primes(50, 1);
	primes[0] = primes[1] = 0;
	for (int i = 2;i * i < 50;++i)
	{
		if (primes[i] == 1)
		{
			for (int j = i * 2;j < 50;j += i)
			{
				primes[j] = 0;
			}
		}
	}
	for (int i = 0;i < 50;++i)
	{
		if (primes[i] == 1)
			cout << i << " ";
	}
}
vector<int> primeRange(int M, int N)
{
	const int size = N + 1;
	vector<bool> primes(size, 1);
	primes[0] = primes[1] = false;
	for (int i = 2;i * i <= N;++i)
	{
		if (primes[i])
		{
			for (int j = i * i;j <= N;j += i)
			{
				primes[j] = false;
			}
		}
	}
	vector<int> res;
	for (int i = max(M, 2);i <= N;++i)
	{
		if (primes[i])
			res.push_back(i);
	}
	return res;
}
vector<int> primefacTrialDivision(int num)
{
	vector<int> pf;
	for (int i = 2;i * i <= num;++i)
	{
		if (num % i == 0)
		{
			while (num % i == 0)
			{
				pf.push_back(i);
				num /= i;
			}
		}
	}
	if (num > 1)
		pf.push_back(num);
	return pf;
}
vector<int> primefacWheelFac(int num)
{
	vector<int> pf;
	while (!(num % 2))
	{
		pf.push_back(2);
		num /= 2;
	}
	for (int i = 3;i * i <= num;i += 2)
	{
		if (!(num % i))
		{
			while (!(num % i))
			{
				pf.push_back(i);
				num /= i;
			}
		}
	}
	if (num > 1)
		pf.push_back(num);
	return pf;
}
vector<int> primefacBySeive(int num)
{
	//when their is a query problem
	const int size = 1000;
	vector<int> primefac(size, 1);
	primefac[0] = primefac[1] = 0;
	for (int i = 2;i * i < size;++i)
	{
		if (primefac[i] == 1)
		{
			primefac[i] = i;
			for (int j = i * i;j < size;j += i)
			{
				if (primefac[j] == 1)
					primefac[j] = i;
			}
		}
	}
	vector<int> primesfac;
	while (primefac[num] > 0)
	{
		primesfac.push_back(primefac[num]);
		num /= primefac[num];
	}
	return primesfac;
}
pair<int, int> lowestAndHighestPrimefac(int num)
{
	//this is mostly useful for query problems
	vector<int> hp(101, 1);
	vector<int> lp(101, 1);
	vector<int> p(101, 1);
	hp[0] = lp[0] = p[0] = 0;
	hp[1] = lp[1] = p[1] = 0;
	for (int i = 2;i * i <= 100;++i)
	{
		if (p[i] == 1)
		{
			if (lp[i] == 1)
				lp[i] = i;
			hp[i] = i;
			for (int j = 2 * i;j <= 100;j += i)
			{
				p[j] = 0;
				hp[j] = i;
				if (lp[j] == 1)
					lp[j] = i;
			}
		}
	}
	return { lp[num],hp[num] };
}
ll fermatTheorem(ll num, ll modulo)
{
	//fermat little theorem gives us the inverse of a number if the mod is prime by a simple formula of taking the power of mod-2
	return (isPrime(modulo)) ? binaryExponentiation_safe(num, modulo - 2, modulo) : 0;
}
ll F[1000001];
void preComputeFactorial(int MOD)
{
	F[0] = F[1] = 1;
	for (int i = 2;i <= 100000;++i)
		F[i] = (F[i - 1] * 1LL * i) % MOD;
}
ll binomialCoefficient(int N, int k)
{
	if (k<0 || k>N)
		return 0;
	return F[N] / (F[k] * F[N - k]);
}
int binomialCoefficient_mod(int n, int k, int MOD)
{
	preComputeFactorial(MOD);
	if (k > n) return 0;
	int numenator = F[n];
	int denomenator = (F[k] * F[n - k]) % MOD;
	int inverse_mod = fermatTheorem(denomenator, MOD);
	return (numenator * inverse_mod) % MOD;
}
int EulerTotientFun(int num, int n = 1)
{
	if (isPrime(num) && n == 1)
		return num - 1;
	else if (isPrime(num) && n != 1)
		return binaryExponentiation(num, n - 1) * (num - 1);
	else
	{
		int res = num;
		for (int i = 2;i * i <= num;++i) {
			if (num % i == 0)
			{
				res /= i;
				res *= i - 1;
				while (num % i == 0)
					num /= i;
			}
		}
		if (num > 1)
		{
			res /= num;
			res *= (num - 1);
		}
		return res;
	}
}
int ETF[n + 1];
void ETF_seive(int query)
{
	for (int i = 0;i <= n;++i)
		ETF[i] = i;
	for (int i = 2;i * i <= n;++i) {
		if (ETF[i] == i)
		{
			for (int j = i;j <= n;j += i)
			{
				ETF[j] /= i;
				ETF[j] *= (i - 1);
			}
		}
	}
	cout << ETF[query] << endl;
}
vector<int> simpleSeive(int limit)
{
	vector<bool> seive(limit + 1, true);
	seive[0] = seive[1] = false;
	for (int i = 2;i * i <= limit;++i)
	{
		if (seive[i])
		{
			for (int j = i * i;j <= limit;j += i)
			{
				seive[j] = false;
			}
		}
	}
	vector<int> primes;
	for (int i = 2;i <= limit;++i)
	{
		if (seive[i])
			primes.push_back(i);
	}
	return primes;
}
vector<ll> segmentedSeive(ll L, ll R)
{
	int limit = sqrt(R) + 1;
	vector<int> primes = simpleSeive(limit);
	vector<int> segPrime(R - L + 1, true);
	for (const int& prime : primes)
	{
		ll start = max(prime * 1LL * prime, ((L + prime - 1) / prime) * 1LL * prime);
		for (ll j = start;j <= R;j += prime)
			segPrime[j - L] = false;
	}
	vector<ll> res;
	for (ll i = L;i <= R;++i)
	{
		if (i > 1 && segPrime[i - L])
			res.push_back(i);
	}
	return res;
}
ll ModularMultiplicativeInverse(ll num, ll MOd)
{
	if (isPrime(MOd))
		return binomialCoefficient_mod(num, MOd - 2, MOd);
}

int main()
{

}

