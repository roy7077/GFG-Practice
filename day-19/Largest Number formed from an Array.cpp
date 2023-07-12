class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	static bool cmp(string a,string b)
	{
	    return (a+b)>(b+a);
	}
	string printLargest(vector<string> &arr) {
	    
	    sort(arr.begin(),arr.end(),cmp);
	    string ans="";
	    
	    for(auto it:arr)
	    ans+=it;
	    
	    return ans;
	}
};