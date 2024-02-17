#include<iostream>
#include<fstream>
#include<vector>
#include "../../utils/utils.h"
using str = std::string;
using vec = std::vector<str>;

// IMPORTANT ccurrently abandoning day3 since I've got no idea on how to do it.
// will come back to it later.

int main(){
    auto text = readInput("sample.txt");
    for( int lno = 0; lno < text.size(); lno++){
        str line = text[lno];
        int current_no;
        int counter = 0;
        println(line);
        for( int chrno = 0; chrno < line.size(); chrno++){
            char chr = line[chrno];
            if(std::isdigit(chr)){
                while(std::isdigit(line[chrno + counter])){
                    counter++;
                }
                current_no = std::stoi(line.substr(chrno,chrno+counter));
                println(current_no);
            }
        }
    }

    return 0;
}