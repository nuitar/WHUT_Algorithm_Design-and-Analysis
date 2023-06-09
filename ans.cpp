#include <iostream>
#include <functional>
#include <vector>

class solution
{
public:
    void grayCode()
    {
        // 输入样例 
        int n, size;
        std::cin >> n;
        size = 1 << n;
        std::string str;
        std::vector<std::string> ans;
        for (int i = 0; i < n; i++)
            str += '0';
        std::function<void(bool)> f = [&](bool flag)
        {
            if (ans.size() == size)
                return;
            ans.push_back(str);
            int pos = flag == 0 ? n - 1 : str.rfind('1') - 1;
            str[pos] = str[pos] == '0' ? '1' : '0';
            f(!flag);
        };

        f(0);
        for (std::string code : ans)
            std::cout << code << std::endl;
    }

    void hireShip()
    {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> hireMoney(n, std::vector<int>(n + 1, 0));
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
                std::cin >> hireMoney[i][j];
        }

        std::vector<int> dp(n + 1, 0);
        dp = hireMoney[1]; // dp表示前i站到j站的最小花费
        for (int i = 2; i < n; i++)
        {
            for (int j = n; j > i; j--)
                dp[j] = std::min(dp[j], dp[j - 1] + hireMoney[i][j]);
        }
        std::cout << dp[n];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		int k1 = (n + m + 1) / 2, k2 = (n + m + 2) / 2;
		double ans = back(nums1, 0, n - 1, nums2, 0, m - 1, k1) + back(nums1, 0, n - 1, nums2, 0, m - 1, k2);
		return ans / 2;
	}
	int back(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
		int len1 = end1 - start1 + 1, len2 = end2 - start2 + 1;

		if (k == 1)
			return min(nums1[start1], nums2[start2]);

		if (len1 > len2)
			return back(nums2, start2, end2, nums1, start1, end1, k);
		if (len1 == 0)
			return nums2[start2 + k - 1];
		int i = start1 + min(len1, k / 2) - 1, j = start2 + min(len2, k / 2) - 1;
		if (nums1[i] > nums2[j])
			return back(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
		else
			return back(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
	}
    
	void maxK_multiple() {
		int n, k;
		string str;
		cin >> n >> k;
		cin >> str;
		vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));
		for (int i = 1; i <= n; i++)
			dp[i][1] = atoi(str.substr(0, i).c_str());

		//前i位分成k段
		for (int i = 1; i <= n; i++) {
			for (int j = 2; j <= k; j++) {
				int m = 0;
				for (int z = 0; z < i; z++) { //扫描前0 - i 位分成j-1段与n位数后i位的乘积最大值
					m = max(m, dp[z][j - 1] * atoi(str.substr(z, i - z).c_str()));
				}
				dp[i][j] = m;
			}
		}
		cout << dp[n][k];
	}
};

int main()
{
    solution s;
    s.hireShip();
}
