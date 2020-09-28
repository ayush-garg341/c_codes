#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int count{0};
      for(int i{0}; i<nums.size(); i++){
	if(count!=0 &&  nums[i]!=nums[count-1]){
	  nums[count] = nums[i];
	  count += 1;
	}
	else if(count==0){
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
  soln.removeDuplicates(A, 2);
  return 0;
}
