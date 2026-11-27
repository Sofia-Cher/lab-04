// Интерфейс объекта поведения: как считать налог.
public interface TaxPolicy {
    int taxFor(int income);
    String getName();
}
