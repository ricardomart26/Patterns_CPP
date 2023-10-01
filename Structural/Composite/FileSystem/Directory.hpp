#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP


#include "FileSystemComponent.hpp"
#include "File.hpp"
#include <vector>

// Directory (Composite):
//     This class represents a directory. It inherits from FileSystemComponent and can contain a collection of files and subdirectories.
//     It implements methods like add() to add child files or directories and remove() to remove them.
//     Implement displayInfo() to display directory-specific information and the list of child elements.


class Directory: public FileSystemComponent
{
    public:

        Directory() {}
        ~Directory() {}

        void displayInfo() const override {}
        void add(FileSystemComponent *component) override {}
        void remove(FileSystemComponent *component) override {}


    private:

        std::vector<File *> myFiles;
        std::vector<Directory *> myDirectories;

};

#endif