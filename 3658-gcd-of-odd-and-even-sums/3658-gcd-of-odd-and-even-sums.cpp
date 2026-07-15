class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd=1,even=2;
        int oddsum=0,evensum=0;
        while(n>=1){
            oddsum+=(odd);
            evensum+=(even);
            odd+=2,even+=2;
            n--;
        }
        cout<<oddsum<<" "<<evensum;
        return gcd(oddsum,evensum);
    }
};