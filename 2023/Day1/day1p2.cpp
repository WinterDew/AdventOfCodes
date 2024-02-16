#include<iostream>
#include<fstream>
#include<vector>
#include "../../utils/utils.h"
#include<regex>
#include<format>


using std::vector;
using std::string;


int spellCompare(const std::string &str, const std::size_t index){
	switch(str[index]){
		case 'o':
			if(str.compare(index, 3, "one") == 0) return 1;
			break;
		case 't':
			if(str.compare(index, 3, "two") == 0) return 2;
			if(str.compare(index, 5, "three") == 0) return 3;
			break;
		case 'f':
			if(str.compare(index, 4, "four") == 0) return 4;
			if(str.compare(index, 4, "five") == 0) return 5;
			break;
		case 's': 
			if(str.compare(index, 3, "six") == 0) return 6;
			if(str.compare(index, 5, "seven") == 0) return 7;
			break;
		case 'e':
			if(str.compare(index, 5, "eight") == 0) return 8;
			break;
		case 'n':
			if(str.compare(index, 4, "nine") == 0) return 9;
			break;
		default:
			return 0;
	}
	return 0;
}


int main(){

    auto input = readInput();
    int sum = 0;
    
    
    for(string line: input){
        int left = 0, right = 0;

		for(std::size_t i = 0; i < line.length(); ++i){
			if( isdigit(line[i]) ){
				left = line[i] - '0';
				break;
			}else if( (left = spellCompare(line, i)) ){
				break; 
			}
		}
		for(std::size_t i = line.length(); i != 0; --i){
			if( isdigit(line[i-1]) ){
				right = line[i-1] - '0';
				break;
			}else if( (right = spellCompare(line, i-1)) ){
				break;
			}
		}
        sum += left * 10 + right;
    }

    println(sum);
    return 0;
}