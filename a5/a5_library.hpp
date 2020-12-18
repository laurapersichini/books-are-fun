//
//  a5_library.hpp
//
//  Created by Laura Persichini on 2020-11-20.
//  Copyright © 2020 Laura Persichini. All rights reserved.
/*

 Project: Books are awesome
 Purpose: Create a book object with a title, author, and date of publication using a library and book class. Implement the insert and remove functions from the library class to add or remove books.
 Due date: November 20th, 2020

Testing:
 We tested the following scenarios to ensure that our prorgram was working correctly:
1.Inserting a book that is already in the Library
2. Inserting a book not in the library
3. Removing a book that is not in the library
4. Removing a book that is in the library.
5. All 4 constrctor declarations for Book class, where we tried defining a book variable all 4 ways and ensured they behaved correctly.
6. Both Library class constructor declaration, where we implemented both and made sure they worked.
 Sample Output: The author(s) of the book is: Carlo Collodi
 The date of publication of the book is: 1883
 Book Index: 2
 The title of the book is: Catcher in the Rye
 The author(s) of the book is: J.D. Salinger
 The date of publication of the book is: 1951
 Book Index: 0
 The title of the book is: The Hunger Games
 The author(s) of the book is: Suzanne Collins
 The date of publication of the book is: 2008
 Book Index: 0
 The title of the book is: The Hunger Games
 The author(s) of the book is: Suzanne Collins
 The date of publication of the book is: 2008
 Book Index: 1
 The title of the book is: Pinocchio
 The author(s) of the book is: Carlo Collodi
 The date of publication of the book is: 1883
 Program ended with exit code: 0

Limitation of the program: Even though the assignment did not instruct us to do so, we noticed that it was not possible for us to implement a book constructor where the value for authors was "n/a" as, if there were only 2 parameters in the constructors, the compiler would always assign the 2nd parametric value to author and there is no way to implement the constructor in a way where title and dat_of_pub are parameterized and author is "n/a". **/

//

#ifndef a5_library_hpp
#define a5_library_hpp

#include <vector>
#include "a5_book.hpp"

using namespace std;

//class declaration
class Library {
    //public members
public:
    //data member
    vector<Book> booklist;
    
    //non parameterized constructor
    Library();
    //parametric constructor
    Library(vector<Book> new_books);

    void print();
    bool insert_book(string, string, string);
    bool insert_book(Book);

    bool remove_book(string, string, string);
    bool remove_book(Book);

};
#endif
