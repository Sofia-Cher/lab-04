public class StandardTax implements TaxPolicy {
    private static final int PERCENT = 20;

    @Override
    public int taxFor(int income) { return income * PERCENT / 100; }

    @Override
    public String getName() { return "обычный налог (20%)"; }
}
