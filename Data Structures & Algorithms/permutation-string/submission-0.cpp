class Solution {
public:
    bool areVectorsEqual(vector<int>&a, vector<int> &b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        //if length of  s1 bigger no way it is true
        if(s1.length()>s2.length()){
            return false;
        }

        //create vectors to map frequencies and match frequencies in particular window
       vector<int> s1Count(26,0);
       vector<int> s2Count(26,0);

        for(int i=0;i<s1.length();i++){
            s1Count[s1[i]-'a']++;
        }
       
        int i=0,j=0;
        while(j<s2.length()){
            
            s2Count[s2[j] - 'a']++;

            //if the window is reached and it matches
            if(j-i+1== s1.length()){
                if(areVectorsEqual(s1Count,s2Count)){
                    return true;
                }
            }

            if(j-i+1<s1.length()){
                j++;
            }

            else{
                s2Count[s2[i]- 'a']--;
                i++;
                j++;
            }

        }
        return false;
    }
    
};
