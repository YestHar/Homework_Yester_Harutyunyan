int hourglassSum(vector<vector<int>> arr) {
    int sum = 0;
    vector<vector<int>> sum_arr;
    for(int i = 1; i < 5; i++){
        vector<int> v1; 
        for(int j = 1; j < 5; j++){
            sum = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] + arr[i][j] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
            v1.push_back(sum);
        }
        sum_arr.push_back(v1);
    }
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            if (sum_arr[i][j] > sum){
                sum = sum_arr[i][j];
            }
    }
    return sum;
}