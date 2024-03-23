#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

template<typename T>
void println(T message = "Hello, World!"){
    std::cout << message << std::endl;
}

template<typename T>
void print(T message = "Hello, World!"){
    std::cout << message;
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


std::string stripl(std::string message, std::string token = " "){
    message.erase(message.find_last_not_of(token)+1);         
    return message;
}
std::string stripr(std::string message, std::string token = " "){
    message.erase(0, message.find_first_not_of(token)); 
    return message;
}
std::string strip(std::string message, std::string token = " "){
    message = stripr(message, token);
    message = stripl(message, token);
    return message;
}
std::vector<std::string> split(std::string message, std::string delim){
    std::vector<std::string> result;
    size_t pos = 0;
    while ((pos = message.find(delim)) != std::string::npos) {
        std::string token = message.substr(0, pos);
        result.push_back(token);
        message.erase(0, pos + delim.length());
        // result.push_back(message);
    }
    result.push_back(message);
    return result;
}

template<typename T>
bool checkInVec(T elem, std::vector<T> vec){
    return std::find(vec.begin(), vec.end(), elem) != vec.end();
}
