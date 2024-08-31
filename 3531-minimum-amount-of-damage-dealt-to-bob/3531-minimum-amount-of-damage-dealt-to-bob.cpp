#include <vector>
#include <algorithm>

class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b, int power) {
        long long timeA = (a.second + power - 1) / power;
        long long timeB = (b.second + power - 1) / power;
        return a.first * timeB > b.first * timeA;
    }

    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int len = damage.size();
        vector<pair<int, int>> enemies(len);

        for (int i = 0; i < len; ++i) {
            enemies[i] = {damage[i], health[i]};
        }
        
        sort(enemies.begin(), enemies.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return comp(a, b, power);
        });

        long long ans = 0;
        long long curr = 0;

        for (const auto& enemy : enemies) {
            curr += enemy.first;
        }

        for (const auto& enemy : enemies) {
            int timeToKill = (enemy.second + power - 1) / power;
            ans += curr * timeToKill;
            curr -= enemy.first;
        }

        return ans;
    }
};
