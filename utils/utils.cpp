#include<iostream>
#include<fstream>
#include<vector>

template<typename T>
void println(T message){
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


std::string stripl(std::string message){
    message.erase(message.find_last_not_of(' ')+1);         
    return message;
}
std::string stripr(std::string message){
    message.erase(0, message.find_first_not_of(' ')); 
    return message;
}
std::string strip(std::string message){
    message = stripr(message);
    message = stripl(message);
    return message;
}
std::vector<std::string> split(std::string message, std::string delim){
    std::vector<std::string> result;
    size_t pos = 0;
    while ((pos = message.find(delim)) != std::string::npos) {
        std::string token = message.substr(0, pos);
        result.push_back(token);
        message.erase(0, pos + delim.length());
    }
    return result;
}

