#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "../Book/Book.h"
#include "../Member/Member.h"

class BorrowManager
{
private:
    std::unordered_map<Member, std::vector<Book>> BorrowedBooks;
public:
    BorrowManager();

    void BorrowBook(const Member& member, const Book& book);
    void ReturnBook(const Member& member, const Book& book);
    
    std::vector<Book> ViewBorrowedBooks(const Member& member) const;
};