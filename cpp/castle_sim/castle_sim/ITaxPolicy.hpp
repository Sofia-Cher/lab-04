#pragma once
#include <string>

// Интерфейс объекта поведения: как считать налог.
class ITaxPolicy
{
public:
    virtual ~ITaxPolicy() = default;

    virtual int TaxFor(int income) const = 0;
    virtual std::string GetName() const = 0;
};
