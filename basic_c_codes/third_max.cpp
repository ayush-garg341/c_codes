#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first_max = -2147483648;
        int second_max = -2147483648;
        int third_max = -2147483648;
	bool third_max_present = false;
        int array_size = nums.size();
        for(int i = 0; i < array_size ; i++){
	  if(nums[i]==-2147483648){
	    third_max_present = true;
	  }
          if(nums[i] > first_max){
	    cout << "first max ====" <<nums[i] << "\n";
	    third_max = second_max;
	    second_max = first_max;
	    first_max = nums[i];
	  }
            else if(nums[i] < first_max && nums[i] > second_max){
	      cout << "second max ====="  << nums[i] << "\n";
	      third_max = second_max;
	      second_max = nums[i];
            }
            else if(nums[i] < first_max && nums[i] < second_max && nums[i] > third_max){
	      cout << "third max ======= " << nums[i] << "\n";
                third_max =  nums[i];
            }
            
        }

	cout << first_max << " " << second_max << " " << third_max << "\n";
	
        if((first_max!=second_max && second_max!=third_max && first_max!=third_max)){
	  if(third_max_present && third_max == -2147483648){
	    return third_max;
	  }
	  else if(third_max==-2147483648){
	    return first_max;
	  }
            return third_max;
        }
        return first_max;
    }
};


int main(){
  Solution soln;
  vector<int> nums={1, 2, 1};
  soln.thirdMax(nums);
  return 0;
}
