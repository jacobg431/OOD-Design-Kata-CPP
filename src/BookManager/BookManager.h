#pragma once
#include <vector>
#include "../Book/Book.h"

class BookManager
{
private:
    std::vector<Book> Books;
public:
    BookManager();

    void AddBook(const Book& book);
    void RemoveBook(const Book& book);

    void UpdateBook(const std::string& originalTitle, const Book& updatedBook);
    Book* FindBook(const std::string& title);
};

