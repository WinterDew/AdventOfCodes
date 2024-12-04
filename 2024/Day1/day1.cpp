#include<iostream>
#include<fstream>
#include<vector>
#include "../../cpp/utils/utils.h"

using str = std::string;


int main(){
    int sum = 0,sum2 = 0;

    // std::vector<str> txt = readInput("sample.txt");
    std::vector<str> txt = readInput();


    std::vector<int> firstList, secondList;
    for(str v : txt){
        firstList.push_back(std::stoi(split(v, "   ")[0]));
        secondList.push_back(std::stoi(split(v, "   ")[1]));
    }
    std::sort(firstList.begin(), firstList.end());
    std::sort(secondList.begin(), secondList.end());

    for(int i = 0; i < firstList.size(); i++){
        sum += std::abs(firstList[i] -  secondList[i]);
        // part 2
        int count = 0;
        for(int j = 0; j < secondList.size(); j++){
            if(firstList[i] == secondList[j]) count++;
        }
        sum2 += count * firstList[i];
    }

    

 
    println("");
    println("==================PART 1===================");
    println("Answer is: " + std::to_string(sum));
    println("==================PART 2===================");
    println("Answer is: " + std::to_string(sum2));
    return 0;

}
