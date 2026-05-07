class Solution {
public:
    string minWindow(string s, string t) {
        if(s==t){
            return t;
        }
        //take the freqmap of t input
        unordered_map<char,int> m;
        for(int i=0;i< t.size();i++){
            m[t[i]]++;
        }

        int i=0,j=0; //init two pointers
        int counter = t.size();
        int minStart=0;
        int minLength= INT_MAX;

        while(j<s.size()){  //till end of main string
            if(m[s[j]]>0){//current letter present in both t and s
                counter--;
            }
            
            m[s[j]]--;
            j++;

            //we have reached the pattern fully
            while(counter == 0){
                //check if it is shorter than prev min length
                    if(j-i<minLength){
                        minStart=i;
                        minLength=j-i;
                    }
                    //now do necessary stuff to move left counter
                    m[s[i]]++;
                    //positive msi means that it was present in t
                    if(m[s[i]] >0){
                        counter++;
                    }
                    i++;
            }

        }
        //if minlength exists return it or return blank
        if(minLength != INT_MAX){
            return s.substr(minStart,minLength);
        }
        return "";
        
    }
};
