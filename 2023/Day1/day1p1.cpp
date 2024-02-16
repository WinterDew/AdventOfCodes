#include<iostream>
#include<fstream>
#include<vector>
#include "../../utils/utils.h"

int main(){
    std::vector<std::string> txt = readInput();
    // for(std::string line: inp){
    //     println(line);
    // }
    // println(std::to_string(inp.size()));
    int output = 0;
    for( std::string line : txt){
        std::string value = "";
        for (char chr: line){
            if(std::isdigit(chr)){
                value += chr;
                break;
            }    
        }
        for (char chr: std::string(line.rbegin(),line.rend())){
            if(std::isdigit(chr)){
                value += chr;
                break;
            }
        }
       
        int out = std::stoi(value);
        
        // println(std::to_string(out));
        output += out;

    }

    println(std::to_string(output));
    // println("Hello World!");
    // std::cin.get();
    return 0;
}