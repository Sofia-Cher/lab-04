#include "castle.hpp"
#include "Soldier.hpp"
#include "Peasant.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "===== 1. АБСТРАКТНЫЙ КЛАСС И НАСЛЕДНИКИ =====\n";
    auto soldier = std::make_shared<Soldier>("Иван", "Меч");
    auto peasant = std::make_shared<Peasant>("Петр");

    std::cout << "\nПрофессии:\n";
    std::cout << soldier->GetName() << ": " << soldier->GetProfession() << "\n";
    std::cout << peasant->GetName() << ": " << peasant->GetProfession() << "\n";
    std::cout << "\nСтатический счетчик жителей: " << BaseResident::GetTotalResidents() << "\n";

    std::cout << "\n===== 2. ВИРТУАЛЬНЫЙ ДЕСТРУКТОР =====\n";
    {
        std::unique_ptr<BaseResident> ptr = std::make_unique<Soldier>("Генерал", "Копье");
    }

    std::cout << "\n===== 3. КОПИРОВАНИЕ (ГЛУБОКОЕ) =====\n";
    {
        Soldier original("Клон", "Топор");
        Soldier copy = original;
        std::cout << "Оригинал: " << original.Describe() << "\n";
        std::cout << "Копия:    " << copy.Describe() << "\n";
    }

    std::cout << "\n===== 4. ПОЛИМОРФИЗМ (ВЫЗОВ ЧЕРЕЗ БАЗУ) =====\n";
    std::vector<std::shared_ptr<BaseResident>> residents = { soldier, peasant };
    for (const auto& r : residents)
    {
        r->Work();
        std::cout << r->Describe() << "\n";
    }

    std::cout << "\n===== 5. СТРОКИ =====\n";
    std::string report = "Жители: " + soldier->GetName() + " и " + peasant->GetName();
    std::cout << "Конкатенация: " << report << "\n";

    std::cout << "\n===== 6. ИСПОЛЬЗОВАНИЕ КАЗАРМЫ =====\n";
    Castle castle("Каменный", 1000, "Главная казарма", 2);
    castle.GetBarracks().Recruit(soldier);
    castle.GetBarracks().Recruit(peasant);
    castle.GetBarracks().ReportStatus();

    std::cout << "\n===== КОНЕЦ ПРОГРАММЫ =====\n";
    return 0;
}