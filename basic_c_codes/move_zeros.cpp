#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int count{0};
      for(int i{0}; i<nums.size(); i++){
	if(nums[i]!=0){
	  nums[count]=nums[i];
	  count++;
	} 
      }

      for(int j{count}; j<nums.size(); j++){
	nums[j]=0;
      }
    }
};


int main(){
  Solution soln;
  vector<int> nums={0,1,0,3,12};
  soln.moveZeroes(nums);
  return 0;
}
