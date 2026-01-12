#include "BookManager.h"

BookManager::BookManager() = default;

void BookManager::AddBook(const Book& book) { Books.push_back(book); }

void BookManager::RemoveBook(const Book& book)
{
    auto it = std::remove_if
    (
        Books.begin(), Books.end(),
        [&](const Book& b){ return b.getTitle() == book.getTitle() && b.getAuthor() == book.getAuthor(); }
    );
    Books.erase(it, Books.end());
}

void BookManager::UpdateBook(const std::string& originalTitle, const Book& updatedBook)
{
    auto it = std::find_if(Books.begin(), Books.end(), [&](const Book& b){ return b.getTitle() == originalTitle; });
    if (it != Books.end()) {
        it->setTitle(updatedBook.getTitle());
        it->setAuthor(updatedBook.getAuthor());
    }
}

Book* BookManager::FindBook(const std::string& title)
{
    auto it = std::find_if(Books.begin(), Books.end(), [&](const Book& b){ return b.getTitle() == title; });
    return it != Books.end() ? &(*it) : nullptr;
}