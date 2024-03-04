int sockMerchant(int n, vector<int> ar) {
    int quantity = 0;
    int j = 0;
    for (int i = 1; i< n; i++){
        if (ar[j] == -1){
            j++;
        }
        if ((i == n-1 && ar[j] != ar[i])){
            j++;
            i = j + 1;
        }
        
        if(ar[j] == ar[i] && i != j){
            ar[i] = -1;
            ar[j] = -1;
            i = j + 1;
            j++; 
        }
    }

    for (int i=0;i<n;i++){
        if(ar[i] == -1){
            quantity++;
        }
    }
    return quantity/2;    
}
