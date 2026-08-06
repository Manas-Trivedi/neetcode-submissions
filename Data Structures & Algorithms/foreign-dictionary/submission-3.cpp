class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<bool> present(26, false);
        vector<int> indegree(26,  0);
        unordered_map<char, unordered_set<char>> preceds;
        for(int j = 0; j < words[0].size(); j++) present[words[0][j] - 'a'] = true;
        for(int i = 1; i < words.size(); i++) {
            bool flag = false;
            for(int j = 0; j < words[i].size(); j++) {
                if(!flag && (words[i - 1].size() <= j || words[i][j] != words[i - 1][j])) {
                    flag = true;
                    if(words[i - 1].size() <= j) continue;
                    if(!preceds[words[i - 1][j]].count(words[i][j])) {
                        preceds[words[i - 1][j]].emplace(words[i][j]);
                        indegree[words[i][j] - 'a']++;
                    }
                }
                present[words[i][j] - 'a'] = true;
            }
            if(!flag && words[i - 1].size() > words[i].size()) return "";
        }
        queue<char> q;
        for(int i = 0; i < 26; i++) {
            if(present[i] && indegree[i] == 0) {
                q.push(i + 'a');
                present[i] = false;
            }
        }
        string order = "";
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            order.push_back(c);
            for(const auto &ch: preceds[c]) {
                indegree[ch - 'a']--;
                if(!indegree[ch - 'a']) {
                    q.push(ch);
                    present[ch - 'a'] = false;
                }
            }
        }
        for(int i = 0; i < 26; i++) if(present[i]) return "";
        return order;
    }
};
