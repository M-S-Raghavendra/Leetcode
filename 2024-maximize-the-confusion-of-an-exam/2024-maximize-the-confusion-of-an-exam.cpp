class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0, j;
        int n = answerKey.size();
        int cnt = k;
        
        for(j=0;j<n;j++)
        {
            if(answerKey[j] == 'F')
                cnt--;
            if(cnt < 0 and answerKey[i++] == 'F')
                cnt++;
        }
        
        int ans = j-i;
        
        i = 0;
        cnt = k;
        
        for(j=0;j<n;j++)
        {
            if(answerKey[j] == 'T')
                cnt--;
            if(cnt < 0 and answerKey[i++] == 'T')
                cnt++;
        }
        
        ans = max(ans, j-i);
        return ans;
    }
};