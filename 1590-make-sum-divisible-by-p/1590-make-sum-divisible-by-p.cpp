class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int>mpp;
        long long tot=accumulate(nums.begin(),nums.end(),0LL);
        int N=nums.size();
        if(tot<p) return -1;
        if(tot%p==0) return 0;
        int rem=tot%p;
        int pref=0,minlen=N;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            pref=(pref+nums[i])%p;
            int diff=pref-rem;
            if(diff<0) diff+=p;
            if(mpp.find(diff)!=mpp.end()){
                minlen=min(minlen,i-mpp[diff]);
            }
            mpp[pref]=i;
        }
        return minlen==N ? -1 :minlen ;
    }
};