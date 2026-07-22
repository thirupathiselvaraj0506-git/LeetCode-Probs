class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>mpp;
        for(int a:nums1){
            for(int b:nums2){
                mpp[a+b]++;
            }
        }
        int cnt=0;
        for(int c:nums3){                                               //a+b+c+d=0;
            for(int d:nums4){                                           //a+b=-(c+d);
                if(mpp.find(-(c+d))!=mpp.end()){
                    cnt+=mpp[-(c+d)];
                }
            }
        }
        return cnt;
    }
};