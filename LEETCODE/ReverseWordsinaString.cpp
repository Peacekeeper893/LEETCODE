#include<bits/stdc++.h>
using namespace std;


int main()
{
    

    return 0;
}

class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        string curr_word="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' '){
                if(curr_word.size() != 0)
                    words.push_back(curr_word);
                curr_word="";
                continue;
            }
            else
            {
                curr_word.push_back(s[i]);
            }
                
        }

        if(curr_word.size() != 0)
                    words.push_back(curr_word);

        for(auto x : words)
            cout<<x<<" ";

        string res = "";
        reverse(words.begin() , words.end());

        for(auto x : words)
        {
            res+=x;
            res.push_back(' ');
        }

        res.pop_back();

        return res;
        
    }
};