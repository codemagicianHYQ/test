// 文件名：PowerCheck.java
public class PowerCheck {

    // 检查 base 的 power 次幂是否等于 number
    public static boolean isPowerOf(int number, int base) {
        if (base <= 1) {
            return number == 1;
        }
        int power = 1;
        while (power < number) {
            power *= base;
        }
        return power == number;
    }

    public static void main(String[] args) {
        int number = 8;
        int base = 2;
        if (isPowerOf(number, base)) {
            System.out.println(number + " 是 " + base + " 的幂。");
        } else {
            System.out.println(number + " 不是 " + base + " 的幂。");
        }
    }
}
