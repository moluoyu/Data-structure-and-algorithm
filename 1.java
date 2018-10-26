import java.util.*;
public class Main1 {
    static int result = 0;
    public static void main(String[] args) 
    {  
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {//注意while处理多个case
            char[][] a = new char[10][10];
            String[] strs = new String[10];
            for(int i = 0; i < 10; i++) {
                strs[i] = in.nextLine();
                for(int j = 0; j < 10; j++) {
                    a[i][j] = strs[i].charAt(j);
                }
            }
            int m = Integer.parseInt(in.nextLine());
            int n = Integer.parseInt(in.nextLine());
             
            /*for(int i = 0; i < 10; i++) {  for(int j = 0; j < 10; j++) {  System.out.print(a[i][j]);  }  System.out.println();
            }
             
            System.out.println(m);
            System.out.println(n);*/
             
            int[][] book = new int[10][10];
            book[n][m] = 1;
            dfs(a, n, m, book);
            System.out.println(result);
        }  } 
      
    static void dfs(char[][] a, int x, int y, int[][] book) {
        if (x < 0 || x >= a.length || y < 0 || y >= a[0].length) {
            result = 1;
            return;
        }
        int[][] next = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        int xx, yy;
        for (int i = 0; i < 4; i++) {
            xx = x + next[i][0];
            yy = y + next[i][1];
            if (xx < 0 || xx >= a.length || yy < 0 || yy >= a[0].length) {
                result = 1;
                return;
            }
        }
        for (int i = 0; i < 4; i++) {
            xx = x + next[i][0];
            yy = y + next[i][1];
            if (xx < 0 || xx >= a.length || yy < 0 || yy >= a[0].length) {
                result = 1;
                return;
            }
            if (book[xx][yy] == 0 && a[xx][yy] == '0') {
                book[xx][yy] = 1;
                if (result != 1)
                    dfs(a, xx, yy, book);
                book[xx][yy] = 0;
            }
        }
        return;
    }
}




