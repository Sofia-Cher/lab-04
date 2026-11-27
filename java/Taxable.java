// Контракт: "платит налоги". Только методы без реализации, состояния нет.
public interface Taxable {
    int calculateTax();
    String getTaxpayerName();
}
