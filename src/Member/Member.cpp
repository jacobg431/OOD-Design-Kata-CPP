#include <string>
#include "Member.h"

Member::Member(std::string name, std::string memberId) : 
    _name(std::move(name)), _memberId(std::move(memberId)) 
{}

const std::string& Member::getName() const { return _name; }
void Member::setName(const std::string& name) { _name = name; }

const std::string& Member::getMemberId() const { return _memberId; }
void Member::setMemberId(const std::string& memberId) { _memberId = memberId; }

bool Member::operator==(const Member& other) const { return _memberId == other._memberId; }

size_t std::hash<Member>::operator()(const Member& m) const noexcept {
    return std::hash<std::string>()(m.getMemberId());
}