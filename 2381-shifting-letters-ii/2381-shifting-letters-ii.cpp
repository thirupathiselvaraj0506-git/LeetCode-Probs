class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int N=s.size();
        vector<int>toShift(N+1,0);
        for(int i=0;i<shifts.size();i++){
            int st=shifts[i][0];
            int end=shifts[i][1];
            if(shifts[i][2]==0){            //for backward dir
                toShift[st]-=1;
                toShift[end+1]+=1;
            }else{                          //for forward dir
                toShift[st]+=1;
                toShift[end+1]-=1;
            }
        }
        int tot=0;
        for(int i=0;i<N+1;i++){             //prefix sum
            tot+=toShift[i];
            toShift[i]=tot;
        }
        for(int i=0;i<N;i++){
            int sum=((toShift[i]%26)+26) % 26;
            s[i]=(s[i]-'a'+sum)%26 +'a';
        }
        return s;
    }
};