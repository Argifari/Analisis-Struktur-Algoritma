package Pertemuan1.bantuPakJoko;

// Muhammad Firdaus Argifari 
// 24060124130107

import java.util.Scanner;

public class main {
    
    public static void main (String args[]) {
        Scanner scanner = new Scanner(System.in);
        String kode;
        kode = scanner.nextLine();
        scanner.close();
        int maksimalChar = 0;
        int cekMaks = 0;
        char pattern = ' ';
        
        boolean[] isVisited = new boolean[kode.length()];
        
        for (int i = 0; i < kode.length(); i++) {
            isVisited[i] = false;
        }

        for (int i = 0; i < kode.length(); i++) {
            cekMaks = 0;
            if (isVisited[i]) {
                continue;
            }
            for (int j = i + 1; j < kode.length();j++){
                if (kode.charAt(i) == kode.charAt(j)) {
                    cekMaks++;
                    isVisited[j] = true;
                }
            }
            if (maksimalChar < cekMaks){
                maksimalChar = cekMaks;
                pattern = kode.charAt(i);
            }
    }
    if (maksimalChar+1 == kode.length()) {
        System.out.print("-1");
    }else {
        for (int i = 0; i < kode.length();i++){
            if (pattern != kode.charAt(i)) {
                    System.out.print(i + 1+ " ");
                }

            }
        }
    
    
    }
}