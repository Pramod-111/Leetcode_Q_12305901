 for(var i =0;i<nums.length;i++){
    var item = nums[i];   
    for(var j=0; j < nums.length;j++){
        var item2 = nums[j];
        var sum = item + item2;
        
    if(sum === target ){
      return [i,j];
      
    }
  }
 }