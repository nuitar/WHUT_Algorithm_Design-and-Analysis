#include <iostream>
#include <functional>
#include <vector>

class solution
{
public:
    void grayCode(){
        //输入样例
        int n, size;
        std::cin >> n;
        size = 1 << n;
        std::string str;
        std::vector<std::string> ans;
        for (int i = 0; i < n;i++)
            str += '0';
        std::function<void(bool)> f = [&](bool flag)
        {
            if(ans.size() == size)
                return;
            ans.push_back(str);
            int pos = flag == 0? n - 1:str.rfind('1') - 1;
            str[pos] = str[pos] == '0' ? '1' : '0';
            f(!flag);
        };

        f(0);
        for(std::string code:ans)
            std::cout << code <<std::endl;
    }

    void hireShip(){
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> hireMoney(n, std::vector<int>(n + 1, 0));
        for (int i = 1; i < n;i++){
            for (int j = i + 1; j <= n;j++)
                std::cin >> hireMoney[i][j];
        }

        std::vector<int> dp(n + 1,0);
        dp = hireMoney[1];
        for (int i = 2; i < n;i++){
            for (int j = n; j > i;j--)
                dp[j] = std::min(dp[j], dp[j - 1] + hireMoney[i][j]);
        }
        std::cout << dp[n];
    }
};

int main(){
    solution s;
    s.hireShip();
}