

class MovieRentingSystem {
public:
    typedef pair<int, int> P; // (price, shop)

    // movie -> set of {price, shop} for available movies
    unordered_map<int, set<P>> available;

    // movie -> {shop -> price} (for quick lookup of price)
    unordered_map<int, map<int, int>> movieToShopPrice;

    // rented movies -> {price, shop, movie}
    set<tuple<int, int, int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            available[movie].insert({price, shop});
            movieToShopPrice[movie][shop] = price;
        }
    }

    // Return up to 5 cheapest shops for a movie
    vector<int> search(int movie) {
        vector<int> result;
        if (available.count(movie)) {
            int count = 0;
            for (auto& [price, shop] : available[movie]) {
                result.push_back(shop);
                if (++count >= 5)
                    break;
            }
        }
        return result;
    }

    // Rent a movie from a shop
    void rent(int shop, int movie) {
        int price = movieToShopPrice[movie][shop];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    // Drop a rented movie back to available
    void drop(int shop, int movie) {
        int price = movieToShopPrice[movie][shop];
        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    // Report up to 5 rented movies sorted by (price, shop, movie)
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto& [price, shop, movie] : rented) {
            result.push_back({shop, movie});
            if (++count >= 5)
                break;
        }
        return result;
    }
};
