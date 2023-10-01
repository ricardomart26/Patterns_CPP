#ifndef FILE_HPP
#define FILE_HPP


#include "FileSystemComponent.hpp"
#include <iostream>

// File (Leaf):
//      This class represents a file. It inherits from FileSystemComponent and provides specific file-related functionality.
//      It might have attributes such as file size, creation date, and file content.
//      Implement displayInfo() to display file-specific information.
class File: public FileSystemComponent
{
    public:

        File() {}
        ~File() {}

        void displayInfo() const override {}

    private:
        unsigned int mySize;
        std::string myDate;
        std::string fileContent;

};

#endif
