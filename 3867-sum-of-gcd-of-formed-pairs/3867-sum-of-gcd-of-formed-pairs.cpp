class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=INT_MIN;
        for(auto& x:nums){
            mx=max(mx,x);
            x=gcd(x,mx);
        }
        sort(nums.begin(),nums.end());
        long long sum=0;
        for(int i=0,j=nums.size()-1; i<j; i++,j--){
            sum+=gcd(nums[i],nums[j]);
        }
        return sum;
    }
};