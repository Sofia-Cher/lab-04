#pragma once
#pragma once

#include <string>
#include <iostream>

class BaseResident
{
private:
    std::string m_name;
    int m_health;
    static int m_totalResidents;

protected:
    int m_satiety;

public:
    BaseResident(const std::string& name);
    BaseResident(const BaseResident& other);
    virtual ~BaseResident();

    virtual std::string GetProfession() const = 0;
    virtual void Work() = 0;

    virtual std::string Describe() const;
    static int GetTotalResidents();

    std::string GetName() const { return m_name; }
    int GetHealth() const { return m_health; }
    int GetSatiety() const { return m_satiety; }

    void TakeDamage(int damage);
    void Eat(int food);
    bool ConsumeFood(int foodPerTurn);
};