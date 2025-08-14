    for(int i=0;i<nums.length;i++){
        if(nums[i]==1){
            count +=1;
        }
        else{
            if(count>max){
                max=count;
                count=0;
            }               
        }
    }
    return max;       
}