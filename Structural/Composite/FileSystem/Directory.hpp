#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP


#include "FileSystemComponent.hpp"


// Directory (Composite):
//     This class represents a directory. It inherits from FileSystemComponent and can contain a collection of files and subdirectories.
//     It implements methods like add() to add child files or directories and remove() to remove them.
//     Implement displayInfo() to display directory-specific information and the list of child elements.


class Directory: public FileSystemComponent
{

};

#endif