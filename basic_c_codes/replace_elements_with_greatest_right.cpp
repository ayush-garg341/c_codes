#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> replaceElements(vector<int>& arr) {
    int maxElem{arr[arr.size()-1]};
    for(int i{static_cast<int>( arr.size())-1}; i>=0 ; i--){
      if(i==arr.size()-1){
	arr[i]=-1;
      }
      else if(arr[i]>maxElem){
	int temp{0};
	temp = arr[i];
	arr[i] = maxElem;
	maxElem=temp;
      }
      else{
	arr[i] = maxElem;
      }
    }

    return arr;
  }
};



int main(){
  Solution soln;
  vector<int> arr={17,18,5,4,6,1};
  soln.replaceElements(arr);
  
  return 0;
}
