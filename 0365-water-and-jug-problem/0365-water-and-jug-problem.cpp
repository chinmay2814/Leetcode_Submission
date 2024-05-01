class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target == 0) return true; // Target of 0 can always be achieved
        if (x + y < target) return false; // If the total capacity is less than the target, it's impossible

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push({0, 0});
        visited.insert({0, 0});

        while (!q.empty()) {
            auto [jug1, jug2] = q.front();
            q.pop();

            if (jug1 == target || jug2 == target || jug1 + jug2 == target) return true;

            // Try all possible operations
            vector<pair<int, int>> nextStates = {
                {x, jug2}, // Fill jug 1
                {jug1, y}, // Fill jug 2
                {0, jug2}, // Empty jug 1
                {jug1, 0}, // Empty jug 2
                {min(x, jug1 + jug2), max(0, jug1 + jug2 - x)}, // Pour from jug 1 to jug 2
                {max(0, jug1 + jug2 - y), min(y, jug1 + jug2)}  // Pour from jug 2 to jug 1
            };

            for (auto nextState : nextStates) {
                if (!visited.count(nextState)) {
                    q.push(nextState);
                    visited.insert(nextState);
                }
            }
        }

        return false;
    }
};
