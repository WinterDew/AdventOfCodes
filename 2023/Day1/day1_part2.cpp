#include<iostream>
#include<fstream>
#include<vector>
#include "../../utils/utils.h"
#include<regex>
#include<format>


using std::vector;
using std::string;

vector<string> list = {"one","two","three","four","five","six","seven","eight","nine"};


int main(){

    std::regex r = std::regex("(?=([0-9]|one|two|three|four|five|six|seven|eight|nine))");
    auto input = readInput("sample.txt");
    int sum = 0;
    
    vector<string> data;
    for(string line: input){
        //to implement;
        
    }

    return 0;
}