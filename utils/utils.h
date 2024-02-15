#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include "utils.cpp"

template<typename T>
void println(T message);

std::vector<std::string> readInput(const char* filename);
std::string stripl(std::string message);
std::string stripr(std::string message);
std::string strip(std::string message);
std::vector<std::string> split(std::string message, std::string delim);

