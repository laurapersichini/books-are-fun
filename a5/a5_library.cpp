//
//  a5_library.cpp
//  a5
//
//  Created by Laura Persichini on 2020-11-20.
//  Copyright © 2020 Laura Persichini. All rights reserved.
/*
Student Name #1: Laura Persichini
ID#: 20894127
Student Name #2: Chintansingh Gurucharansingh Chhabda
ID: 20872484
 
 SYDE 121 Assignment #5
 File Name: a5_library.cpp
 
 We hereby declare that this code, submitted for credit for the course
 SYDE121, is a product of our own efforts. This coded solution has
 not been plagiarized from other sources and has not been knowingly
 plagiarized by others.

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

#include "a5_library.hpp"

using namespace std;

//non parameterized constructor
Library::Library() {}

//parametric constructor
Library::Library(vector<Book> new_books) {
    //concatenates the parameterizes new vector and the original book vector.
    //This code also holds the functionality to copy its value to the original book vector if the original vector was empty.
    booklist.insert(booklist.end(),new_books.begin(),new_books.end());
}

void Library::print(){
//Member function print.
//Input: None. Output: Void.
//Function: Prints all the books in a library.
    
    //for loop, couts Index value of a book in library
    for(int i=0; i<booklist.size(); i++){
        cout<<"Book Index: "<<i<<endl;
        booklist[i].print_book();
    }
}

bool Library::insert_book(Book book_insert){
//Member function insert_book.
//Input: An object of class Book. Output: Boolean (T if replacement occurs, F otherwise)
//Function: This class inserts the parameterized book in library.
    
    //for loop checks if a similar book is present in library.
    for(int i=0;i<booklist.size();i++){
        if (booklist[i].title==book_insert.title && booklist[i].date_of_pub==book_insert.date_of_pub && booklist[i].authors==book_insert.authors) {
            return false;
        }
    }
    booklist.push_back(book_insert);
    return true;
}

bool Library::insert_book(string title_in, string author_in,string date_in) {
//Member function insert_book.
//Input: 3 strings. Output: Boolean (T if replacement occurs, F otherwise)
/*Function: This class inserts the parameterized strings into the library as information for a book*/
    
    //for loop checks if a similar book is present in library.
    for(int i=0;i<booklist.size();i++){
        if(booklist[i].title==title_in && booklist[i].authors==author_in && booklist[i].date_of_pub==date_in) {
            return false;
        }
    }
    booklist.push_back(Book(title_in,author_in,date_in));
    return true;
    
}

bool Library::remove_book(Book book_remove) {
//Member function remove_book.
//Input: An object of class Book. Output: Boolean (T if erasing occurs, F otherwise)
//Function: This class removes the parameterized book from the library.
    
    //for loop checks if a similar book is present in library.
    for(int i=0;i<booklist.size();i++){
        if (booklist[i].title==book_remove.title && booklist[i].authors==book_remove.authors && booklist[i].date_of_pub==book_remove.date_of_pub){

                //conversion of index value to iterator for erase function.
                vector<Book>::iterator it = booklist.begin() + i;
                booklist.erase(it);
                return true;
        }
    }
    return false;
}

bool Library::remove_book(string title_in, string author_in,string date_in) {
    //Member function remove_book.
    //Input: 3 strings. Output: Boolean (T if erasing occurs, F otherwise)
    /*Function: This class removes the book associated with the parameterized strings from the library.*/
    
    //for loop checks if a similar book is present in library.
    for(int i=0;i<booklist.size();i++){
        if (booklist[i].title==title_in && booklist[i].authors==author_in && booklist[i].date_of_pub==date_in){

                //conversion of index value to iterator for erase function.
                vector<Book>::iterator it = booklist.begin() + i;
                booklist.erase(it);
                return true;
        }
    }
    return false;
}
