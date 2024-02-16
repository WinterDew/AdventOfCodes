#include<iostream>
#include<fstream>
#include<vector>
#include "../../utils/utils.h"
using str = std::string;
using Svec = std::vector<str>;

#define RED = 12;
#define GREEN = 13;
#define BLUE = 14;


int main(){
    auto text = readInput("sample.txt");
    int id = 1;
    for (str line: text){
        println("==========================");
        println("======= GAME: " + std::to_string(id) + " ==========");
        for(str piece :split(split(line,":")[1],";")){
            println(piece);
        }

        id++;
    }

    return 0;
}