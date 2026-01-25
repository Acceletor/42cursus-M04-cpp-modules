#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>

int main (){
    PhoneBook pb;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            break;
        if (cmd == "ADD")
        {
            if (!pb.cmdAdd())
                break;
        }
        else if (cmd == "SEARCH")
        {
            if(!pb.cmdSearch())
                break;
        }
        else if (cmd == "EXIT")
            break;
    }

    return (0);
}