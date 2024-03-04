int countingValleys(int steps, string path) {
 int valleys = 0;
    int roudway = 0;
    for (int i = 0;i < steps; i++){
        if (path[i] == 'U'){
            roudway++;
        
            if(roudway == 0){
                valleys++;
            }
        } else if(path[i] == 'D'){
            roudway--;
   
        }  
    }
    return valleys;
}