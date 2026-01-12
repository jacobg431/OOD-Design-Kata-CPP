#pragma once
#include <string>

class Book
{
private:
    std::string _title;
    std::string _author;
public:
    Book() = default;
    Book(std::string title, std::string author);

    const std::string& getTitle() const;
    void setTitle(const std::string& title);

    const std::string& getAuthor() const;
    void setAuthor(const std::string& author);
};