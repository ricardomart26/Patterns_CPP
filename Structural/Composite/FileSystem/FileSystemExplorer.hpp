#ifndef FILE_SYSTEM_EXPLORER_HPP
#define FILE_SYSTEM_EXPLORER_HPP

#include "FileSystemComponent.hpp"
#include <vector>
#include <iostream>

// File System Explorer

// Main Menu:
// 1. List Contents of Current Directory
// 2. Create File
// 3. Create Directory
// 4. Delete File
// 5. Delete Directory
// 6. Navigate to Directory
// 7. View File
// 8. Search for File/Directory
// 9. Copy File/Directory
// 10. Move/Rename File/Directory
// 11. Exit

// Enter your choice (1-11):

// FileSystemExplorer (Client):
//      This is the main application that allows users to interact with the file system. 
//      It provides a user-friendly command-line interface (CLI) for managing files and directories.
//      It maintains a reference to the root directory, which serves as the entry point to the file system.
//      Implement functions for operations like creating files, creating directories, deleting files, deleting directories,
//      navigating through the file system, displaying the file system structure, viewing file contents, searching for files,
//      and performing file operations (copy, move, rename).

typedef enum OptionsEnum {
    LIST,
    CREATE_FILE,
    CREATE_DIR,
    DELETE_FILE,
    DELETE_DIR,
    NAVIGATE,
    VIEW_FILE,
    SEARCH,
    COPY,
    MOVE_OR_RENAME,
    EXIT,
};


class FileSystemExplorer
{

    public:

        FileSystemExplorer()
            : myMenuOptions({
                "List Contents of Current Directory",
                "Create File",
                "Create Directory",
                "Delete File",
                "Delete Directory",
                "Navigate to Directory",
                "View File",
                "Search for File/Directory",
                "Copy File/Directory",
                "Move/Rename File/Directory",
                "Exit",
            })
        {

        }


        void displayMainMenu()
        {
            while (true)
            {
                std::cout << "File System Explorer\n\n";
                std::cout << "Main Menu:\n";
                for (size_t i = 0; i < myMenuOptions.size(); i++)
                    std::cout << i + 1 << ". " << myMenuOptions[i] << std::endl;
                int option;
                std::cin >> option;
                option = option - 1;
                if (option == EXIT)
                    break;
                else if (option == LIST)
                {

                }
            }
        }




    private:

        std::vector<std::string> myMenuOptions;

};



#endif