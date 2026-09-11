class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mpp;
        for(int i=0;i<26;i++){
            mpp[order[i]]=i;
        }
        int n=words.size();
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(),s2.size());
            int j=0;
            int flag=1;
            while(j<len){
                if(s1[j]!=s2[j]){
                    flag=0;
                    if(mpp[s1[j]]>mpp[s2[j]]){
                        return false;
                    }
                    else break;
                }
                j++;
            }
            if(flag==1){
                if(s1.size()>s2.size())return false;
            }
        }
        return true;
    }
};