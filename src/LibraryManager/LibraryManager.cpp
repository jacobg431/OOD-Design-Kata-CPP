#include "LibraryManager.h"

LibraryManager::LibraryManager() = default;

void LibraryManager::AddBook(const Book& book) { Books.push_back(book); }

void LibraryManager::RemoveBook(const Book& book)
{
    auto it = std::remove_if
    (
        Books.begin(), Books.end(),
        [&](const Book& b){ return b.getTitle() == book.getTitle() && b.getAuthor() == book.getAuthor(); }
    );
    Books.erase(it, Books.end());
}

void LibraryManager::UpdateBook(const std::string& originalTitle, const Book& updatedBook)
{
    auto it = std::find_if(Books.begin(), Books.end(), [&](const Book& b){ return b.getTitle() == originalTitle; });
    if (it != Books.end()) {
        it->setTitle(updatedBook.getTitle());
        it->setAuthor(updatedBook.getAuthor());
    }
}

Book* LibraryManager::FindBook(const std::string& title)
{
    auto it = std::find_if(Books.begin(), Books.end(), [&](const Book& b){ return b.getTitle() == title; });
    return it != Books.end() ? &(*it) : nullptr;
}

void LibraryManager::RegisterMember(const Member& member) { Members.push_back(member); }

void LibraryManager::RemoveMember(const Member& member) 
{
    auto it = std::remove_if(Members.begin(), Members.end(),
        [&](const Member& m){ return m.getMemberId() == member.getMemberId(); });
    Members.erase(it, Members.end());
    BorrowedBooks.erase(member);
}

void LibraryManager::UpdateMember(const std::string& memberId, const Member& updatedMember)
{
    auto it = std::find_if(Members.begin(), Members.end(), [&](const Member& m){ return m.getMemberId() == memberId; });
    if (it != Members.end()) {
        it->setName(updatedMember.getName());
        it->setMemberId(updatedMember.getMemberId());
    }
}

Member* LibraryManager::FindMember(const std::string& memberId)
{
    auto it = std::find_if(Members.begin(), Members.end(), [&](const Member& m){ return m.getMemberId() == memberId; });
    return it != Members.end() ? &(*it) : nullptr;
}   

void LibraryManager::BorrowBook(const Member& member, const Book& book)
{
    BorrowedBooks[member].push_back(book);
}

void LibraryManager::ReturnBook(const Member& member, const Book& book) 
{
    auto it = BorrowedBooks.find(member);
    if (it != BorrowedBooks.end()) {
        auto& list = it->second;
        auto jt = std::remove_if(list.begin(), list.end(),
            [&](const Book& b){ return b.getTitle() == book.getTitle() && b.getAuthor() == book.getAuthor(); });
        list.erase(jt, list.end());
    }
}

std::vector<Book> LibraryManager::ViewBorrowedBooks(const Member& member) const 
 {
    auto it = BorrowedBooks.find(member);
    if (it != BorrowedBooks.end()) return it->second;
    return {};
}