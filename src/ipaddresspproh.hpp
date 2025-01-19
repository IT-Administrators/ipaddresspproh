/*
This header file contains the function/method declarations for the
ipaddresspproh module.
*/

// Conditional pre processor directive.
// Include guard to prevent importing headerfile more than once.
#ifndef IPADDRESSPPROH_H
#define IPADDRESSPPROH_H

#include <string>
#include <sstream>
#include <vector>
#include <regex>

class  IPAddress
{

    public:
        // Constructor without parameter.

        // Default constructor.
        IPAddress();
        // Custom constructor with string parameter.
        IPAddress(std::string &ipaddress);
        // Custom constructor with char parameter. Input can also be char[].
        IPAddress(const char* c);
        // Default destructor.
        ~ IPAddress();

        // IP address.
        std::string ip_address = "127.0.0.1";

        [[nodiscard]] bool IsIPv4() const;
    

    private:
        [[nodiscard]] std::vector<std::string> SplitString (const std::string &str, const char &del) const;
        [[nodiscard]] bool MatchPattern (const std::string &str, const std::string &pattern) const;

        // IPv4 separator.
        const char ipv4_sep = '.';
        const std::string ipv4_pattern = "(^[0-9]{1,3}\\.)([0-9]{1,3}\\.){2}([0-9]{1,3}$)";
};

IPAddress:: IPAddress()
{
}

inline IPAddress::IPAddress(std::string &ipaddress)
{
    this->ip_address = ipaddress;
}

inline IPAddress::IPAddress(const char *c)
{
    this->ip_address = c;
}

IPAddress::~ IPAddress()
{
}

// Check if provided string is an ipv4 address.
inline bool IPAddress::IsIPv4() const
{   
    // Match pattern. 
    if (MatchPattern(ip_address, ipv4_pattern))
    {
        // If pattern matches, split string into blocks to check if each block has numbers lower than 255.
        std::vector<std::string> substr = SplitString(ip_address, ipv4_sep);
        // Iterate over vector foreach.
        for (auto i : substr)
        {
            // Convert string to int and check if input is greater than 255.
            if (std::stoi(i) > 255)
            {
                return false;
            }
        }
    }
    else{
        // If pattern doesn't match return false.
        return false;
    }
    return true;
}

// Split the provided string into a vector of substrings using the specified delimiter.
inline std::vector<std::string> IPAddress::SplitString(const std::string &str, const char &del) const
{
    std::vector<std::string> words;
    std::string word;

    for (char ch : str) {
        if (ch != del) {
            word += ch;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

// Match the provided string against regex pattern.
inline bool IPAddress::MatchPattern(const std::string &str, const std::string &pattern) const
{
    // Check if the entire string matches the pattern.
    if (std::regex_match(str, std::regex(pattern))) {
        return true;
    }
    return false;
}

#endif 