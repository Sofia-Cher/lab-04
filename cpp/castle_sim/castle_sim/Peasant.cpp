#include "Peasant.hpp"
#include <stdexcept>

Peasant::Peasant(const std::string& name, int income, std::unique_ptr<ITaxPolicy> policy)
    : BaseResident(name), m_income(income), m_policy(std::move(policy))
{
    if (!m_policy)
    {
        throw std::invalid_argument{ "у крестьянина должно быть правило налога" };
    }
    std::cout << "[Peasant] Крестьянин " << name << " готов к работе (доход " << m_income
        << ", " << m_policy->GetName() << ").\n";
}

Peasant::~Peasant() noexcept { std::cout << "[Peasant] Крестьянин уничтожен\n"; }

std::string Peasant::GetProfession() const { return "Крестьянин"; }

void Peasant::Work() { std::cout << GetName() << " пашет землю.\n"; }

int Peasant::CalculateTax() const { return m_policy->TaxFor(m_income); }

std::string Peasant::GetTaxpayerName() const { return GetName(); }

void Peasant::SetPolicy(std::unique_ptr<ITaxPolicy> policy)
{
    if (!policy)
    {
        throw std::invalid_argument{ "правило налога не может быть пустым" };
    }
    m_policy = std::move(policy);
    std::cout << "[Peasant] " << GetName() << ": новое правило — " << m_policy->GetName() << "\n";
}
