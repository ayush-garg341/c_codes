#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int isDigit(char c){
        
        switch(c){
                
            case '0':
                return 0;
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
            case '+':
                return 11;
            case '-':
                return 12;
            case '.':
                return 13;
                
            default:
                return -1;
                
        }
    }
    
    int myAtoi(string str) {
        unsigned long bufferLength{str.size()};
        vector<int> new_str;
        long long num{0};
        long long another_num{0};
        char type;
        int char_type{0};
        long long count =  1;
        const int max_int = 2147483647;
        const int min_int = -2147483648;
        int return_val{0};
        for(int i{0}; i<bufferLength; i++){
            if(new_str.size()==0 && i!=0 && (str[i]==' ' || str[i]=='+' || str[i]=='-') && str[i-1]=='0'){
                return 0;   
            }
            else if(str[i]==' ' && new_str.size() == 0){
                continue;
            }
            else if ( (isDigit(str[i])==-1 || isDigit(str[i])==13) && new_str.size()==0){
                return 0;
            }
            else if(str[i]==' ' && new_str.size()!=0){
                break;
            }
            
            else if(new_str.size()==0 && str[i]=='0'){
                continue;
            }
            else if(new_str.size()==1 && (str[0]=='+' || str[0]=='-') && str[i]=='0'){
                continue;
            }
            else{
                new_str.push_back(isDigit(str[i]));
            }
        }
        if(new_str.size()){
           char_type=new_str.at(0);
    }
	if(char_type==11){
	  type='+';
	}
	else if(char_type==12){
	  type='-';
	}
        int string_count{0};
        for (auto ir = new_str.crbegin(); ir != new_str.crend(); ++ir){
            string_count+=1;
            if((*ir == 11 || *ir==12 || *ir==13 || *ir==-1) && string_count!=new_str.size()){
                num=0;
	            count=1;
            }
            else if((*ir == 11 || *ir==12 || *ir==13 || *ir==-1) && string_count==new_str.size()){
	      continue;
	    }
            else{
                    
                if(num<max_int){
                    num = num + (*ir)*count;
                }
                if(count < max_int){
                    count=count*10; 
                }
                
                if(count>max_int && type!='-'){
                    return_val=max_int;
                }
                
                
                
                if(type=='+'){
                    if(num>max_int){
                        return_val = max_int;
                    }   
                }
                else if(type=='-'){
                    another_num = 0-num;
                    if(another_num<min_int){
                        return_val=min_int;
                    }
                }
                
            }
        }
        
        if(type=='+'){
            if(num<max_int){
                return num;
            }
            else{
                return max_int;
            }
        }
        else if(type=='-'){
            another_num = 0-num;
            if(another_num<min_int){
                return return_val;
            }
            else{
                
                return another_num;
            }
        }
        else if(num>max_int){
                return max_int;
            }
            else if(num<=max_int){
                return num;
            }
        else{
            return 0;
        }
        
        
    }
};

int main(){
  Solution sol;
  std::cout << sol.myAtoi("  +b12102370352") << '\n';
}
