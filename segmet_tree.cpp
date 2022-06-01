


// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>
  #include<bits/stdc++.h>
  
using namespace std;


const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0;
}



//rabin -karp algorithm for finding size of k as substring in original string 
string isPossible(string s, int k, int n){
        unordered_map<int, vector<int>> mp;
        
        long long d=26;
        long long q=1000000007;
        long long h=1;
        long long t=0;
        for(int i=1;i<k;i++){
            h=(h*d)%q;
        }
        
        for(int i=0;i<k;i++){
            t=(t*d+s[i])%q;
        }
        
        
        for(int i=0;i<=(n-k);i++){
            if(mp.find(t)!=mp.end()){
                for(auto val:mp[t]){
                    string str1=s.substr(val,k);
                    string str2=s.substr(i,k);
                    if(str1==str2){
                        return str1;
                    }
                }
            }
            
            mp[t].push_back(i);
            t=(d*(t-h*s[i])+s[i+k])%q;
            if(t<0){
                t=t+q;
            }
        }
        
        
        
        return "";
    }







