#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int count{0};
      for(int i{0}; i<nums.size(); i++){
	if(nums[i]!=val){
	  nums[count] = nums[i];
	  count += 1;
	}
      }

      return count;
    }
};


int main(){
  Solution soln;
  vector<int> A={0,1,2,2,3,0,4,2};
  soln.removeElement(A, 2);
  return 0;
}
