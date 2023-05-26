//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  private:
  long long floorBSearch(vector<long long> &v, long long x, long long n)
  {
      long long s = 0, e = n-1;
      long long ans = -1;
      
      while(s <= e)
      {
          int m = s + (e-s)/2;
          if(x == v[m])
            return m;
          else if(x < v[m])
              e = m-1;
          else
          {
            ans = m;
            s =  m+1;
          }
      }
      return ans;
  }
  
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        long long ans = floorBSearch(v,x,n);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends