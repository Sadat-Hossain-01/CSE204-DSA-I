import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int init_len = scanner.nextInt();
        int chunk_size = scanner.nextInt();

        Integer[] nums = new Integer[init_len];
        for (int i=0; i<init_len; i++) nums[i] = scanner.nextInt();
        for (var i : nums) System.out.println(i);
        AList<Integer> myList = new AList<>(chunk_size, init_len, nums);

        while (true){
            int Q, P;
            Q = scanner.nextInt();
            P = scanner.nextInt();
            if (Q == 0) break;
            switch (Q)
            {
                case 1:
                    myList.clear();
                    break;
                case 2:
                    myList.insert(P);
                    break;
                case 3:
                    myList.append(P);
                    break;
                case 4:
                    myList.remove();
                    break;
                case 5:
                    myList.moveToStart();
                    break;
                case 6:
                    myList.moveToEnd();
                    break;
                case 7:
                    myList.prev();
                    break;
                case 8:
                    myList.next();
                    break;
                case 9:
                    myList.length();
                    break;
                case 10:
                    myList.currPos();
                    break;
                case 11:
                    myList.moveToPos(P);
                    break;
                case 12:
                    myList.getValue();
                    break;
                case 13:
                    myList.Search(P);
                    break;
                default:
                    System.out.println("Please input a proper choice");
                    break;
            }
        }
        scanner.close();
    }
}
