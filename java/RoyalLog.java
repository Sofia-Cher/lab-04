// Ресурс, который нужно закрыть при любом исходе (для try-with-resources).
public class RoyalLog implements AutoCloseable {
    private final String title;

    public RoyalLog(String title) {
        this.title = title;
        System.out.println("[Журнал] \"" + title + "\" открыт");
    }

    public void write(String message) {
        System.out.println("[Журнал] " + message);
    }

    @Override
    public void close() {
        System.out.println("[Журнал] \"" + title + "\" закрыт");
    }
}
