public final class Peasant extends BaseResident {
    public Peasant(String name) {
        super(name);
        System.out.println("[Peasant] Крестьянин " + name + " готов к работе.");
    }

    @Override
    public String getProfession() { return "Крестьянин"; }

    @Override
    public void work() {
        System.out.println(getName() + " пашет землю.");
    }
}