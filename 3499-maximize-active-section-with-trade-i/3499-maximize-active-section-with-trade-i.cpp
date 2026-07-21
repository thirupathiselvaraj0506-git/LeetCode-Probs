class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int i=0,prevzc=0,currzc=0,max2zc=0,onecnt=0;
        int N=s.size();
        while(i<N && s[i]=='1'){
            onecnt++; i++;
        }
        while(i<N && s[i]=='0'){
            prevzc++; i++;
        }
        while(i<N){
            while(i<N && s[i]=='1'){
                onecnt++; i++;
            }
            if(i==N) break;
            while(i<N && s[i]=='0'){
                currzc++; i++;
            }
            max2zc=max(max2zc,prevzc+currzc);
            prevzc=currzc;
            currzc=0;
        }
        return max2zc+onecnt;
    }
};