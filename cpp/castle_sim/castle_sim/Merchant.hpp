#pragma once
#include "BaseResident.hpp"
#include "ITaxable.hpp"

// Второй класс, реализующий ITaxable.
class Merchant : public BaseResident, public ITaxable
{
private:
    int m_income;

public:
    Merchant(const std::string& name, int income);
    ~Merchant() noexcept override;

    std::string GetProfession() const override;
    void Work() override;

    int CalculateTax() const override;
    std::string GetTaxpayerName() const override;
};
