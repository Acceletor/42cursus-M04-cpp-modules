#include <iostream>
#include <string>

int main() {

    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "The Memory Address held by:" << std::endl;
    std::cout << "str: " << &str << std::endl
              << "stringPTR: " << stringPTR << std::endl
              << "stringREF: " << &stringREF << std::endl
              << std::endl;
    
    std::cout << "VALUE:" << std::endl;
    std::cout << "str: " << str << std::endl
              << "stringPTR: " << *stringPTR << std::endl
              << "stringREF: " << stringREF << std::endl;

    return (0);
}
