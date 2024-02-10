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
    
    println("Hello World!");
    return 0;
}