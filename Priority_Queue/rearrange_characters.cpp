/*
    problem link --> https://www.geeksforgeeks.org/problems/rearrange-characters4649/1
*/


class Solution
{
    public:
    
    // custom class to organize the characters based on their frequency
    class CustomNode {
        public:
        char val;
        int freq;
        
        CustomNode(char val, int freq) {
            this->val = val;
            this->freq = freq;
        }
        
        bool operator < (const CustomNode& otherNode) const {
            return freq < otherNode.freq;
        }
    };
    
    string rearrangeString(string str)
    {
        //code here
        priority_queue<CustomNode> pq;
        vector<int> hash(26);
        for(char& c: str) hash[c - 'a']++;
        for(int i=0;i<26;i++) {
            if(!hash[i]) continue;
            pq.push(CustomNode((char)('a' + i), hash[i]));
        }
        char prev = '#';
        string res = "";

        // always take the character with the maximum remaining frequency, which is not matching the last character, if possible
        while(pq.size()) {
            CustomNode currnode = pq.top(); pq.pop();
            if(currnode.val == prev) {
                if(!pq.size()) return "-1";
                auto nextNode = pq.top(); pq.pop();
                res.push_back(nextNode.val);
                nextNode.freq--;
                if(nextNode.freq) pq.push(nextNode);
                prev = nextNode.val;
            } else {
                res.push_back(currnode.val);
                currnode.freq--;
                prev = currnode.val;
            }
            if(currnode.freq) pq.push(currnode);
        }
        return res;
    }
    
};