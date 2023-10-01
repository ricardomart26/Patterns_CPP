#ifndef FILE_SYSTEM_COMPONENT_HPP
#define FILE_SYSTEM_COMPONENT_HPP

// FileSystemComponent (Component):
//      This is an abstract base class that defines the common interface for files and directories. 
//      It serves as the Component in the Composite pattern.
//      Common methods include:
//         displayInfo(): Display information about the file or directory.
//         add(): Add a child file or directory (only applicable to directories).
//         remove(): Remove a child file or directory (only applicable to directories).
class FileSystemComponent
{
    public:

        virtual void displayInfo() const = 0;
        virtual void add(FileSystemComponent *component) = 0;
        virtual void remove(FileSystemComponent *component) = 0;

};

#endif
