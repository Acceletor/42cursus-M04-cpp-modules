#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _count;
        int _nextIndex;
        static std::string _formatColumn(const std::string &s);
    
    public:
        PhoneBook();

        void addContact(const Contact &c);
        void displayTable() const;
        int getCount() const;
        bool hasAny() const;
        bool isValidIndex(int i) const;

        void displayContactDetails(int index) const;

        bool cmdAdd();
        bool cmdSearch();
};

#endif