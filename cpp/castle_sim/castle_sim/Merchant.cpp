#include "Merchant.hpp"

Merchant::Merchant(const std::string& name, int income)
    : BaseResident(name), m_income(income)
{
    std::cout << "[Merchant] Торговец " << name << " открыл лавку (доход " << m_income << ").\n";
}

Merchant::~Merchant() noexcept { std::cout << "[Merchant] Торговец уничтожен\n"; }

std::string Merchant::GetProfession() const { return "Торговец"; }

void Merchant::Work() { std::cout << GetName() << " торгует на рынке.\n"; }

int Merchant::CalculateTax() const { return m_income * 15 / 100; }

std::string Merchant::GetTaxpayerName() const { return GetName(); }
