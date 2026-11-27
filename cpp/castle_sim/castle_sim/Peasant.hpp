#pragma once
#include "BaseResident.hpp"
#include "ITaxable.hpp"
#include "ITaxPolicy.hpp"
#include <memory>

class Peasant final : public BaseResident, public ITaxable
{
private:
    int m_income;
    std::unique_ptr<ITaxPolicy> m_policy;

public:
    Peasant(const std::string& name, int income, std::unique_ptr<ITaxPolicy> policy);
    ~Peasant() noexcept override;

    std::string GetProfession() const override;
    void Work() override;

    int CalculateTax() const override;
    std::string GetTaxpayerName() const override;

    void SetPolicy(std::unique_ptr<ITaxPolicy> policy);

    std::string GetKind() const { return "крестьянин"; }
};