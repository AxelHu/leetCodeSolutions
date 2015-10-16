class Solution {
public:
    // modification from Manacher's algorithm
    // #....#*#*#*#a#b#c#.....#
    // center at any pos, should cover more '*' to make 
    // resulting string shorter
    // so on testing the original string, the palindrome length test
    // center at each point should reach at least left boundary
    // to be considered by the result
    string shortestPalindrome(string s) {
        string sp;
        for(int i = 0; i < s.size(); i++)
            sp += "#" + s.substr(i, 1);
        sp.push_back('#');
        
        
        vector<int> palCount(sp.size(), 0);
        int centerPos = 0;
        int leftPos = 0;
        int rightPos = 0;
        int maxLen = 0;
        int resCenter = 0;
        
        for(int i = 1; i < sp.size()-1; i++)
        {
            int ip = 2*centerPos-i;
            palCount[i]=(rightPos>i)?min(rightPos-i, palCount[ip]):0;
            while(i-1-palCount[i]>=0 && i+1+palCount[i]<=sp.size()-1 && sp[i+1+palCount[i]] == sp[i-1-palCount[i]])
                palCount[i]++;
            if(i+palCount[i] > rightPos)
            {
                centerPos = i;
                rightPos = i+palCount[i];
            }
            if(palCount[i]-i >= 0)
            {
                maxLen = palCount[i];
                resCenter = i;
            }   
        }
        //cout<<resCenter<<"--"<<maxLen<<endl;
        string strToAdd = s.substr((resCenter));
        std::reverse(strToAdd.begin(), strToAdd.end());
        return strToAdd+s;
    }
};