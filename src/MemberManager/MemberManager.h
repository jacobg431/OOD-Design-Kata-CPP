#pragma once
#include <vector>
#include "../Member/Member.h"
#include "../BorrowManager/BorrowManager.h"

class MemberManager
{
private:
    std::vector<Member> Members;
public:
    MemberManager();

    void RegisterMember(const Member& member);
    void RemoveMember(const Member& member, BorrowManager& borrowManager);

    void UpdateMember(const std::string& memberId, const Member& updatedMember);
    Member* FindMember(const std::string& memberId);
};