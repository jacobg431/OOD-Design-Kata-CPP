#pragma once
#include <string>

class Member {
private:
    std::string _name;
    std::string _memberId;
public:
    Member() = default;
    Member(std::string name, std::string memberId);

    const std::string& getName() const;
    void setName(const std::string& name);

    const std::string& getMemberId() const;
    void setMemberId(const std::string& memberId);

    // Equality based on memberId (mirrors typical identity semantics)
    bool operator==(const Member& other) const;
};

// Hash for Member so it can be used as a key in unordered_map
namespace std {
template<> struct hash<Member> {
    size_t operator()(const Member& m) const noexcept;
};
}
