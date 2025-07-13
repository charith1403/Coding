class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        const int n = nums.size();
        std::vector<int> diff(n);
        int alreadyK = 0;                       // elements that are already == k

        for (int i = 0; i < n; ++i) {
            diff[i] = k - nums[i];
            if (diff[i] == 0) ++alreadyK;
        }

        int bestGain = 0;                       // best extra k-values we can create

        //  1 ≤ nums[i], k ≤ 50  →  diff in [-49, 49]
        for (int x = -49; x <= 49; ++x) {
            if (x == 0) continue;

            int head = -1, tail = 0;
            int cntX = 0, cnt0 = 0;            // counts of diff==x and diff==0 in window

            while (tail < n) {
                // grow the window while the score stays non-negative
                while (head + 1 < n) {
                    int w = 0;
                    if (diff[head + 1] == x)      w =  1;
                    else if (diff[head + 1] == 0) w = -1;

                    if (cntX - cnt0 + w < 0) break;
                    ++head;

                    if (diff[head] == x) ++cntX;
                    if (diff[head] == 0) ++cnt0;

                    bestGain = std::max(bestGain, cntX - cnt0);  // update here
                }

                if (tail > head) {                 // window empty → advance both ends
                    ++tail;
                    head = tail - 1;
                } else {                           // shrink from the left
                    if (diff[tail] == x) --cntX;
                    if (diff[tail] == 0) --cnt0;
                    ++tail;
                }
            }
        }
        return alreadyK + bestGain;
    }
};
