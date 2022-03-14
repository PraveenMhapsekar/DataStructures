#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>>
groupAnagrams(vector<string> &strs) {
	unordered_map<string,vector<string>>mp;
	vector<vector<string>>ans;
	for (int i=0;i<strs.size();i++) {
		string ff=strs[i];
		sort(ff.begin(),ff.end());
		mp[ff].push_back(strs[i]);
	}
	unordered_map<string,vector<string>>::iterator itr;
	for (itr=mp.begin();itr!=mp.end();itr++) {
		 ans.push_back(itr->second);
	}
	return ans;
}

int 
main() {
  vector<string>  strs = {"eat","tea","tan","ate","nat","bat"} ;
  vector<vector<string>> ans;
  ans = groupAnagrams(strs);
  for (int i = 0; i < ans.size(); i++) {
     vector<string> tmp = ans[i];
     for (int j = 0; j < tmp.size(); j++) {
        string mystr = tmp[j];
        cout << mystr << " " ;
     }
     cout << endl;
  }
  return 0;
}
