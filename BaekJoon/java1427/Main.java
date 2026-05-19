package java1427;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.stream.Collectors; 

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // int[] arr = sc.nextLine().chars().map(c -> c - '0').sorted().toArray();
        String arr = sc.nextLine().chars()      // O(N)
                        .map(c -> c - '0')      // O(N)
                        .boxed()                // O(N)
                        .sorted(Comparator.reverseOrder())      // O(N log N)
                        .map(String::valueOf)    // O(N)
                        .collect(Collectors.joining());  // O(N)
        
        System.out.println(arr);
         
        sc.close();

    }
}
