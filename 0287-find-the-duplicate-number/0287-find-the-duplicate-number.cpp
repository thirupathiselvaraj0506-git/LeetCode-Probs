class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lt=1;
        int rt=nums.size()-1;
        while(lt<rt){                          //binary search 1 to N
            int cnt=0;
            int mid=lt+(rt-lt)/2;
            for(int x:nums){
                if(x<=mid){
                    cnt++;
                }
            }
            if(cnt>mid){
                rt=mid;
            }else{
                lt=mid+1;
            }
        }
        return lt;
    }
};