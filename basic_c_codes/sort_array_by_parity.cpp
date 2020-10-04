#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& A) {
    int l{0};
    int r{static_cast <int>(A.size())-1};
    while(l<r){
      if(A[l]%2!=0){
	if(A[r]%2==0){
	  swap(A[l], A[r]);
	  r--;
	}
	else{
	  r--;
	}
      }
      else{
	l++;
      }
    }
    
    
    return A;
  }
};

int main(){
  Solution soln;
  vector<int> nums={3,1,2,4};
  soln.sortArrayByParity(nums);
  return 0;
}
