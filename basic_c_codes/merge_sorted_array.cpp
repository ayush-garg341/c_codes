#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i{m-1};
        int j{n-1};
        int k{m+n-1};
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            else if(nums2[j]>nums1[i]){
                nums1[k] = nums2[j];
                j--;
                k--;
            }
            else{
                nums1[k] = nums1[i];
                k--;
                i--;
                
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            
        }
        if(j>=0){
            while(j>=0){
                nums1[k]=nums2[j];
                k--;
                j--;
            }
            
        }
    }
};


int main(){
  Solution soln;
  vector<int> A={2,4,8,9,0,0,0};
  vector<int> B={1,2,3};
  int m{4};
  int n{3};
  soln.merge(A, m, B, n);
  return 0;
}
