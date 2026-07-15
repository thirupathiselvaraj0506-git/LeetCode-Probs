class Solution {
public:
    void revWord(string& s,int st,int end){
        while(st<end){
            swap(s[st],s[end]);
            st++,end--;
        }
    }
    bool isVow(char ch){
        if(ch=='a'|| ch=='e'||ch=='i'||ch=='o'||ch=='u') return 1;
        return 0;
    }
    string reverseWords(string s) {
        int j=0,flg=0;
        int vowcnt=0;
        int wordvow=0;
        for(int i=0;i<s.size();i++){
            if(flg==0){
                if(s[i]==' ') {flg=1;j=i+1;continue;}
                if(isVow(s[i])) vowcnt++;
                continue;
            }
            if(s[i]!=' '){
                if(isVow(s[i])) wordvow++;
            }else if(s[i]==' '){
                if(wordvow==vowcnt){
                    revWord(s,j,i-1);
                }
                wordvow=0;
                j=i+1;
            }
        }
        if(wordvow==vowcnt){
            revWord(s,j,s.size()-1);
        }
        return s;
    }
};