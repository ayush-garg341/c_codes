#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> nums;
        for(int i{0}; i<A.size(); i++){
            if(A[i]%2==0){
	      nums.insert(nums.begin(), A[i]);
            }
            else{
	      nums.push_back(A[i]);
            }
        }

	for(int i{0}; i<A.size(); i++){
	  cout << nums[i] << "\n";
	}
        
        return nums;
    }
};

int main(){
  Solution soln;
  vector<int> nums={3,1,2,4};
  soln.sortArrayByParity(nums);
  return 0;
}
