class Solution {
public:
    int MOD = 1000000007;
    long long k = 31;

    string pos(string s, int wid) {
        // First window hash and power precompute
        long long fHash = 0;
        long long power = 1;
        for (int i = 0; i < wid; i++) {
            fHash = (fHash * k + s[i] - 'a') % MOD;
            if (i < wid - 1) {
                power = (power * k) % MOD;
            }
        }

        // Set to store hashes and their starting positions
        unordered_map<long long, vector<int>> hash_positions;
        hash_positions[fHash].push_back(0);

        // Rolling hash
        for (int i = 1; i <= s.size() - wid; i++) {
            // Previous character remove
            fHash = (fHash - (s[i - 1] - 'a') * power % MOD + MOD) % MOD;
            // Next character add
            fHash = (fHash * k + s[i + wid - 1] - 'a') % MOD;

            // Check if the hash already exists
            if (hash_positions.find(fHash) != hash_positions.end()) {
                // Verify by comparing the substrings
                for (int start_idx : hash_positions[fHash]) {
                    if (s.substr(start_idx, wid) == s.substr(i, wid)) {
                        return s.substr(i, wid);
                    }
                }
            }
            hash_positions[fHash].push_back(i);
        }
        return "";
    }

    string longestDupSubstring(string s) {
        int lo = 1, hi = s.size() - 1;
        string res = "";
        while (hi >= lo) {
            int mid = (hi + lo) / 2;
            string temp = pos(s, mid);
            if (!temp.empty()) {
                if (temp.size() > res.size()) {
                    res = temp;
                }
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }
};
