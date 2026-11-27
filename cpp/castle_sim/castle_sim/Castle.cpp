#include "Castle.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <stdexcept>

Castle::Castle(const std::string& name, int gold, const std::string& barracksName, int barracksCapacity)
    : m_name(name), m_gold(gold), m_barracks(barracksName, barracksCapacity)
{
    std::cout << "[Castle] Основан замок: " << m_name << " (золото: " << m_gold << ")\n";
}

Castle::~Castle() noexcept { std::cout << "[Castle] Замок " << m_name << " пал...\n"; }

void Castle::CollectTaxes(int amount)
{
    if (amount < 0)
    {
        throw std::invalid_argument{ "сумма налогов не может быть отрицательной" };
    }
    m_gold += amount;
    std::cout << "[Castle] Собраны налоги: +" << amount << " (итого " << m_gold << ")\n";
}

void Castle::CollectTaxFrom(const ITaxable& payer)
{
    std::cout << "[Castle] Налог с " << payer.GetTaxpayerName() << ": " << payer.CalculateTax() << "\n";
    CollectTaxes(payer.CalculateTax());
}

void Castle::SpendGold(int amount)
{
    if (amount < 0)
    {
        throw std::invalid_argument{ "нельзя потратить отрицательную сумму" };
    }
    if (amount > m_gold)
    {
        throw InsufficientGoldException{ amount, m_gold };
    }
    m_gold -= amount;
    std::cout << "[Castle] Потрачено золота: " << amount << " (осталось " << m_gold << ")\n";
}

Barracks& Castle::GetBarracks() { return m_barracks; }

void Castle::PrintStatus() const
{
    std::cout << "Замок " << m_name << " | Золото: " << m_gold << " | Бойцов: " << m_barracks.GetSoldierCount() << "\n";
}
