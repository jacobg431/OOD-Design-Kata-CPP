#pragma once
#include <vector>
#include "../BookManager/BookManager.h"
#include "../MemberManager/MemberManager.h"

class LibraryManager {
public:
    // Collections
    BookManager bookManager;
    MemberManager memberManager;
    BorrowManager borrowManager;

    LibraryManager();
};
