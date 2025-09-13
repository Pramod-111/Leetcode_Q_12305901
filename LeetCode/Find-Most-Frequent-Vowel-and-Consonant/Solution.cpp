class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};
        int maxVowel = 0, maxConsonant = 0;

        for (char ch : s) {
            int idx = ch - 'a';
            int newCount = ++freq[idx];

            // Check vowel vs consonant
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                maxVowel = max(maxVowel, newCount);
            } else {
                maxConsonant = max(maxConsonant, newCount);
            }
        }

        return maxVowel + maxConsonant;
    }
};