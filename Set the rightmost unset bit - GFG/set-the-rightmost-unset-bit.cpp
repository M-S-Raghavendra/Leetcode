//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        int index = -1;
        for(int i=0;i<32;i++)
        {
            if((N & (1<<i)) == 0)
            {
                N = N | (1<<i);
                index = i;
                break;
            }
        }
        
        bool done = false;
        
        for(int i=index+1;i<32;i++)
        {
            if(N & (1<<i))
            {
                done = true;
                break;
            }
        }
        
        if(!done)
            N = N & ~(1<<index);
        
        return N;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends