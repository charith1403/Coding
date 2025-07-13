class Solution {
public:
    bool searchSubs(int index, const string& word, unordered_set<string>& st, int count, unordered_map<int, bool>& memo) {
        if (index == word.size()) {
            return count >= 2;
        }
        if (memo.count(index)) return memo[index];

        string temp = "";
        for (int i = index; i < word.size(); i++) {
            temp += word[i];
            if (st.find(temp) != st.end()) {
                if (searchSubs(i + 1, word, st, count + 1, memo)) {
                    return memo[index] = true;
                }
            }
        }
        return memo[index] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> st(words.begin(), words.end());

        for (const string& word : words) {
            st.erase(word);
            unordered_map<int, bool> memo;
            if (!word.empty() && searchSubs(0, word, st, 0, memo)) {
                ans.push_back(word);
            }
            st.insert(word);
        }
        return ans;
    }
};
