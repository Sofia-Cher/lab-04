public class Merchant extends BaseResident implements Taxable {
    private final int income;

    public Merchant(String name, int income) {
        super(name);
        this.income = income;
        System.out.println("[Merchant] Торговец " + name + " открыл лавку (доход " + income + ").");
    }

    @Override
    public String getProfession() { return "Торговец"; }

    @Override
    public void work() {
        System.out.println(getName() + " торгует на рынке.");
    }

    @Override
    public int calculateTax() { return income * 15 / 100; }

    @Override
    public String getTaxpayerName() { return getName(); }
}
