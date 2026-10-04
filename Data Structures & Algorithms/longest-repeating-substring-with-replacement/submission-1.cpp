class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        unordered_map<int,int>freq;
        int maxFreq=0;
        int maxLen=0;
        while(r<s.size()){
            freq[s[r]-'A']++;
            maxFreq=max(maxFreq,freq[s[r]-'A']);
            int len=r-l+1;
            int replacement=len-maxFreq;
            if(replacement<=k)
            maxLen=max(len,maxLen);
            else{
                while(r-l+1-maxFreq>k){
                    freq[s[l]-'A']--;
                    l++;
                }
                
            }
            r++;
        }
        return maxLen;
    }
};
