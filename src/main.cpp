#include <iostream>
#include <string>
#include <sstream>
#include "Book/Book.h"
#include "Member/Member.h"
#include "LibraryManager/LibraryManager.h"

int main()
{
    LibraryManager myLibrary;
    
    Book bookExampleOne("Example Book 1", "Example Author 1");
    Book bookExampleTwo("Example Book 1", "Example Author 2");
    Book bookExampleThree("Example Book 2", "Example Author 2");
    Book bookExampleFour("Example Book 3", "Example Author 3");

    myLibrary.bookManager.AddBook(bookExampleOne);
    myLibrary.bookManager.AddBook(bookExampleTwo);
    myLibrary.bookManager.AddBook(bookExampleThree);
    myLibrary.bookManager.AddBook(bookExampleFour);

    Member memberExampleOne("Example Name 1", "ID-1");
    Member memberExampleTwo("Example Name 2", "ID-2");
    Member memberExampleThree("Example Name 3", "ID-3");
    Member memberExampleFour("Example Name 4", "ID-4");

    myLibrary.memberManager.RegisterMember(memberExampleOne);
    myLibrary.memberManager.RegisterMember(memberExampleTwo);
    myLibrary.memberManager.RegisterMember(memberExampleThree);
    myLibrary.memberManager.RegisterMember(memberExampleFour);

    myLibrary.borrowManager.BorrowBook(memberExampleOne, bookExampleOne);

    std::string memberExampleOneName = memberExampleOne.getName();
    std::stringstream ss;
    ss << "Member " << memberExampleOneName << " has the following books:" << std::endl;
    for (Book memberBook : myLibrary.borrowManager.ViewBorrowedBooks(memberExampleOne))
    {
        ss << memberBook.getTitle() << " by " << memberBook.getAuthor() << std::endl;
    }
    ss << std::endl;
    std::string str = ss.str();
    std::cout << str << std::endl;
}