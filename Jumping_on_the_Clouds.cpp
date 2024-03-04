int jumpingOnClouds(vector<int> c) {
    int minJump = 0;
    for(int i = 0;i < c.size() - 1; i++) {
        if (c[i+2] == 0){
            minJump++;
            i++;
        } else {
            minJump++;
        }
        
    }
    
    return minJump;
}