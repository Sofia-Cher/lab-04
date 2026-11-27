public class InsufficientGoldException extends RuntimeException {
    public InsufficientGoldException(int requested, int available) {
        super("недостаточно золота: нужно " + requested + ", есть " + available);
    }
}
