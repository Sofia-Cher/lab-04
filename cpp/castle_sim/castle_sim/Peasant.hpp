#pragma once
#pragma once
#include "BaseResident.hpp"

class Peasant final : public BaseResident
{
public:
    Peasant(const std::string& name);
    ~Peasant() override;

    std::string GetProfession() const override;
    void Work() override;
};