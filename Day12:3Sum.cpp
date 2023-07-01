#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>> res; 
        sort(arr.begin(), arr.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(arr.size())-2; i++) {
            
            if (i == 0 || (i > 0 && arr[i] != arr[i-1])) {
                
                int lo = i+1, hi = (int)(arr.size())-1, sum = K - arr[i];
                
                while (lo < hi) {
                    if (arr[lo] + arr[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(arr[i]); 
                        temp.push_back(arr[lo]); 
                        temp.push_back(arr[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && arr[lo] == arr[lo+1]) lo++;
                        while (lo < hi && arr[hi] == arr[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (arr[lo] + arr[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
}
