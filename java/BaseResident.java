public abstract class BaseResident {
    private static int totalResidents = 0;
    private final String name;
    private int health;
    protected int satiety;

    public BaseResident(String name) {
        this.name = name;
        this.health = 100;
        this.satiety = 100;
        totalResidents++;
        System.out.println("[BaseResident] Создан житель: " + name);
    }

    public BaseResident(BaseResident other) {
        this.name = other.name + "_copy";
        this.health = other.health;
        this.satiety = other.satiety;
        totalResidents++;
        System.out.println("[BaseResident] Создана КОПИЯ жителя: " + this.name);
    }

    public abstract String getProfession();
    public abstract void work();

    public String describe() {
        return "Житель " + name + " (Здоровье: " + health + ")";
    }

    public static int getTotalResidents() { return totalResidents; }

    public String getName() { return name; }
    public int getHealth() { return health; }
    public int getSatiety() { return satiety; }

    public void takeDamage(int damage) {
        if (damage < 0 || health <= 0) return;
        health -= damage;
        if (health < 0) health = 0;
    }
}