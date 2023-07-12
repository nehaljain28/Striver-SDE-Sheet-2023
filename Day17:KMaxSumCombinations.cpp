#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int C){
	// Write your code here.
	 

    vector<int>ans;

    // sort both arrays 

    sort(A.begin(), A.end());

    sort(B.begin(), B.end());

    // Store sum -> (i,j)

    priority_queue<pair<int, pair<int, int>>>pq; // (sum, (i,j))

    set<pair<int,int>>st;

    

    pq.push({A[n-1]+B[n-1],{n-1,n-1}});

    st.insert({n-1,n-1}); // which pair of indices we have used already, to keep a track of them

    

    while(C--)

    {

        auto p = pq.top();pq.pop();

        int sum = p.first; 

        int i = p.second.first;

        int j = p.second.second;

        // max sum -> answer

        ans.push_back(sum);

        

        // Next two sum combinations (i-1,j), (i,j-1)

        sum = A[i-1] + B[j];

        if(st.find({i-1,j})==st.end()){

            pq.push({sum, {i-1,j}});

            st.insert({i-1,j});

        }

        sum = A[i] + B[j-1];

        if(st.find({i,j-1})==st.end()){

            pq.push({sum, {i,j-1}});

            st.insert({i,j-1});

        }

    }

    return ans;
}
