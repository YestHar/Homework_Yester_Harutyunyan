long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n+1,0);
    long max_val = 0;
    for (const auto& query : queries) {
        int a = query[0];
        int b = query[1];
        int k = query[2];
        arr[a - 1] += k;
        arr[b] -= k;
    
    }
    long sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        max_val = max(max_val, sum);
    }
    return max_val;
    
}