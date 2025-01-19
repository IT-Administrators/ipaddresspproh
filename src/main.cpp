/*
This file is the driver file to illustrate the implementation of 
ippproh.hpp.

Compile with (from src):
g++ .\main.cpp -o ippproh.exe
*/

// Include necessary libraries.
#include <iostream>

// User defined header file.
#include "ipaddresspproh.hpp"

using namespace std;

int main(){

    IPAddress ip;
    cout << ip.ip_address << endl;
    ip.ip_address = "192.168.1.0";
    cout << ip.ip_address << endl;
    cout << ip.IsIPv4() << endl;
    ip.ip_address = "192.168.1.340";
    cout << ip.IsIPv4() << endl;
    ip.ip_address = "192.256.1:0";
    cout << ip.IsIPv4() << endl;

    string ipadd = "192.168.0.1";
    IPAddress ip2(ipadd);
    cout << ip2.ip_address << endl;

    IPAddress ip3("192.168.0.1");
    cout << ip3.ip_address << endl;
}