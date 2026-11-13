public class Soldier extends BaseResident {
    private String weapon;

    public Soldier(String name, String weapon) {
        super(name);
        this.weapon = weapon;
        System.out.println("[Soldier] Воин " + name + " вооружен: " + weapon);
    }

    public Soldier(Soldier other) {
        super(other);
        this.weapon = new String(other.weapon);
    }

    @Override
    public String getProfession() { return "Воин"; }

    @Override
    public void work() {
        System.out.println(getName() + " тренируется с " + weapon + ".");
    }

    @Override
    public String describe() {
        return super.describe() + " | Профессия: " + getProfession() + ", Оружие: " + weapon;
    }
}