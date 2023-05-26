class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        string join = s + s;
        
        if(join.find(goal) != string::npos)
            return true;
        else return false;
    }
};