class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> indegree(26, 0);
        vector<vector<char>> preceds(26);
        vector<bool> present(26, false);

        for(auto &word : words)
            for(char c : word)
                present[c - 'a'] = true;

        for(int i = 1; i < words.size(); i++) {
            bool flag = false;
            for(int j = 0; j < min(words[i].size(), words[i - 1].size()); j++) {
                char c1 = words[i][j], c2 = words[i - 1][j];
                if(j < min(words[i].size(), words[i - 1].size()) && c1 != c2 && !flag) {
                    indegree[c2 - 'a']++;
                    preceds[c1 - 'a'].push_back(c2);
                    flag = true;
                }
            }
            if(!flag && words[i - 1].size() > words[i].size())
                return "";
        }
        string res = "";
        queue<int> q;
        for(int i = 0; i < 26; i++) {
            if(indegree[i] == 0 && present[i]) {
                q.push(i);
                res += i + 'a';
                present[i] = false;
            }
        }
        while(!q.empty()) {
            char c = q.front() + 'a';
            q.pop();
            for(int i = 0; i < preceds[c - 'a'].size(); i++) {
                char newChar = preceds[c - 'a'][i];
                indegree[newChar - 'a']--;
                if(indegree[newChar - 'a'] == 0 && present[newChar - 'a']) {
                    res += newChar;
                    q.push(newChar - 'a');
                    present[newChar - 'a'] = false;
                }
            }
        }
        for(int i = 0; i < 26; i++) {
            if(indegree[i] != 0) return "";
        }
        for(int i = 0; i < 26; i++) {
            if(present[i]) res += i + 'a';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
