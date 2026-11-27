import java.util.Arrays;

public class Main {
    // Проверка типа на границе: "умеет ли житель платить налоги вообще".
    private static void tryCollectTax(Castle castle, BaseResident resident) {
        if (resident instanceof Taxable payer) {
            castle.collectTaxFrom(payer);
        } else {
            System.out.println(resident.getName() + " (" + resident.getProfession() + "): налоги не платит");
        }
    }

    public static void main(String[] args) {
        System.out.println("===== 1. АБСТРАКТНЫЙ КЛАСС И НАСЛЕДНИКИ =====");
        Soldier soldier = new Soldier("Иван", "Меч");
        Peasant peasant = new Peasant("Петр", 200, new StandardTax());
        Merchant merchant = new Merchant("Сидор", 500);

        System.out.println("\nПрофессии:");
        System.out.println(soldier.getName() + ": " + soldier.getProfession());
        System.out.println(peasant.getName() + ": " + peasant.getProfession());
        System.out.println(merchant.getName() + ": " + merchant.getProfession());
        System.out.println("\nСтатический счетчик жителей: " + BaseResident.getTotalResidents());

        System.out.println("\n===== 2. КОПИРОВАНИЕ (ГЛУБОКОЕ) =====");
        Soldier original = new Soldier("Клон", "Топор");
        Soldier copy = new Soldier(original);
        System.out.println("Оригинал: " + original.describe());
        System.out.println("Копия:    " + copy.describe());

        System.out.println("\n===== 3. ПОЛИМОРФИЗМ (ВЫЗОВ ЧЕРЕЗ БАЗУ) =====");
        BaseResident[] residents = { soldier, peasant, merchant };
        for (BaseResident r : residents) {
            r.work();
            System.out.println(r.describe());
        }

        System.out.println("\n===== 4. РАННЕЕ И ПОЗДНЕЕ СВЯЗЫВАНИЕ =====");
        BaseResident base = new Soldier("Борис", "Лук");
        // static-метод выбирается при компиляции по типу ссылки (BaseResident) -> раннее.
        System.out.println("getKind()  через BaseResident: " + BaseResident.getKind() + "  <- раннее связывание");
        // Обычный метод виртуален: выбирается по типу объекта (Soldier) -> позднее.
        System.out.println("describe() через BaseResident: " + base.describe() + "  <- позднее связывание");
        System.out.println("getKind()  через Soldier:      " + Soldier.getKind());

        System.out.println("\n===== 5. СТРОКИ =====");
        String report = "Жители: " + soldier.getName() + " и " + peasant.getName();
        System.out.println("Конкатенация: " + report);

        System.out.println("\n===== 6. ИНТЕРФЕЙС Taxable =====");
        Castle castle = new Castle("Каменный", 1000, "Главная казарма", 2);
        castle.collectTaxFrom(peasant);
        castle.collectTaxFrom(merchant);
        castle.printStatus();

        System.out.println("\n===== 7. INSTANCEOF =====");
        for (BaseResident r : residents) {
            tryCollectTax(castle, r);
        }

        System.out.println("\n===== 8. КОНФИГУРИРОВАНИЕ (ДИНАМИЧЕСКОЕ) =====");
        System.out.println("Налог крестьянина сейчас: " + peasant.calculateTax());
        peasant.setPolicy(new ReducedTax());
        System.out.println("Налог крестьянина после смены правила: " + peasant.calculateTax());

        System.out.println("\n===== 9. COMPARABLE =====");
        
        Soldier[] guards = {
            new Soldier("Яков", "Меч"),
            new Soldier("Артём", "Лук"),
            new Soldier("Борис", "Копьё")
        };
        System.out.println("Отсортированные воины по имени:");
        Arrays.sort(guards);
        for (Soldier s : guards) {
            
            System.out.println(s.getName());
        }

        System.out.println("\n===== 10. ИСКЛЮЧЕНИЯ =====");
        Soldier soldier2 = new Soldier("Алексей", "Лук");
        Soldier soldier3 = new Soldier("Дмитрий", "Копье");
        try {
            castle.getBarracks().recruit(soldier);
            castle.getBarracks().recruit(soldier2);
            castle.getBarracks().recruit(soldier3); // мест нет -> исключение
        } catch (BarracksFullException e) {
            System.out.println("Нарушение правила: " + e.getMessage() + " - "
                    + soldier3.getName() + " отправлен в резерв");
        } finally {
            System.out.println("[Журнал] попытка набора завершена"); // при любом исходе
        }

        try (RoyalLog log = new RoyalLog("Казна")) {
            castle.spendGold(300);
            log.write("потрачено 300");
            castle.spendGold(5000); // не хватает золота -> исключение
            log.write("эта строка не выполнится");
        } catch (InsufficientGoldException e) {
            System.out.println("Нарушение правила: " + e.getMessage() + " — найм отменён");
        }

        try {
            castle.getBarracks().recruit(null);
        } catch (IllegalArgumentException e) {
            System.out.println("Неверный аргумент: " + e.getMessage());
        }

        castle.getBarracks().reportStatus();
        castle.printStatus();

        System.out.println("\n===== КОНЕЦ ПРОГРАММЫ =====");
    }
}
