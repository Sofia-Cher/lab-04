public class Castle {
    private final String name;
    private final Barracks barracks;

    public Castle(String name, int gold, String barracksName, int capacity) {
        this.name = name;
        this.barracks = new Barracks(barracksName, capacity);
        System.out.println("[Castle] Основан замок: " + name);
    }

    public Barracks getBarracks() { return barracks; }
}