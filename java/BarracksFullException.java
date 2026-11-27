public class BarracksFullException extends RuntimeException {
    public BarracksFullException(String barracksName, int capacity) {
        super("казарма " + barracksName + " переполнена (вместимость " + capacity + ")");
    }
}
