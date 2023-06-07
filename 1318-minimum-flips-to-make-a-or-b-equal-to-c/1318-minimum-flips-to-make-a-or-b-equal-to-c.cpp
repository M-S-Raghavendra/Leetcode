class Solution {
public:
    int minFlips(int a, int b, int c) {
        int seta = __builtin_popcount(a);
        int setb = __builtin_popcount(b);
        int flips = 0;
                
        for(int i=0;i<32;i++)
        {
            int cbit = c & (1<<i);
            int bbit = b & (1<<i);
            int abit = a & (1<<i);
            // cout<<abit<<" "<<bbit<<" "<<cbit<<endl;
            
            if(cbit) {
                if(abit == 0 and bbit == 0)
                {
                    if(seta < setb)
                    {
                        seta++;
                    }
                    else
                    {
                        setb++;
                    }
                    flips++;
                }
            }
            else {
                if(abit)
                {
                    seta--;
                    flips++;
                }
                if(bbit)
                {
                    setb--;
                    flips++;
                }
            }
        }
        
        return flips;
    }
};