#include<iostream>
#include<fstream>
#include<vector>
#include "../../utils/utils.h"
#include<map>
using str = std::string;
using Svec = std::vector<str>;




int main(){
    std::map<str,int> constraints = {{"red",12},{"green",13},{"blue",14}};

    auto text = readInput();
    int id = 1;
    int sum = 0;
    int sum2 = 0;
    for (str game: text){
        std::map<str,int> p2c = {{"red",0},{"green",0},{"blue",0}};

        bool flag = 1;

        println("==========================");
        println("======= GAME: " + std::to_string(id) + " ==========");
        for(str set: split(split(game,":")[1],";")){

            println(set);
            
            for(str turn : split(set,",")){
                int count = std::stoi(split(strip(turn), " ")[0]); str color = strip(split(strip(turn), " ")[1]);
                if(count > constraints[color]){
                    flag = 0;
                }
                if(count > p2c[color]){
                    p2c[color] = count;
                }
            }
            

        }
        
        if(flag){
            sum += id;
        }
        sum2 += p2c["red"] * p2c["green"] * p2c["blue"];
        id++;
    }

    println("========== PART 1 ===========");
    println(std::to_string(sum));
    println("========== PART 2 ===========");
    println(std::to_string(sum2));
    return 0;
}