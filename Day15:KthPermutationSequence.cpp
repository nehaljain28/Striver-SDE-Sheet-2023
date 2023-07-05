//all combinations
 #include<algorithm>
 void permutationHelper(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string kthPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }



//optimal
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>num;
        int fact=1;
        for(int i=1;i<n;i++){
            num.push_back(i);
            fact*=i;
        }
        string ans="";
        num.push_back(n);
        k-=1;
        while(true){
            ans+=to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0)break;
            k%=fact;
            fact/=num.size();
        }
        return ans;
    }
};
