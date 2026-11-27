#pragma once
#include <string>

// Контракт: "житель платит налоги". Только чисто виртуальные методы, полей нет.
class ITaxable
{
public:
    virtual ~ITaxable() = default;

    virtual int CalculateTax() const = 0;
    virtual std::string GetTaxpayerName() const = 0;
};
