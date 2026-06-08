class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s: strs) {
            string prefix = to_string(s.size()) + '#';
            res += prefix + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        int len = -1, idx = 0;
        vector<string> strs;
        while(idx < s.size()) {
            string tmp = "";
            while(idx < s.size() && s[idx] != '#') {
                tmp += s[idx++];
            }
            len = stoi(tmp);
            idx++; // skip '#'
            string str = s.substr(idx, len);
            strs.push_back(str);
            idx += len;
        }
        return strs;
    }
};
