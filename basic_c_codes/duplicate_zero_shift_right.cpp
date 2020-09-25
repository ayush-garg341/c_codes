#include<iostream>
#include <vector>
using namespace std;


class Solution {
public:
  void duplicateZeros(vector<int>& arr) {
    vector<unsigned int> new_arr;
    for(int k{0}; k< arr.size(); k++){
      if(arr[k]==0){
	new_arr.push_back(0);
	new_arr.push_back(0);
      }
      else{
	new_arr.push_back(arr[k]);
	
      }
        arr[k] = new_arr[k];
    }
  }
};


int main(){
  Solution soln;
  vector<int> A={1,0,2,3,0,4,5,0};
  soln.duplicateZeros(A);
  return 0;
}
