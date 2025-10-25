class Solution {
    public int totalMoney(int n) {
        int m = n / 7;
        int k = n % 7;
        int preWeeks = m * 28 + 7 * ((m - 1) * m / 2); 
        int lastWeek = k * (k + 1) / 2 + m * k;
        return preWeeks + lastWeek;
    }
}