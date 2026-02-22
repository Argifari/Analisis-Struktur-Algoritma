// Muhammad Firdaus Argifari
// 24060124130107

import java.util.Scanner;

public class main {

    public static void main(String[] args) {
        String kode;
        char pattern = 'A';

        Scanner scanner = new Scanner(System.in);
        kode = scanner.nextLine();

        for (int i = 0; i < kode.length(); i++) {
            if (kode.charAt(i) != pattern) {
                System.out.printf("%d ",i + 1);
            }
        }

        scanner.close();

    }
}