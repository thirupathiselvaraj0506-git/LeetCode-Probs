class Solution {
private:
    vector<string> seperate(string& s){
        stringstream ss(s);
        string word;
        vector<string>res;
        while(ss>>word){
            res.push_back(word);
        }
        return res;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>sen1=seperate(sentence1);
        vector<string>sen2=seperate(sentence2);
        if(sen1.size()<sen2.size()) swap(sen1,sen2);
        int st=0,end=0;
        int size1=sen1.size(),size2=sen2.size();
        while(st<size2 && sen1[st]==sen2[st]) st++;
        while(end<size2 && sen1[size1-end-1]==sen2[size2-end-1]) end++;
        return st+end>=size2;
    }
};