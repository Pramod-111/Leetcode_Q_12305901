    while (empty >= numExchange) {
        ans++; // Drink one more bottle
        empty -= numExchange; // Use 'numExchange' empty bottles to get a new one
        empty++; // Add the new bottle's empty bottle to count
        numExchange++; // The next exchange requires one more empty bottle
    }
    return ans;
}