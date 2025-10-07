func avoidFlood(rains []int) []int {
    totalDays := len(rains)
    full := make(map[int]int, totalDays)
    dryDays := make([]int,0,totalDays)
	result := make([]int, totalDays)
	
    for i, lake := range rains {	
        result[i] = 1 // puzzle's description demands this default value 	
        
        if isDryDay := lake==0; isDryDay {
			dryDays = append(dryDays, i)
            continue
		} 
        result[i] = -1

        if fullLake, found := full[lake]; found { // Danger! possible over-flooding for this lake
            i := sort.SearchInts(dryDays, fullLake)  // trickiest part of the puzzle
            noDryDaysAfterTheDayThisLakeWasFilled := i==len(dryDays) 
            if noDryDaysAfterTheDayThisLakeWasFilled { // rip...
                return []int{}
            }
            result[dryDays[i]] = lake
            dryDays = append(dryDays[:i], dryDays[i+1:]...) // deletes i-th element
        }
        full[lake] = i
	}
	return result
}