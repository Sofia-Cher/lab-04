#include "Castle.hpp"
#include "Soldier.hpp"
#include "Peasant.hpp"
#include "Merchant.hpp"
#include "TaxPolicies.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

namespace
{
    // Проверка типа на границе: "умеет ли житель платить налоги вообще".
    void TryCollectTax(Castle& castle, BaseResident& resident)
    {
        if (const auto* payer = dynamic_cast<const ITaxable*>(&resident))
        {
            castle.CollectTaxFrom(*payer);
        }
        else
        {
            std::cout << resident.GetName() << " (" << resident.GetProfession() << "): налоги не платит\n";
        }
    }
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    std::cout << "===== 1. АБСТРАКТНЫЙ КЛАСС И НАСЛЕДНИКИ =====\n";
    auto soldier = std::make_shared<Soldier>("Иван", "Меч");
    auto peasant = std::make_shared<Peasant>("Петр", 200, std::make_unique<StandardTax>());
    auto merchant = std::make_shared<Merchant>("Сидор", 500);

    std::cout << "\nПрофессии:\n";
    std::cout << soldier->GetName() << ": " << soldier->GetProfession() << "\n";
    std::cout << peasant->GetName() << ": " << peasant->GetProfession() << "\n";
    std::cout << merchant->GetName() << ": " << merchant->GetProfession() << "\n";
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
    std::vector<std::shared_ptr<BaseResident>> residents = { soldier, peasant, merchant };
    for (const auto& r : residents)
    {
        r->Work();
        std::cout << r->Describe() << "\n";
    }

    std::cout << "\n===== 5. РАННЕЕ И ПОЗДНЕЕ СВЯЗЫВАНИЕ =====\n";
    {
        std::unique_ptr<BaseResident> base = std::make_unique<Soldier>("Борис", "Лук");
        // GetKind — невиртуальный: выбран по ТИПУ УКАЗАТЕЛЯ (BaseResident) -> раннее.
        std::cout << "GetKind()  через BaseResident: " << base->GetKind() << "  <- раннее связывание\n";
        // Describe — виртуальный: выбран по ТИПУ ОБЪЕКТА (Soldier) -> позднее.
        std::cout << "Describe() через BaseResident: " << base->Describe() << "  <- позднее связывание\n";
        // Для сравнения: через указатель на настоящий тип выбирается версия Soldier.
        Soldier realSoldier("Глеб", "Булава");
        std::cout << "GetKind()  через Soldier:      " << realSoldier.GetKind() << "\n";
    }

    std::cout << "\n===== 6. ИНТЕРФЕЙС ITaxable =====\n";
    Castle castle("Каменный", 1000, "Главная казарма", 2);
    castle.CollectTaxFrom(*peasant);   // Peasant как ITaxable
    castle.CollectTaxFrom(*merchant);  // Merchant как ITaxable
    castle.PrintStatus();

    std::cout << "\n===== 7. DYNAMIC_CAST =====\n";
    for (const auto& r : residents)
    {
        TryCollectTax(castle, *r);
    }

    std::cout << "\n===== 8. КОНФИГУРИРОВАНИЕ (ДИНАМИЧЕСКОЕ) =====\n";
    std::cout << "Налог крестьянина сейчас: " << peasant->CalculateTax() << "\n";
    peasant->SetPolicy(std::make_unique<ReducedTax>());
    std::cout << "Налог крестьянина после смены правила: " << peasant->CalculateTax() << "\n";

    std::cout << "\n===== 9. ИСКЛЮЧЕНИЯ =====\n";
    auto soldier2 = std::make_shared<Soldier>("Алексей", "Лук");
    auto soldier3 = std::make_shared<Soldier>("Дмитрий", "Копье");
    try
    {
        castle.GetBarracks().Recruit(soldier);
        castle.GetBarracks().Recruit(soldier2);
        castle.GetBarracks().Recruit(soldier3); // мест нет -> исключение
    }
    catch (const BarracksFullException& error)
    {
        std::cout << "Нарушение правила: " << error.what() << " — " << soldier3->GetName()
            << " отправлен в резерв\n";
    }
    catch (const std::exception& error)
    {
        std::cout << "Ошибка: " << error.what() << "\n";
    }

    try
    {
        castle.SpendGold(300);   // успешно
        castle.SpendGold(5000);  // не хватает золота -> исключение
    }
    catch (const InsufficientGoldException& error)
    {
        std::cout << "Нарушение правила: " << error.what() << " — найм отменён\n";
    }
    catch (const std::exception& error)
    {
        std::cout << "Ошибка: " << error.what() << "\n";
    }

    try
    {
        castle.GetBarracks().Recruit(nullptr);
    }
    catch (const std::invalid_argument& error)
    {
        std::cout << "Неверный аргумент: " << error.what() << "\n";
    }

    castle.GetBarracks().ReportStatus();
    castle.PrintStatus();

    std::cout << "\n===== КОНЕЦ ПРОГРАММЫ =====\n";
    return 0;
}
