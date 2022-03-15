/*
Algorithm
If the cumulative sum(represented by sum[i]sum[i] for sum up to ith index) up to two indices is the same, the sum of the elements lying in between those indices is zero. 
Extending the same thought further, if the cumulative sum up to two indices, say i and j is at a difference of k
 i.e. if sum[i] - sum[j] = ksum[i] − sum[j] = k, the sum of elements lying between indices i and j is k.

Based on these thoughts, we make use of a hashmap which is used to store the cumulative sum up to all the indices possible along with the number of times the same sum occurs. We store the data in the form: (sum_i, no. of occurances of sum_i)

We traverse over the array nums and keep on finding the cumulative sum.
Every time we encounter a new sum, we make a new entry in the hashmap corresponding to that sum. 
If the same sum occurs again, we increment the count corresponding to that sum in the hashmap. 
Further, for every sum encountered, we also determine the number of times the sum == sum-k has occurred already, since it will determine the number of times a subarray with sum k has occurred up to the current index. We increment the count by the same amount.

After the comaplete array has been traversed, the count gives the required result.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int 
subarraySum(vector<int> &nums, int k) {
	int count = 0;
	int sum = 0;
	unordered_map<int,int> map;

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum == k) {
			count++;
		}

		if (map.find(sum-k) != mp.end()) {
			count += map[sum-k]; 
			// here in count we add the frequency of the element that is
			// sum-k=x(suppose)...so that it will add all the frequency of x to the count..
		}
		map[sum]++;
	}

	return count;
}

#if 0
int subarraySum(vector<int> &nums, int k) {
	int count = 0, sum = 0;
  int sumCnt = 1;
	unordered_map <int, int> map;
	map.insert({ sum, sumCnt });  /// init (0, 1)
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		int diff = sum - k;
    // find comaplementary sum in the map
		if (map.find(diff) != map.end()) {
			count += map.at(diff);
		}

		if (map.find(sum) != map.end()) {
      // If present, increament by 1
			sumCnt = map.at(sum);
	    sumCnt = sumCnt + 1;
		} else {
      // new insertion, set to 1
			sumCnt = 1;
		}

		map.insert({ sum, sumCnt});
	}

	return count;
}
#endif

int
main() {

 vector<int> n = {3, 4, 7, 2, -3, 1, 4, 2};
 int k = 7;

 int ans = subarraySum(n, k);

  cout << "ans is " << ans << " " << endl;

}

