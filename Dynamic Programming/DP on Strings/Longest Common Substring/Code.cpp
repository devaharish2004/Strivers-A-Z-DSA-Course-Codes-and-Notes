//recursive method - requires 3D DP to solve

int lcsHelper(string &str1, string &str2, int n, int m, int count){
    if (m == -1 || n == -1){
        return count;
    }
    if (str1[n] == str2[m]){
        count = lcsHelper(str1, str2, n - 1, m - 1, count + 1);
    }
    
    count = max({count, lcsHelper(str1, str2, n - 1, m, 0), lcsHelper(str1, str2, n, m - 1, 0)});
    return count;
}

int lcs(string &str1, string &str2){
    return lcsHelper(str1, str2, str1.length() - 1, str2.length() - 1, 0);
}