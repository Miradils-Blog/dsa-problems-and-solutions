import java.util.*;

class Edge {

    int x, y, danger;

    Edge (int x, int y, int danger) {

        this.x = x;
        this.y = y;
        this.danger = danger;
    }
};

 

public class Main {

    static int parent[], size[];

    static int repr(int node) {

        if (node == parent[node]) return node;

        return parent[node] = repr(parent[node]);

    }

    static boolean unite(int x, int y) {

        x = repr(x); 
        y = repr(y);

        if(x == y) return false;

        if (size[x] < size[y]) {
            int temp = x; x = y; y = temp;
        }

        parent[y] = x;
        size[x] += size[y];

        return true;
    }

    public static class Comp implements Comparator<Edge> {

        public int compare(Edge a, Edge b) {
            return a.danger - b.danger;
        }

    }

    public static void main(String[] args) {
        Scanner con = new Scanner(System.in);

        int n = con.nextInt();
        int m = con.nextInt();

        parent = new int[n + 1];
        size = new int[n + 1];

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        Vector<Edge> v = new Vector<Edge>();

        for(int i = 0; i < m; i++) {
            int x = con.nextInt();
            int y = con.nextInt();
            int danger = con.nextInt();
            v.add(new Edge(x, y, danger));
        }

        Collections.sort(v, new Comp());
        int index = 0;

        for(int i = 0; i < m; i++) {

            unite(v.get(i).x, v.get(i).y);

            if (repr(1) == repr(n)) {
                index = i;
                break;
            }
        }

        System.out.println(v.get(index).danger);
        con.close();

    }
}  

