class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        // int N=shifts.size();
        // vector<int>suff(N);
        // suff[N-1]=shifts[N-1];
        // for(int i=N-2;i>=0;i--){
        //     suff[i]=suff[i+1]+shifts[i];
        // }
        long long sum=0;
        for(int i=shifts.size()-1;i>=0;i--){
            sum=(sum+shifts[i])%26;
            s[i]=((s[i]-'a'+sum)%26) +'a';
            // cout<<s[i]<<" ";
        }
        return s;
    }
};