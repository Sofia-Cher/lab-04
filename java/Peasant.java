public final class Peasant extends BaseResident implements Taxable {
    private final int income;
    private TaxPolicy policy; // объект поведения

    public Peasant(String name, int income, TaxPolicy policy) {
        super(name);
        if (policy == null) {
            throw new IllegalArgumentException("у крестьянина должно быть правило налога");
        }
        this.income = income;
        this.policy = policy;
        System.out.println("[Peasant] Крестьянин " + name + " готов к работе (доход " + income
                + ", " + policy.getName() + ").");
    }

    @Override
    public String getProfession() { return "Крестьянин"; }

    @Override
    public void work() {
        System.out.println(getName() + " пашет землю.");
    }

    @Override
    public int calculateTax() { return policy.taxFor(income); }

    @Override
    public String getTaxpayerName() { return getName(); }

    // Динамическое конфигурирование: правило меняется во время работы.
    public void setPolicy(TaxPolicy policy) {
        if (policy == null) {
            throw new IllegalArgumentException("правило налога не может быть пустым");
        }
        this.policy = policy;
        System.out.println("[Peasant] " + getName() + ": новое правило - " + policy.getName());
    }

    public static String getKind() { return "крестьянин"; }
}
