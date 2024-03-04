long repeatedString(std::string s, long n) {
    long sizeString = n / s.size();
    int k = n % s.size();
    long count = 0; 
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a'){
            count++;
        }
    }
    count = sizeString * count;
    for (int i = 0; i < k; i++) {
        if (s[i] == 'a'){
            count++;
        }
    }
        
    return count;
}