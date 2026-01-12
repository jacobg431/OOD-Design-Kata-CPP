#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "../Book/Book.h"
#include "../Member/Member.h"

class LibraryManager {
public:
    // Collections
    std::vector<Book> Books;
    std::vector<Member> Members;
    std::unordered_map<Member, std::vector<Book>> BorrowedBooks;

    LibraryManager();

    void AddBook(const Book& book) { Books.push_back(book); }

    void RemoveBook(const Book& book);

    void UpdateBook(const std::string& originalTitle, const Book& updatedBook);

    Book* FindBook(const std::string& title);

    void RegisterMember(const Member& member);

    void RemoveMember(const Member& member);

    void UpdateMember(const std::string& memberId, const Member& updatedMember);

    Member* FindMember(const std::string& memberId);

    void BorrowBook(const Member& member, const Book& book);

    void ReturnBook(const Member& member, const Book& book);

    std::vector<Book> ViewBorrowedBooks(const Member& member) const;
};
