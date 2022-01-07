class Solution {
public:
    int ans = 0;
    void back(vector<string>& words, vector<int>& score, vector<int> &freq, vector<int> &vis, int pos, int sc) {
        for (int i = 0; i < 26; ++i) {
            if (vis[i] > freq[i]) return;
        }
        ans = max(sc, ans);
        for (int i = pos; i < words.size(); ++i) {
            for (auto & c : words[i]) {
                vis[c-'a']++;
                sc += score[c-'a'];
            }
            back(words, score, freq, vis, i+1, sc);
            for (auto & c : words[i]) {
                vis[c-'a']--;
                sc -= score[c-'a'];
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0), vis(26, 0);
        for (auto & c : letters) {
            freq[c-'a']++;
        }
        back(words, score, freq, vis, 0, 0);
        return ans;
    }
};