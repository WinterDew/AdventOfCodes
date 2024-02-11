#include<iostream>
#include<fstream>
#include<vector>

void println(const std::string message){
    std::cout << message << std::endl;
}
void println(const char* message){
    std::cout << message << std::endl;
}

std::vector<std::string> readInput(const char* filename = "input.txt"){
    std::vector<std::string> text;
    std::string line;
    std::ifstream file;
    file.open(filename);
    while(std::getline(file,line)){
        text.push_back(line);
    }
    file.close();
    return text;
}

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