import java.util.Scanner;

public class Main {
    public static <T> void printList(List<T> list){
        if (list.length() == 0){
            System.out.println("<>");
            return;
        }
        var realCur = list.currPos();
        var len = list.length();
        list.moveToStart();
        int printed = 0;
        System.out.print("<");
        while (printed < len){
            var now = list.getValue();
            if (printed == realCur) {
                System.out.print("|");
                System.out.print(" ");
            }
            System.out.print(now);
            printed++;
            if (printed < len) System.out.print(" ");
            list.next();
        }
        if (realCur == len) System.out.print("|");
        System.out.println(">");
        list.moveToPos(realCur);
    }

    public static void main(String[] args) {
        int ret = -1;
        Scanner scanner = new Scanner(System.in);
        int init_len = scanner.nextInt();
        int chunk_size = scanner.nextInt();

        Integer[] nums = new Integer[init_len];
        for (int i=0; i<init_len; i++) nums[i] = scanner.nextInt();
//        Arr<Integer> myList = new Arr<>(chunk_size, init_len, nums);
        LL<Integer> myList = new LL<>(init_len, nums);
        printList(myList);

        while (true){
            int Q, P;
            Q = scanner.nextInt();
            P = scanner.nextInt();
            if (Q == 0) break;

            switch(Q)
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
                    var that = myList.remove();
                    if (that == null) ret = -1;
                    else ret = that;
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
                    ret = myList.length();
                    break;
                case 10:
                    ret = myList.currPos();
                    break;
                case 11:
                    myList.moveToPos(P);
                    break;
                case 12:
                    var val = myList.getValue();
                    if (val == null) ret = -1;
                    else ret = val;
                    break;
                case 13:
                    ret = myList.Search(P);
                    break;
                default:
                    System.out.println("Please input a proper choice");
                    break;
            }
            printList(myList);
            System.out.println(ret);
            ret = -1;
        }
        scanner.close();
    }
}
