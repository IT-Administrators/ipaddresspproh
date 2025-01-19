# ipaddresspproh

_The ipaddresspproh header is a headerfile, which implements functions to validate ipv4 addresses._

## Table of contents

1. [Introduction](#introduction)
2. [Getting started](#getting-started)
    1. [Prerequisites](#prerequisites)
    2. [Installation](#installation)
3. [How to use](#how-to-use)
    1. [Compile the programm](#compile-the-programm)
    1. [How to import](#how-to-import)
    2. [Using the header](#using-the-header)
4. [License](/LICENSE)

## Introduction

Current this headerfile only validates ipv4 addresses. In the future there might be also ipv6 validation as well as ipaddress manipulation and calculations.

## Getting started

### Prerequisites

- A compiler like gcc or g++
- IDE like VSCode and the right extensions (cpp,..) if you want to make adjustments.

### Installation

To use the headerfile inside your project type the following inside your terminal (requires git):

1. Using Powershell and git

```PS
# Powershell
# Creates a directory in your current directory
md ipaddresspproh
# Change location to the created directory
cd ipaddresspproh
# Pull necessary files
git pull https://github.com/IT-Administrators/ipaddresspproh.git
```
2. Using Powershell without git

```PS
# Download zip archive using powershell
Invoke-WebRequest -Uri "https://github.com/IT-Administrators/ipaddresspproh/archive/refs/heads/main.zip"
# Than expand archive
Expand-Archive -Path .\ArchiveName
```

After that you will find all project related files in the created directory. 

Than you can copy the necessary files to your project folder to use them. You don't need the main.cpp file.

Before using i would recommend compiling and testing the programm. You can find an instruction here: [Compile the programm](#compile-the-programm).

## How to use

### Compile the programm

I would recommend to compile the programm right after download, to see how it works. 
Depending on your chosen compiler the following snippet might look different.

You need to be in the src folder of the project to run the command otherwise you need to specify the full path name:
```
g++ .\main.cpp -o ipaddresspproh
```
After that you will find an .exe file there, called ipaddresspproh.exe which you can run. 

### How to import

Using the headerfile in your project is quite easy. You can include it just like any other file. Depending on your project structure the include statement might look different.

In this example the headerfile is in the same directory as the main file.

```cpp 
// User defined header file.
#include "ipaddresspproh.hpp"
```

### Using the header

Using the class inside your project works the following way. 

After importing the headerfile([How to import](#how-to-import)) you can use the class in two different ways:

1. Using directive
```cpp
// Include necessary libraries.
#include <iostream>

// User defined header file.
#include "ipaddresspproh.hpp"

using namespace std;

int main(){

    IPAddress ip;
    // Show default ipaddress. Default ip is localhost (127.0.0.1).
    cout << ip.ip_address << endl;
    // Change ip address after object initialisation.
    ip.ip_address = "192.168.1.0";
    cout << ip.ip_address << endl;
    // Check if ip address is valid. 
    cout << ip.IsIPv4() << endl;
    // Change ip to non valid ip address.
    ip.ip_address = "192.168.1.340";
    cout << ip.IsIPv4() << endl;
    Change ip to non valid ip address.
    ip.ip_address = "192.256.1:0";
    cout << ip.IsIPv4() << endl;

    // Demonstrate different ways to intialize object.
    string ipadd = "192.168.0.1";
    IPAddress ip2(ipadd);
    cout << ip2.ip_address << endl;
    IPAddress ip3("192.168.0.1");
    cout << ip3.ip_address << endl;
}
```
Result:
```cpp
127.0.0.1 
192.168.1.0
1
0
0
192.168.0.1
192.168.0.1
```

## License

[MIT](/LICENSE)