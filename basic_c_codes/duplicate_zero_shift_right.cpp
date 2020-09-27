#include<iostream>
#include <vector>
using namespace std;


class Solution {
public:
  void duplicateZeros(vector<int>& arr) {
    int count_zeros{0};
    int i{0};
    int actual_size{0};
    int j{static_cast<int>(arr.size())-1};
    char duplicate_last_zero{'0'};

    while(actual_size<arr.size()){
      if(arr[i]==0){
	actual_size += 2;
	count_zeros+=1;
      }
      else{
	actual_size += 1;
      }
      cout<<arr[i]<<"\n";
      i++;
    }

    if((i-count_zeros + (count_zeros*2)) == arr.size()){
      duplicate_last_zero =  '1';
    }

    cout<<"number of elements we can acoomodate in new array " << i << "\n";

    for(int k{i-1}; k>=0;k--){
      if(arr[k]==0 && (j<arr.size()-1 ||  duplicate_last_zero=='1')){
      	arr[j]=0;
      	arr[j-1]=0;
      	j = j-2;
      }
      else{
      	arr[j]=arr[k];
      	j = j-1;
      	
      }
      
    }

    for(int i{0}; i<arr.size(); i++){
      cout<<"array elements "<< arr[i]<<"\n";
    }

    cout<<"\n";
    
  }
};


int main(){
  Solution soln;
  vector<int> A={1,5,2,0,6,8,0,6,0};
  soln.duplicateZeros(A);
  return 0;
}
