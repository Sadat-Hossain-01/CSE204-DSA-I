import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int init_len = scanner.nextInt();
        int chunk_size = scanner.nextInt();

        Integer[] nums = new Integer[init_len];
        for (int i=0; i<init_len; i++) nums[i] = scanner.nextInt();
//        Arr<Integer> myList = new Arr<>(chunk_size, init_len, nums);
        LL<Integer> myList = new LL<>(init_len, nums);

        while (true){
            int Q, P;
            Q = scanner.nextInt();
            P = scanner.nextInt();
            if (Q == 0) break;
            switch (Q) {
                case 1 -> myList.clear();
                case 2 -> myList.insert(P);
                case 3 -> myList.append(P);
                case 4 -> myList.remove();
                case 5 -> myList.moveToStart();
                case 6 -> myList.moveToEnd();
                case 7 -> myList.prev();
                case 8 -> myList.next();
                case 9 -> myList.length();
                case 10 -> myList.currPos();
                case 11 -> myList.moveToPos(P);
                case 12 -> myList.getValue();
                case 13 -> myList.Search(P);
                default -> System.out.println("Please input a proper choice");
            }
        }
        scanner.close();
    }
}
