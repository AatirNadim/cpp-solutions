// problem link --> https://practice.geeksforgeeks.org/problems/power-set4302/1#

class Solution{
	public:
	   struct TrieNode {
	       bool isEnd = 0;
	       int times = 0;
	       vector<TrieNode*> edges;
	       TrieNode() {
	           edges = vector<TrieNode*> (26);
	           times = 1;
	       }
	   };
	    TrieNode* root; vector<string> res;
	    void populate(string& s, int idx, int& n, TrieNode* currnode) {
	        if(idx == n) {
	            currnode->isEnd = 1;
	            return;
	        }
	        populate(s, idx + 1, n, currnode);
	        if(currnode->edges[s[idx] - 'a'])
	            currnode->edges[s[idx] - 'a']->times++;
	        else currnode->edges[s[idx] - 'a'] = new TrieNode();
	        populate(s, idx + 1, n, currnode->edges[s[idx] - 'a']);
	    }
	    
	    void traverse(TrieNode* currnode, string& temp) {
	        if(currnode->isEnd and temp.size()) {
	            for(int i=0;i<currnode->times;i++)
	                res.push_back(temp);
	            
	        }
	        for(int i=0; i < 26;i++) {
	            if(currnode->edges[i]) {
	                temp.push_back((char)('a' + i));
	                traverse(currnode->edges[i], temp);
	                temp.pop_back();
	            }
	        }
	    }
	    vector<string> AllPossibleStrings(string s){
		    root = new TrieNode();
		    int n = s.size(), idx = 0; string temp = "";
		    populate(s, idx, n, root);
		    traverse(root, temp);
		    return res;
		}
		
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends