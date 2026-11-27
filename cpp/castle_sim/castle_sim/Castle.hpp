#pragma once
#include "Barracks.hpp"
#include "ITaxable.hpp"
#include <string>

class Castle
{
private:
    std::string m_name;
    int m_gold;
    Barracks m_barracks;

public:
    Castle(const std::string& name, int gold, const std::string& barracksName, int barracksCapacity);
    ~Castle() noexcept;

    void CollectTaxes(int amount);
    // Работает через интерфейс и не знает конкретных классов плательщиков.
    void CollectTaxFrom(const ITaxable& payer);
    // Бросает InsufficientGoldException, если золота не хватает.
    void SpendGold(int amount);
    Barracks& GetBarracks();
    void PrintStatus() const;
};
