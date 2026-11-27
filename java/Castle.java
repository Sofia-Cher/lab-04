public class Castle {
    private final String name;
    private int gold;
    private final Barracks barracks;

    public Castle(String name, int gold, String barracksName, int capacity) {
        this.name = name;
        this.gold = gold;
        this.barracks = new Barracks(barracksName, capacity);
        System.out.println("[Castle] Основан замок: " + name + " (золото: " + gold + ")");
    }

    public void collectTaxes(int amount) {
        if (amount < 0) {
            throw new IllegalArgumentException("сумма налогов не может быть отрицательной");
        }
        gold += amount;
        System.out.println("[Castle] Собраны налоги: +" + amount + " (итого " + gold + ")");
    }

    // Работает через интерфейс и не знает конкретных классов плательщиков.
    public void collectTaxFrom(Taxable payer) {
        System.out.println("[Castle] Налог с " + payer.getTaxpayerName() + ": " + payer.calculateTax());
        collectTaxes(payer.calculateTax());
    }

    public void spendGold(int amount) {
        if (amount < 0) {
            throw new IllegalArgumentException("нельзя потратить отрицательную сумму");
        }
        if (amount > gold) {
            throw new InsufficientGoldException(amount, gold);
        }
        gold -= amount;
        System.out.println("[Castle] Потрачено золота: " + amount + " (осталось " + gold + ")");
    }

    public Barracks getBarracks() { return barracks; }

    public void printStatus() {
        System.out.println("Замок " + name + " | Золото: " + gold + " | Бойцов: " + barracks.getSoldierCount());
    }
}
