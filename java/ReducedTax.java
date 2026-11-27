public class ReducedTax implements TaxPolicy {
    private static final int PERCENT = 5;
    private static final int MAX_TAX = 30;

    @Override
    public int taxFor(int income) { return Math.min(income * PERCENT / 100, MAX_TAX); }

    @Override
    public String getName() { return "льготный налог (5%, максимум 30)"; }
}
