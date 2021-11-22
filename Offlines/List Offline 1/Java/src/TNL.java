import java.util.Scanner;

public class TNL {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int rs, bs, ts;

        rs = scanner.nextInt();
        Integer[] rickshaw_stops = new Integer[rs];
        for (int i = 0; i < rs; i++) {
            rickshaw_stops[i] = i;
        }

        bs = scanner.nextInt();
        Integer[] bus_stops = new Integer[bs];
        for (int i = 0; i < bs; i++) {
            bus_stops[i] = scanner.nextInt();
        }

        ts = scanner.nextInt();
        Integer[] train_stops = new Integer[ts];
        for (int i = 0; i < ts; i++) {
            train_stops[i] = scanner.nextInt();
        }

//        Arr<Integer> Rickshaw = new Arr<>(rs, rs, rickshaw_stops);
        LL<Integer> Rickshaw = new LL<>(rs, rickshaw_stops);
//        Arr<Integer> Bus = new Arr<>(rs, bs, bus_stops);
        LL<Integer> Bus = new LL<>(bs, bus_stops);
//        Arr<Integer> Train = new Arr<>(rs, ts, train_stops);
        LL<Integer> Train = new LL<>(ts, train_stops);

        int task;
        task = scanner.nextInt();

        if (task == 1) {
            Rickshaw.moveToStart();
            int done = 0;
            while (done < rs) {
                var now = Rickshaw.getValue();
                if (done > 0) System.out.print(",");
                System.out.print(now);
                done++;
                Rickshaw.next();
            }
            System.out.println();

            Rickshaw.moveToStart();
            done = 0;
            while (done < rs) {
                var now = Rickshaw.getValue();
                var it = Bus.Search(now);
                if (done > 0) System.out.print(",");
                if (it != -1) System.out.print(now);
                done++;
                Rickshaw.next();
            }
            System.out.println();

            Rickshaw.moveToStart();
            done = 0;
            while (done < rs) {
                var now = Rickshaw.getValue();
                var it = Train.Search(now);
                if (done > 0) System.out.print(",");
                if (it != -1) System.out.print(now);
                done++;
                Rickshaw.next();
            }
            System.out.println();
        }

        scanner.close();
    }
}
