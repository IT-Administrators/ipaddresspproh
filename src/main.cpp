/*
This file is the driver file to illustrate the implementation of 
ippproh.hpp.

Compile with (from src):
g++ .\main.cpp -o ippproh.exe
*/

// Include necessary libraries.
#include <iostream>
#include <fstream>

// User defined header file.
#include "ipaddresspproh.hpp"

using namespace std;

int main(){

    std::string str4;
    std::ifstream testfile4;
    IPAddress ipv4;
    // Create stream object of text.
    testfile4.open("../examples/ipv4.txt");    
    while (std::getline(testfile4, str4))
    {
        cout << str4 << endl;
        ipv4.ip_address = str4;
        cout << ipv4.IsIPv4() << endl;
    }
    testfile4.close();


    std::string str6;
    std::ifstream testfile6;
    IPAddress ipv6;
    // Create stream object of text.
    testfile6.open("../examples/ipv6.txt");    
    while (std::getline(testfile6, str6))
    {
        cout << str6 << endl;
        ipv6.ip_address = str6;
        cout << ipv6.IsIPv6() << endl;
    }
    testfile6.close();  
}