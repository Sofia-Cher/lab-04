#pragma once
#include "ITaxPolicy.hpp"
#include <algorithm>

// Обычный налог: 20% от дохода.
class StandardTax : public ITaxPolicy
{
private:
    static constexpr int PERCENT{ 20 };

public:
    int TaxFor(int income) const override
    {
        return income * PERCENT / 100;
    }

    std::string GetName() const override
    {
        return "обычный налог (20%)";
    }
};

// Льготный налог: 5% от дохода, но не больше 30 золотых.
class ReducedTax : public ITaxPolicy
{
private:
    static constexpr int PERCENT{ 5 };
    static constexpr int MAX_TAX{ 30 };

public:
    int TaxFor(int income) const override
    {
        return std::min(income * PERCENT / 100, MAX_TAX);
    }

    std::string GetName() const override
    {
        return "льготный налог (5%, максимум 30)";
    }
};
