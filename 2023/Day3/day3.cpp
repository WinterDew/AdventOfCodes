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
    auto text = readInput("sample2.txt");
    long long sum = 0;

    for( int lno = 0; lno < text.size(); lno++){
        // loop every line;
        str line = text[lno];
        long long current_no;
        int counter = 0;
        println(line); // print current line.


        for( int chrno = 0; chrno < line.size(); chrno++){
            char chr = line[chrno];
            //loop every char;


            bool flag = 0;
            if(std::isdigit(chr)){ // check if digit, and scan in current line for complete number.
                while(std::isdigit(line[chrno + counter])){
                    counter++;
                }
                current_no = std::stoi(line.substr(chrno,chrno+counter)); // save complete number as current number
                for(int i = chrno; i < chrno + counter; i++){
                    // loop over the number checking thru 3x3 grid;
                    flag = checkAround(text,lno,i);
                    if(flag){
                        break; // if any digit in current number is next to a symbol, break loop and mark number as valid.
                    }

                }
                chrno += counter;
                print(std::to_string(current_no) + "("); // print current number in question.
                print(flag ? "Yes" : "No");
                print("), ");
                if(flag){
                    sum += current_no;
                    flag = 0;
                }
                
                
            }
           
        } // end char loop;
        println("");
        println("");

    
    
    } // end line loop;


    println("==================PART 1===================");
    println("Answer is: " + std::to_string(sum));
    
    return 0;
}