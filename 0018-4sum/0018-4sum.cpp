#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int N=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<N-3;i++){
            for(int j=i+1;j<N-2;j++){
                ll newtarget = (ll)target-(ll)nums[i]-(ll)nums[j];
                int lt=j+1,rt=N-1;
                while(lt<rt){
                    int sum=nums[lt]+nums[rt];
                    if(sum<newtarget){
                        lt++;
                    }else if(sum>newtarget){
                        rt--;
                    }else{                                      //equal
                        ans.push_back({nums[i],nums[j],nums[lt],nums[rt]});
                        int ltind=lt,rtind=rt;
                        lt++,rt--;
                        while(lt<rt && nums[lt]==nums[ltind]) lt++;
                        while(rt>lt && nums[rt]==nums[rtind]) rt--;
                    }
                }
                while(j+1<N && nums[j]==nums[j+1]) j++;
            }
            while(i+1<N && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};