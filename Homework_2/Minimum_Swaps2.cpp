int minimumSwaps(vector<int> arr) {
    int count = 0;
    int arr_size = arr.size();
    int i = 0;
    while (i < arr_size) {
        if (arr[i] != i + 1) {
            swap(arr[i],arr[arr[i]-1]);
            count++;
            i--;
        }
        i++;
    }
    return count;

}