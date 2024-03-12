vector<int> rotLeft(vector<int> a, int d) {
    int vector_size = a.size();

    vector<int> rotated(vector_size); 
    
    for(int i = 0; i < vector_size; i++) {
        int new_index = (i + vector_size - d) % vector_size; 
        rotated[new_index] = a[i]; 
    }

    return rotated; 
}
