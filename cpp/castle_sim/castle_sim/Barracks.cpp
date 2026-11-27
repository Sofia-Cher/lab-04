#include "Barracks.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <stdexcept>

Barracks::Barracks(const std::string& name, int capacity)
    : m_name(name), m_capacity(capacity)
{
    std::cout << "[Barracks] Построена казарма: " << m_name << " (вместимость " << m_capacity << ")\n";
}

Barracks::~Barracks() noexcept { std::cout << "[Barracks] Казарма " << m_name << " разрушена\n"; }

void Barracks::Recruit(const std::shared_ptr<BaseResident>& resident)
{
    // Все проверки — до изменения состояния (строгая гарантия безопасности).
    if (!resident)
    {
        throw std::invalid_argument{ "нельзя зачислить пустого жителя" };
    }
    if (static_cast<int>(m_soldiers.size()) >= m_capacity)
    {
        throw BarracksFullException{ m_name, m_capacity };
    }
    m_soldiers.push_back(resident);
    std::cout << "[Barracks] " << resident->GetName() << " зачислен в " << m_name << "\n";
}

void Barracks::ReportStatus() const
{
    std::cout << "=== Казарма " << m_name << " (" << m_soldiers.size() << "/" << m_capacity << ") ===\n";
    for (const auto& weakSoldier : m_soldiers)
    {
        if (auto soldier = weakSoldier.lock()) std::cout << soldier->Describe() << "\n";
        else std::cout << "  (Житель покинул казарму или погиб)\n";
    }
}

int Barracks::GetSoldierCount() const { return static_cast<int>(m_soldiers.size()); }
const std::string& Barracks::GetName() const { return m_name; }
