class Derp {
    public int x;
    public Derp(int x) {
        this.x = x;
    }
    public String toString() {
        return new String("x=" + x);
    }
}
public class sometn {
    public static void func(Derp d) {
        d = new Derp(222);
    }
    
    public static void main(String args[]) {
        Derp d1 = new Derp(10);
        func(d1);
        System.out.println(d1);
    }
}