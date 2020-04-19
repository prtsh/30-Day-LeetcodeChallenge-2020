/*
    Given an array of strings, group anagrams together.
    
    Example:
    
    Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
    Output:
    [
      ["ate","eat","tea"],
      ["nat","tan"],
      ["bat"]
    ]
    Note:
    
    All inputs will be in lowercase.
    The order of your output does not matter.
    
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(auto s: strs){
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }
        
        vector<vector<string> > results;
        for(auto kv: map)
            results.push_back(kv.second);
        
        return results;
}
