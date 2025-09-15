class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // store broken letters in a set for fast lookup
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

        int count = 0; // number of words we can type
        bool valid = true;

        for (char ch : text) {
            if (ch == ' ') {
                if (valid)
                    count++;
                valid = true; // reset for next word
            } else if (broken.count(ch)) {
                valid = false; // this word contains broken letter
            }
        }

        // last word check (since no trailing space)
        if (valid)
            count++;

        return count;
    }
};
