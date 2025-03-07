// https://leetcode.com/problems/closest-prime-numbers-in-range/
class Solution {
public:
    
    vector<int> closestPrimes(int left, int right) {
        int upperLimit = right;
        vector<int> sieveArray = sieve(upperLimit);
        vector<int> primeNumbers;

        for(int num = left; num <= right; num++) {
            if(sieveArray[num] == 1) {
                primeNumbers.push_back(num);
            }
        }

        if(primeNumbers.size() < 2) {
            return {-1, -1};
        }
        int minDiff = INT_MAX;

        vector<int> closePair(2, -1);

        for(int index = 1; index < primeNumbers.size(); index++) {
            int difference = primeNumbers[index] - primeNumbers[index-1];

            if(difference < minDiff) {
                minDiff = difference;
                closePair[0] = primeNumbers[index-1];
                closePair[1] = primeNumbers[index];
            }
        }

        return closePair;
    }

private:
    vector<int> sieve(int upperLimit) {
        vector<int> sieve(upperLimit + 1, 1);
        sieve[0] = 0;
        sieve[1] = 0;

        for(int num = 2; num*num <= upperLimit; num++) {
            if(sieve[num] == 1) {
                for(int multiple = num*num; multiple <= upperLimit; multiple+=num) {
                    sieve[multiple] = 0;
                }
            }
        }
        return sieve;
    }
};
