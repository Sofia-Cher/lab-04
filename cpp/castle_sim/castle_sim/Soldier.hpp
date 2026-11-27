#pragma once
#include "BaseResident.hpp"

class Soldier : public BaseResident
{
private:
    std::string m_weapon;

public:
    Soldier(const std::string& name, const std::string& weapon);
    ~Soldier() noexcept override;

    std::string GetProfession() const override;
    void Work() override;
    std::string Describe() const override;

    // Скрывает (а не переопределяет) BaseResident::GetKind.
    std::string GetKind() const { return "воин"; }
};
