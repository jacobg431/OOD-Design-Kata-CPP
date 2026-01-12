#include "BorrowManager.h"

BorrowManager::BorrowManager() = default;

void BorrowManager::BorrowBook(const Member& member, const Book& book)
{
    BorrowedBooks[member].push_back(book);
}

void BorrowManager::ReturnBook(const Member& member, const Book& book) 
{
    auto it = BorrowedBooks.find(member);
    if (it != BorrowedBooks.end()) {
        auto& list = it->second;
        auto jt = std::remove_if(list.begin(), list.end(),
            [&](const Book& b){ return b.getTitle() == book.getTitle() && b.getAuthor() == book.getAuthor(); });
        list.erase(jt, list.end());
    }
}

std::vector<Book> BorrowManager::ViewBorrowedBooks(const Member& member) const 
 {
    auto it = BorrowedBooks.find(member);
    if (it != BorrowedBooks.end()) return it->second;
    return {};
}