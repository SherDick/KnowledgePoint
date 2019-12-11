# 查找数组中前k个最大值
```
vector<int> GetMaxNumbers(vector<int> input, int k) {
	if (input.empty() || k <= 0 || input.size() < k) return vector<int>();
	multiset<int, less<int> > leastNumber;
	multiset<int, less<int> >::iterator it;
	for (int i = 0; i < input.size(); i++) {
		if (leastNumber.size() < k) {
			leastNumber.insert(input[i]);
		}
		else {
			it = leastNumber.begin();
			if (input[i] > *it) {
				leastNumber.erase(*it);
				leastNumber.insert(input[i]);
			}
		}
	}
	return vector<int>(leastNumber.begin(), leastNumber.end());
}
```