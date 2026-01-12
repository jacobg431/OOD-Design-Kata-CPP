#include "MemberManager.h"

MemberManager::MemberManager() = default;

void MemberManager::RegisterMember(const Member& member) { Members.push_back(member); }

void MemberManager::RemoveMember(const Member& member, BorrowManager& borrowManager) 
{
    auto it = std::remove_if(Members.begin(), Members.end(),
        [&](const Member& m){ return m.getMemberId() == member.getMemberId(); });
    Members.erase(it, Members.end());
    std::vector<Book> memberBooks = borrowManager.ViewBorrowedBooks(member);
    
    for (Book book : memberBooks)
    {
        borrowManager.ReturnBook(member, book);
    }
}

void MemberManager::UpdateMember(const std::string& memberId, const Member& updatedMember)
{
    auto it = std::find_if(Members.begin(), Members.end(), [&](const Member& m){ return m.getMemberId() == memberId; });
    if (it != Members.end()) {
        it->setName(updatedMember.getName());
        it->setMemberId(updatedMember.getMemberId());
    }
}

Member* MemberManager::FindMember(const std::string& memberId)
{
    auto it = std::find_if(Members.begin(), Members.end(), [&](const Member& m){ return m.getMemberId() == memberId; });
    return it != Members.end() ? &(*it) : nullptr;
}   