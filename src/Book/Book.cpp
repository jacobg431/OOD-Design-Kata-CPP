#include <string>
#include "Book.h"

Book::Book(std::string title, std::string author) : 
    _title(std::move(title)), _author(std::move(author)) 
{}

const std::string& Book::getTitle() const { return _title; }
void Book::setTitle(const std::string& title) { _title = title; }

const std::string& Book::getAuthor() const { return _author; }
void Book::setAuthor(const std::string& author) { _author = author; }
