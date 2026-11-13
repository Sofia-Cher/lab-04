import java.util.ArrayList;
import java.util.List;

public class Barracks {
    private final String name;
    private final int capacity;
    private final List<BaseResident> soldiers;

    public Barracks(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
        this.soldiers = new ArrayList<>();
        System.out.println("[Barracks] Построена казарма: " + name + " (вместимость " + capacity + ")");
    }

    public boolean recruit(BaseResident resident) {
        if (resident == null) return false;
        if (soldiers.size() >= capacity) {
            System.out.println("[Barracks] Отказ: казарма переполнена");
            return false;
        }
        soldiers.add(resident);
        System.out.println("[Barracks] " + resident.getName() + " зачислен в " + name);
        return true;
    }

    public void reportStatus() {
        System.out.println("=== Казарма " + name + " (" + soldiers.size() + "/" + capacity + ") ===");
        for (BaseResident r : soldiers) {
            System.out.println(r.describe());
        }
    }

    public int getSoldierCount() { return soldiers.size(); }
}