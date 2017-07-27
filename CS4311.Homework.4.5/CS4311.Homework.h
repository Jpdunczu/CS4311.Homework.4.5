//
//  CS4311.Homework.h
//  CS4311.Homework.4.5
//
//  Created by Joshua Duncan on 7/27/17.
//  Copyright © 2017 Joshua Duncan. All rights reserved.
//

#ifndef CS4311_Homework_h
#define CS4311_Homework_h


#include <iostream>
#include <vector>
#include <cstring>

namespace View {
    
    class UI {
        
    public:
        
        //UI();
        
        void userOptions() {
            std::cout << std::endl;
            std::cout << "(E)nter a Number\n(G)et a number\n(Q)uit\n" << std::endl;
            std::cout << "Enter your choice(EGQ): ";
        }
        
        void badChoice() {
            std::cout << std::endl;
            std::cout << "Your choice sucked..\n" << std::endl;
            
        }
        
        void makeEntryName() {
            std::cout << std::endl;
            std::cout << "Enter first name: ";
        }
        
        void makeEntryNumber() {
            std::cout << std::endl;
            std::cout << "Phone number(10-digits): ";
        }
        
        void makeEntrySuccess() {
            std::cout << std::endl;
            std::cout << "Entry Successful!";
        }
        
        void getEntry() {
            std::cout << std::endl;
            std::cout << "Enter first name: ";
        }
        
        void displayResult(std::string output) {
            std::cout << std::endl;
            std::cout << output;
            std::cout << " ";
        }
        
        void incorrectNumber() {
            std::cout << std::endl;
            std::cout << "Please enter the 10-digit number (no spaces or dashes)";
        }
    };
}


namespace Model {
    
    class Array {
    public:
        std::vector<std::string> entryNumbers;
        std::vector<std::string> entryNames;
        
        //Array();
        
        void makeEntry(std::string name, std::string number) {
            entryNumbers.push_back(number);
            entryNames.push_back(name);
        }
        
        std::vector<std::string> getEntry(std::string name) {
            int index;
            for(index = 0; index <= entryNames.size(); index++) {
                
                if( entryNames[index] == name ) {
                    std::vector<std::string> foundEntry;
                    foundEntry.push_back(entryNames[index]);
                    foundEntry.push_back(entryNumbers[index]);
                    return foundEntry;
                }
            }
            std::vector<std::string> entryNotFound(1,"Entry does not exist.");
            return entryNotFound;
        }
    };
}

namespace Domain {
    
    class DoPhoneBook {
        
    public:
        Model::Array entryArray;
        View::UI ui;
        
        //DoPhoneBook();
        
        void phoneBook(std::string usersChoice) {
            
            std::string choice;
            std::string name;
            std::string number;
            
            while( usersChoice != "q" || usersChoice != "Q" ) {
                
                if ( usersChoice == "e" || usersChoice == "E" ) {
                    ui.makeEntryName();
                    std::cin >> name;
                    ui.makeEntryNumber();
                    std::cin >> number;
                    while ( number.length() != 10 ) {
                        ui.incorrectNumber();
                        std::cin >> number;
                    }
                    makeEntry(name,number);
                    ui.makeEntrySuccess();
                } else if ( usersChoice == "g" || usersChoice == "G" ) {
                    ui.getEntry();
                    std::cin >> name;
                    getEntry(name);
                } else {
                    ui.badChoice();
                }
                ui.userOptions();
                std::cin >> usersChoice;
            }
        }
        
        void makeEntry(std::string name, std::string number) {
            entryArray.makeEntry(name,number);
        }
        
        void getEntry(std::string name) {
            std::vector<std::string> result;
            result = entryArray.getEntry(name);
            for( int i = 0; i <= result.size(); i++ ) {
                ui.displayResult(result[i]);
            }
        }
        
        void init() {
            std::string choice;
            ui.userOptions();
            std::cin >> choice;
            phoneBook(choice);
        }
    };
}


#endif /* CS4311_Homework_h */
