class Solution {
private:
    int GCD(int a,int b){
        if(b==0) return a;
        return GCD(b,a%b);
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n);
        int maxel=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxel=max(maxel,nums[i]);
            pref[i]=GCD(nums[i],maxel);
        }
        sort(pref.begin(),pref.end());
        for(auto x:pref){
            cout<<x<<" ";
        }
        long long sum=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            sum+=GCD(pref[i],pref[j]);
            i++,j--;
        }
        return sum;
    }
};