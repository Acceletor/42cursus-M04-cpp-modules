#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(): _count(0), _nextIndex(0) {}

std::string PhoneBook::_formatColumn(const std::string &s)
{
    if (s.length() <= 10)
        return s;
    return s.substr(0, 9)+ ".";
}

void PhoneBook::addContact(const Contact &c)
{
    _contacts[_nextIndex] = c;
    // _contacts[_nextIndex].markSet(true);

    _nextIndex = (_nextIndex + 1) % 8;
    if (_count < 8)
        _count++;
}

int PhoneBook::getCount() const { return _count; }
bool PhoneBook::hasAny() const { return _count > 0; }

bool PhoneBook::isValidIndex(int i) const 
{
    return (i >= 1 && i <= _count);
}

void PhoneBook::displayTable() const
{
    std::cout << std::setw(10) << "Index" << "|"
        << std::setw(10) << "First Name" <<  "|"
        << std::setw(10) << "Last Name" << "|"
        << std::setw(10) << "Nickname" << "\n";
    for (int row = 0; row < _count; row++)
    {
        int idx;
        if (_count < 8)
            idx = row;
        else
            idx = (_nextIndex + row) % 8;

        const Contact &c = _contacts[idx];
        std::cout << std::setw(10) << (row + 1) << "|"
            << std::setw(10) << _formatColumn(c.getFirstName()) << "|"
            << std::setw(10) << _formatColumn(c.getLastName()) << "|"
            << std::setw(10) << _formatColumn(c.getNickname()) << "\n";
    }
}

//index based on display order
void PhoneBook::displayContactDetails(int index) const
{
    int idx;
    if (_count < 8)
        idx = index - 1;
    else
        idx = (_nextIndex + (index - 1)) % 8;

    const Contact &c = _contacts[idx];

    std::cout << "First name: " << c.getFirstName() << "\n";
	std::cout << "Last name: " << c.getLastName() << "\n";
	std::cout << "Nickname: " << c.getNickname() << "\n";
	std::cout << "Phone number: " << c.getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << c.getDarkestSecret() << "\n";
}

static bool readNonEmptyLine(const std::string &prompt, std::string &out)
{
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, out))
            return false;
        if (!out.empty())
            return true;
        std::cout << "Field can't be empty. Try again.\n";
    }
}

bool isAllDigits(std::string s)
{
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!std::isdigit((unsigned char)s[i]))
            return false;
    }
    return true;
}


bool PhoneBook::cmdAdd()
{
    Contact c;
    std::string s;

    if (!readNonEmptyLine("First name: ", s)) return false;
    c.setFirstName(s);
    if (!readNonEmptyLine("Last name: ", s)) return false;
    c.setLastName(s);
    if (!readNonEmptyLine("Nickname: ", s)) return false;
    c.setNickname(s);
    while (true)
    {
        if (!readNonEmptyLine("Phone number: ", s)) return false;
        if (isAllDigits(s)) break;
        std::cout << "Phone number should contain digits only. Try again.\n";
    }
    c.setPhoneNumber(s);

    if (!readNonEmptyLine("Darkest Secret: ", s)) return false;
    c.setDarkestSecret(s);

    addContact(c);
    return true;
}

bool PhoneBook::cmdSearch()
{
    if (!hasAny())
    {
        std::cout << "PhoneBook is empty.\n";
        return true;
    }
    displayTable();
    std::string s;
    std::cout << "Enter index to display details: ";
    if (!std::getline(std::cin, s))
        return false;
    if (!isAllDigits(s))
    {
        std::cout << "Invalid index.\n";
        return true;
    }
    int idx = std::stoi(s);
    if (!isValidIndex(idx))
    {
        std::cout << "Index out of range.\n";
        return true;
    }
    displayContactDetails(idx);
    return true;
}