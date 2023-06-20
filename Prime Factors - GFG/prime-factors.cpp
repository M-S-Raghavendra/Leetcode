//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    private:
        vector<int> seive;
        
        void s() {
            for(int i=2;i<seive.size();i++)
            {
                if(seive[i] == 1) {
                    for(long long j=i*i;j<seive.size();j+=i)
                    {
                        seive[j] = 0;
                    }
                }
            }
        }
        
        bool isPrime(int d)
        {
            return seive[d];
        }
        
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int> ans;
	    int div = 2;
	    seive.resize(N+1,1);
	    s();
	    
	    for(int i=2;i<=N;i++)
	    {
	        if(N % i == 0 and isPrime(i))
	            ans.push_back(i);
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends