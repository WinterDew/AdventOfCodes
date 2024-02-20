#include<iostream>
#include<fstream>
#include<vector>
#include "../../utils/utils.h"
using str = std::string;
using vec = std::vector<str>;


int checkLeft(std::string &str, size_t index){
	if(index > 0 && str[index-1] != '.' && !isdigit(str[index-1])){
		return 1;
	}
	return 0;
}

int checkRight(std::string &str, size_t index){
	if( (index < str.length()-1) && str[index+1] != '.' && !isdigit(str[index+1])){
		return 1;
	}
	return 0;
}

// helper functions, to look around.
bool checkAround(std::vector<std::string> &lines, size_t lineNum, size_t index){
	bool found = false;
	found = checkLeft(lines[lineNum], index) || checkRight(lines[lineNum], index);

	// this could definitely be way cleaner
	if(lineNum == 0){
		// can't check up
		if(lines[lineNum+1][index] != '.' && !isdigit(lines[lineNum+1][index])){
			found = true;
		}
		found = found || checkLeft(lines[lineNum+1], index) || checkRight(lines[lineNum+1], index);

	}else if( lineNum == lines.size()-1 ){
		// can't check down
		if(lines[lineNum-1][index] != '.' && !isdigit(lines[lineNum-1][index])){
			found = true;
		}
		found = found || checkLeft(lines[lineNum-1], index) || checkRight(lines[lineNum-1], index);
	}else{
		// check up
		if(lines[lineNum-1][index] != '.' && !isdigit(lines[lineNum-1][index])){
			found = true;
		}
		found = found || checkLeft(lines[lineNum-1], index) || checkRight(lines[lineNum-1], index);
		// check down
		if(lines[lineNum+1][index] != '.' && !isdigit(lines[lineNum+1][index])){
			found = true;
		}
		found = found || checkLeft(lines[lineNum+1], index) || checkRight(lines[lineNum+1], index);
	}
	return found;
}



int main(){
    auto text = readInput("input.txt");
	str currentNo = "";
    bool flag = 0;
    long long sum = 0;
	

    for(int lno = 0; lno < text.size(); lno++){
		// for every line.

		println(text[lno]);
		str line = text[lno];
		for(int chrno = 0; chrno < line.size(); chrno++){
			char chr = line[chrno];
			if(std::isdigit(chr)){
				while(std::isdigit(line[chrno])){
					currentNo += line[chrno];
					if(checkAround(text,lno,chrno)){
						flag = 1;
					}
					chrno++;
				}
			}
			if(flag){
				print(currentNo + ",");
				sum += std::stoi(currentNo);
				
			}
			currentNo = "";
			flag = 0;
		}
		println("");

	}// end for every line.

	println("");
    println("==================PART 1===================");
    println("Answer is: " + std::to_string(sum));
    
    return 0;
}