public class LongestPalindromicSubstrings {
    //time:O(n^2)
    //space:O(n^2)


    
    public String LongestPalindrome(String s) {
        if(null == s || s.length()== 0)
            return s;
        boolean[][] dp = new boolean[s.length()][s.length()];
        int max = 0;
        for (int j = 0; j < s.length(); j++) {
            for (int i = 0; i <= j; i++) {
                


                







            }
        }

        String res = "";


        return res;
    
    }
}
