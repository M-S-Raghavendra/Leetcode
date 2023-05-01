class Solution {
public:
    double average(vector<int>& salary) {
        int mn = *min_element(salary.begin(),salary.end());
        int mx = *max_element(salary.begin(),salary.end());
        double sum = 0;
        
        for(auto x:salary)
        {
            if(x != mn and x != mx)
                sum += x;
        }
        
        return (1.0*sum)/(salary.size()-2);
    }
};