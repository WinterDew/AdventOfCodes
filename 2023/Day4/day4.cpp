#include<iostream>
#include<fstream>
#include<vector>
#include "../../utils/utils.h"
using str = std::string;


int main(){
    auto cards = readInput("sample.txt");
    int id = 0;
    int sum = 0;
    int sum2 = 0;

    for(str card: cards){
        int cardSum = 0;
        println(card);
        auto winning_numbers = split(strip(split(split(card,":")[1],"|")[0])," ");
        auto own_numbers = split(strip(split(split(card,":")[1],"|")[1])," ");
        for(auto number: winning_numbers){
            for(auto oNumber: own_numbers){
                if(strip(number) == strip(oNumber) && strip(number) != ""){
                    print(number + "-" + oNumber + ";");
                    if(cardSum == 0){
                        cardSum++;
                    } else {
                        cardSum *= 2;
                    }
                }
            }
        }

       
        println("");
        println(cardSum);
        sum += cardSum;
        id++;
    }
    
    
    println("");
    println("==================PART 1===================");
    println("Answer is: " + std::to_string(sum));
    println("==================PART 2===================");
    println("Answer is: " + std::to_string(sum2));
    return 0;
}