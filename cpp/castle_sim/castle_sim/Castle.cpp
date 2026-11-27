#include "castle.hpp"
#include <iostream>

Castle::Castle(const std::string& name, int gold, const std::string& barracksName, int barracksCapacity)
    : m_name(name), m_gold(gold), m_barracks(barracksName, barracksCapacity)
{
    std::cout << "[Castle] Основан замок: " << m_name << " (золото: " << m_gold << ")\n";
}

Castle::~Castle() { std::cout << "[Castle] Замок " << m_name << " пал...\n"; }

void Castle::CollectTaxes(int amount)
{
    if (amount < 0) return;
    m_gold += amount;
    std::cout << "[Castle] Собраны налоги: +" << amount << " (итого " << m_gold << ")\n";
}

bool Castle::SpendGold(int amount)
{
    if (amount < 0 || amount > m_gold) return false;
    m_gold -= amount;
    return true;
}

Barracks& Castle::GetBarracks() { return m_barracks; }

void Castle::PrintStatus() const
{
    std::cout << "Замок " << m_name << " | Золото: " << m_gold << " | Бойцов: " << m_barracks.GetSoldierCount() << "\n";
}